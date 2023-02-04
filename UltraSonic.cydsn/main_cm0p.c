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
#define safeDistance 10.00

uint16_t duration, duration1, duration2, duration3 = 0;
bool echo_flag = 0;
double SoundSpeed = 0.0;
char str[128]; /* buffer for first sensor */
char str1[128]; /* buffer for second sensor */
char str2[128]; /* buffer for second sensor */
char str3[128]; /* buffer for second sensor */

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
    NVIC_ClearPendingIRQ(Timer_Echo_1_Int_cfg.intrSrc);
    NVIC_ClearPendingIRQ(Timer_Echo_2_Int_cfg.intrSrc);
    NVIC_ClearPendingIRQ(Timer_Echo_3_Int_cfg.intrSrc);
    NVIC_DisableIRQ((IRQn_Type)Timer_Echo_Int_cfg.intrSrc);
    NVIC_DisableIRQ((IRQn_Type)Timer_Echo_1_Int_cfg.intrSrc);
    NVIC_DisableIRQ((IRQn_Type)Timer_Echo_2_Int_cfg.intrSrc);
    NVIC_DisableIRQ((IRQn_Type)Timer_Echo_3_Int_cfg.intrSrc);

    duration = Timer_Echo_GetCapture(); // first sensor
    duration1 = Timer_Echo_1_GetCapture(); // second sensor
    duration2 = Timer_Echo_2_GetCapture(); // second sensor
    duration3 = Timer_Echo_3_GetCapture(); // second sensor
    
    Timer_Echo_SetCounter(0);
    Timer_Echo_1_SetCounter(0);
    Timer_Echo_2_SetCounter(0);
    Timer_Echo_3_SetCounter(0);
    
    PWM_Trigger_Disable();
    PWM_Trigger_1_Disable();
    PWM_Trigger_2_Disable();
    PWM_Trigger_3_Disable();
   
    echo_flag = 1;
}

void get_speed(){
    uint8 Temp = ReadRegister(0x0D) + 25 - ((ReadRegister(0x0C))>>6);
    SoundSpeed = (sqrt((k*R*(Temp+273.15)))/sqrt(M));  
//    printf("Temp = %d\n\r", Temp); 
//    printf("Sound Speed = %f\n\r", SoundSpeed);
}

void get_distance(uint32_t duration, uint32_t duration1, uint32_t duration2, uint32_t duration3){
    double distance, distance1, distance2, distance3 = 0.0;
    distance = (double)(duration) * SoundSpeed / 240000.0; // Distance from first sensor
    distance1 = (double)(duration1) * SoundSpeed / 240000.0; // Distance from second sensor
    distance2 = (double)(duration2) * SoundSpeed / 240000.0; // Distance from second sensor
    distance3 = (double)(duration3) * SoundSpeed / 240000.0; // Distance from second sensor

    
    if((distance < safeDistance) || (distance1 < safeDistance)){
        snprintf(str,30,"WARNING! : OBJECT LEFT \n\r");
        snprintf(str1,30,"WARNING! : OBJECT LEFT \n\r");
        Cy_GPIO_Write(P10_4_PORT, P10_4_NUM, 1);
    }
    if((distance > safeDistance) && (distance1 > safeDistance)){
        snprintf(str,30,"s1 = %.2f cm\n\r", distance);
        snprintf(str1,30,"s2 = %.2f cm\n\r", distance1);
        Cy_GPIO_Write(P10_4_PORT, P10_4_NUM, 0);
    }
    
    if((distance2 < safeDistance) || (distance3 < safeDistance)){
        snprintf(str2,30,"WARNING! : OBJECT RIGHT \n\r");
        snprintf(str3,30,"WARNING! : OBJECT RIGHT \n\r");
        Cy_GPIO_Write(P10_4_PORT, P10_4_NUM, 1);
    }
    
    if((distance2 > safeDistance) && (distance3 > safeDistance)){
        snprintf(str2,30,"s3 = %.2f cm\n\r", distance2);
        snprintf(str3,30,"s4 = %.2f cm\n\r", distance3);
        Cy_GPIO_Write(P10_4_PORT, P10_4_NUM, 0);
    }




//    fflush(stdin); /* clear buffer */
    
 // snprintf(str1,10,"%.2f\n\r", distance1);
    
    UART_PutString(str);
    UART_PutString(str1);
    UART_PutString(str2);
    UART_PutString(str3);
}

int main(void){
    __enable_irq(); /* Enable global interrupts. */
    UART_Start();
    Timer_Echo_Start();
    Timer_Echo_1_Start();
    Timer_Echo_2_Start();
    Timer_Echo_3_Start();
    
    PWM_Trigger_Start();
    PWM_Trigger_1_Start();
    PWM_Trigger_2_Start();
    PWM_Trigger_3_Start();
    
    Cy_SysInt_Init(&Timer_Echo_Int_cfg, Timer_Int_Handler);
    Cy_SysInt_Init(&Timer_Echo_1_Int_cfg, Timer_Int_Handler);
    Cy_SysInt_Init(&Timer_Echo_2_Int_cfg, Timer_Int_Handler);
    Cy_SysInt_Init(&Timer_Echo_3_Int_cfg, Timer_Int_Handler);
    
    NVIC_EnableIRQ((IRQn_Type)Timer_Echo_Int_cfg.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)Timer_Echo_1_Int_cfg.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)Timer_Echo_2_Int_cfg.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)Timer_Echo_3_Int_cfg.intrSrc);
  
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
            get_distance(duration,duration1,duration2,duration3);
            echo_flag = 0;          

            NVIC_EnableIRQ((IRQn_Type)Timer_Echo_Int_cfg.intrSrc);
            NVIC_EnableIRQ((IRQn_Type)Timer_Echo_1_Int_cfg.intrSrc);
            NVIC_EnableIRQ((IRQn_Type)Timer_Echo_2_Int_cfg.intrSrc);
            NVIC_EnableIRQ((IRQn_Type)Timer_Echo_3_Int_cfg.intrSrc);
            
            PWM_Trigger_Start();
            PWM_Trigger_1_Start();
            PWM_Trigger_2_Start();
            PWM_Trigger_3_Start();
        }        
        CyDelay(80);
}
}
/* [] END OF FILE */
