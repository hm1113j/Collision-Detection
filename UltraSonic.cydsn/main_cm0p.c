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

#define k 1.403 // Specific heat ratio (Air)
#define M 0.028966 // Molecular Weight (kg/mol)
#define R 8.314462 // Gas Constant

uint16_t duration = 0;
bool echo_flag = 0;
double SoundSpeed = 0.0;
char str[20]; /* print buffer */

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

void Timer_Int_Handler(){
    NVIC_ClearPendingIRQ(Timer_Echo_Int_cfg.intrSrc);
    NVIC_DisableIRQ((IRQn_Type)Timer_Echo_Int_cfg.intrSrc);

    duration = Timer_Echo_GetCapture(); // read in cm

    Timer_Echo_SetCounter(0);

    PWM_Trigger_Disable();

    echo_flag = 1;
}

void get_speed(){
    uint8 Temp = ReadRegister(0x0D) + 25 - ((ReadRegister(0x0C))>>6);
    SoundSpeed = (sqrt((k*R*(Temp+273.15)))/sqrt(M));  
    printf("Temp = %d\n\r", Temp); 
    printf("Sound Speed = %f\n\r", SoundSpeed);
}

void get_distance(uint32_t duration){
    double distance = 0.0;
    distance = (double)(duration) * SoundSpeed / 240000.0;
    sprintf(str, "Distance = %.2f \n\r", distance);
    UART_PutString(str);
}

int main(void){
    __enable_irq(); /* Enable global interrupts. */
    UART_Start();
    Timer_Echo_Start();
    PWM_Trigger_Start();
    
    Cy_SysInt_Init(&Timer_Echo_Int_cfg, Timer_Int_Handler) ;
    NVIC_EnableIRQ((IRQn_Type)Timer_Echo_Int_cfg.intrSrc) ;
  
    setvbuf(stdin,NULL,_IONBF,0);
    
    // Set up I2C for LIS3DH
    SensorBus_Start();
    register_setting.slaveAddress = 0x19;
    
    /* Set up LIS3DH registers */
    uint8_t temp_reg = 0x1F;
    uint8_t ctrl_reg = 0x20;
    uint8_t adc_reg = 0x23;

    WriteRegister(temp_reg, (ReadRegister(temp_reg) | 0b11000000)); // enable ADC
    WriteRegister(ctrl_reg, (ReadRegister(ctrl_reg) | 0b01000111)); // enable normal mode
    WriteRegister(adc_reg, (ReadRegister(adc_reg) | 0b10000000)); // enable BDU
  
    for(;;){ 
            get_speed();
        if (echo_flag) {
            get_distance(duration);
            echo_flag = 0;          

            NVIC_EnableIRQ((IRQn_Type)Timer_Echo_Int_cfg.intrSrc);
            PWM_Trigger_Start();
        }        
        CyDelay(80);
}
}
/* [] END OF FILE */
