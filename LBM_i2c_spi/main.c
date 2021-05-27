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

uint8_t buf[] = {'H','e','l','l','o'};
uint8_t rbuf[5] = {0};

#define ChipS1 PORTC2
#define ChipS2 PORTC3

int main(void)
{
	DDRC |= (1 << ChipS1) | (1 << ChipS2); //output chip selects
	PORTC |= (1 << ChipS1) | (1 << ChipS2); //set high levels
	
	
	//Write 1 byte

	PORTC &= ~(1 << ChipS1); //chip select 1, low
	SPI_MasterInit(); //master
	
	SPI_MasterTransmit(0b00000110); //set write enable
	
	SPI_MasterTransmit(0b00000010); //write command
	SPI_MasterTransmit(0x00); //set address to write, 16 bit
	SPI_MasterTransmit(0x00);
	
	SPI_MasterTransmit('K'); //insert 1 byte
	
	PORTC |= (1 << ChipS1); //end transmission, high
	
	//Write 5 byte (64 byte max page, for more - new transmit)
	
	PORTC &= ~(1 << ChipS1); //chip select 1, low
	SPI_MasterInit(); //master
	
	SPI_MasterTransmit(0b00000110); //set write enable
	
	SPI_MasterTransmit(0b00000010); //write command
	SPI_MasterTransmit(0x00); //set address to write, 16 bit
	SPI_MasterTransmit(0x00);
	
	for(uint8_t i = 0; i<5; i++){
		SPI_MasterTransmit(buf[i]); //send byte
	}
	
	PORTC |= (1 << ChipS1); //end transmission, high
	
	//Read 1 byte
	
	PORTC &= ~(1 << ChipS1); //chip select 1, low
	SPI_MasterInit(); //master
	
	SPI_MasterTransmit(0b00000011); //read command
	SPI_MasterTransmit(0x00); //set address to read, 16 bit
	SPI_MasterTransmit(0x00);

	rbuf[0] = SPI_MasterReceive(); //read byte
	
	PORTC |= (1 << ChipS1); //end transmission, high

	//Read 5 byte
	
	PORTC &= ~(1 << ChipS1); //chip select 1, low
	SPI_MasterInit(); //master
	
	SPI_MasterTransmit(0b00000011); //read command
	SPI_MasterTransmit(0x00); //set address to read, 16 bit
	SPI_MasterTransmit(0x00);

	for(uint8_t i = 0; i<5; i++){
		buf[i] = SPI_MasterReceive(); //read byte
	}
	
	PORTC |= (1 << ChipS1); //end transmission, high

    /* Replace with your application code */
    while (1) 
    {
		__asm__ __volatile__ ("nop");
    }
}

