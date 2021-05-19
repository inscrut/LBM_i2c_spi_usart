/*
 * LBM_i2c_spi.c
 *
 * Created: 19.05.2021 20:16:15
 * Author : HodyrevV
 */ 

#include <avr/io.h>
#include "mega_twi.h"

#define IIC_1_ADDR 0x00
#define IIC_2_ADDR 0x04

int main(void)
{
	TWI_Init();
	
	TWI_StartCnd();
	TWI_SendByte(TWI_GetAddr(IIC_1_ADDR, 0x00));
	TWI_StopCnd();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

