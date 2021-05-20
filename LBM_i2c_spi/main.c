/*
 * LBM_i2c_spi.c
 *
 * Created: 19.05.2021 20:16:15
 * Author : HodyrevV
 */ 

#include <avr/io.h>
#include "mega_twi.h"
#include "EEPROM_Ext.h"
#include "usart.h"
#include "SPI.h"

#define IIC_1_ADDR 0b10100000 //1010 - default, 0 - A2 pin, 00 - page (a8 a9), 0 - write|read
#define IIC_2_ADDR 0b10101000 //second device

uint8_t buf[] = {'H','e','l','l','o'};

uint8_t rbuf[5] = {0};

int main(void)
{

	TWI_Init();
	
	//Write
	
	EE_InitMasterWrite(IIC_2_ADDR, 0x00, 0x00);
	for(uint8_t i=0; i<5; i++){
		if(EE_WriteByte(buf[i]) != 0x00) break;
	}
	EE_Stop();
	
	//Read
	
	EE_InitMasterRead(IIC_2_ADDR, 0x00, 0x00);
	for (uint8_t i=0; i<5-1; i++)
	{
		rbuf[i] = EE_ReadByte();
		if(EE_ReadStatus() == 0x01) break;
	}
	rbuf[4] = EE_ReadLastByte();
	EE_Stop();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

