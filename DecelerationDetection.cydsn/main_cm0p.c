/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"
#include <math.h>

#define UNIT_CONVERSION_DIGIT_MG 16
#define THOUSANDS 1000
#define GRAVITY 9.8
#define Rad_to_deg  57.2957951 // 180/pi
#define CarSlowing 1
#define CarNotSlowing 0
#define readMax 6  // #of counts to be measured 

int flag = 0;
int Detected = 0;
 
int readings_x[readMax], readings_y[readMax], readings_z[readMax]; // Array for measured x values
int readIndex = 0; // the location of measured valued to be stored; reading[readIndex]

double ac_x, ac_y, ac_z = 0;
double total_x,total_y,total_z = 0;  // Sum of measured values

double avg_x,avg_y,avg_z = 0; // Avg of measured current values
double prev_avg_x,prev_avg_y,prev_avg_z = 0; // Avg of stored previous values

static cy_stc_scb_i2c_master_xfer_config_t register_setting;

static uint8 rbuff[2];
static uint8 wbuff[2];

static void WaitForOperation()
{
    while(0 != (SensorBus_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY)) {}
    {
        CyDelayUs(1);
    }
}

static void WriteRegister(uint8 reg_addr, uint8 data)
{
    wbuff[0] = reg_addr;
    wbuff[1] = data;
    
    register_setting.buffer = wbuff;
    register_setting.bufferSize = 2;
    register_setting.xferPending = false;
    
    SensorBus_MasterWrite(&register_setting);
    WaitForOperation();    
}

static uint8 ReadRegister(uint8 reg_addr)
{
    wbuff[0] = reg_addr;
    
    register_setting.buffer = wbuff;
    register_setting.bufferSize = 1;
    register_setting.xferPending = true;
    
    SensorBus_MasterWrite(&register_setting);
    WaitForOperation();
    
    register_setting.buffer = rbuff;
    register_setting.xferPending = false;
    
    SensorBus_MasterRead(&register_setting);
    WaitForOperation();
    
    return rbuff[0];
}

double xaccel_calculate() {
// Data read
    uint8 x = ReadRegister(0x29);
// Data SHIFT
    if (x > 127) ac_x = x - 256;
    else ac_x = x;
// Unit Conversion
    ac_x = (ac_x * UNIT_CONVERSION_DIGIT_MG)/THOUSANDS * GRAVITY;
        
    return ac_x;
} 

double yaccel_calculate() {
// Data read
    uint8 y = ReadRegister(0x2B);
// Data SHIFT
    if (y > 127) ac_y = y - 256;
    else ac_y = y;
// Unit Conversion
    ac_y = (ac_y * UNIT_CONVERSION_DIGIT_MG)/THOUSANDS * GRAVITY;
        
    return ac_y;
} 

double zaccel_calculate() {
// Data read
    uint8 z = ReadRegister(0x2D);
// Data SHIFT
    if (z > 127) ac_z = z - 256;
    else ac_z = z;
// Unit Conversion
    ac_z = (ac_z * UNIT_CONVERSION_DIGIT_MG)/THOUSANDS * GRAVITY;
        
    return ac_z;
} 

void setup(){
    for (int i = 0; i < readMax; i++) {
        readings_x[i] = xaccel_calculate(); 
        total_x = total_x+readings_x[i];
    } 
    for (int j = 0; j < readMax; j++) {
        readings_y[j] = yaccel_calculate(); 
        total_y = total_y+readings_y[j];
    } 
    for (int k = 0; k < readMax; k++) {
        readings_z[k] = zaccel_calculate(); 
        total_z = total_z+readings_z[k];
    } 
}

bool CheckDetection(){
    flag = Detected?1:0;
    return flag;
}
/*
int compareDats(){
    if(prev_avg_x > avg_x) return CarSlowing;
    else return CarNotSlowing;
}
*/

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    // Start UART
    UART_Start();
    setvbuf(stdin,NULL,_IONBF,0);
    
    // Set up I2C for LIS3DH
    SensorBus_Start();
    register_setting.slaveAddress = 0x19;
    
    /* Set up LIS3DH registers */
    uint8_t temp_reg = 0x1F;
    uint8_t xyz_reg = 0x20;
    uint8_t adc_reg = 0x23;
    uint8_t CTRL5_reg = 0x24;
    uint8_t fifoCTRL_reg = 0x2E;
    WriteRegister(temp_reg, (ReadRegister(temp_reg) | 0b11000000)); // enable ADC
    WriteRegister(xyz_reg, (ReadRegister(xyz_reg) | 0b01000111)); // enable xyz axis
    WriteRegister(adc_reg, (ReadRegister(adc_reg) | 0b10000000)); // full-scale: +-2g
    WriteRegister(CTRL5_reg, (ReadRegister(CTRL5_reg) | 0b01000000)); // enable FIFO
    WriteRegister(fifoCTRL_reg, (ReadRegister(fifoCTRL_reg) | 0b10000000)); // FIFO:stream mode
   
    setup();
    for(;;){
// Smoothing Filter
    total_x = total_x - readings_x[readIndex];  
    total_y = total_y - readings_y[readIndex];  
    total_z = total_z - readings_z[readIndex];
    
    readings_x[readIndex] = xaccel_calculate(); 
    readings_y[readIndex] = yaccel_calculate(); 
    readings_z[readIndex] = zaccel_calculate();
    
    total_x = total_x + readings_x[readIndex];  
    total_y = total_y + readings_y[readIndex];  
    total_z = total_z + readings_z[readIndex]; 
    
    readIndex = readIndex + 1;
   
    if (readIndex >= readMax) {  
    readIndex = 0;
    }  
    prev_avg_x = avg_x;
    prev_avg_y = avg_y;
    prev_avg_z = avg_z;
    
    printf("prev_ac_x : %f\n\r",prev_avg_x);
    printf("prev_ac_y : %f\n\r",prev_avg_y);
    printf("prev_ac_z : %f\n\r",prev_avg_z);
    
    CyDelay(100);
    
    avg_x = total_x / readMax;
    avg_y = total_y / readMax;
    avg_z = total_z / readMax;
    
    printf("ac_x : %f\n\r",avg_x);
    printf("ac_y : %f\n\r",avg_y);
    printf("ac_z : %f\n\r",avg_z);

    CheckDetection();
    if(1){ // If Object Is Detected
        if(avg_x > prev_avg_x){
        printf("WARNING : Car Not Slowing Down\n\r");
        }
    }
 }        
}

/* [] END OF FILE */
