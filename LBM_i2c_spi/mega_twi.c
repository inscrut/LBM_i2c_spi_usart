/*
 * mega_twi.c
 *
 * Created: 19.05.2021 20:55:15
 *  Author: HodyrevV
 */ 

#include "mega_twi.h"

void TWI_Init(){
	TWBR = 0x20; //set frq, 200 kHz, see datasheet
}

void TWI_StartCnd(){
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN); //run start
	while(!(TWCR & (1 << TWINT))); //wait setup bit
}

void TWI_StopCnd(){
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN); // stop
}

void TWI_SendByte(uint8_t _byte){
	TWDR = _byte;
	TWCR = (1 << TWINT) | (1 << TWEN); //start transmit byte
	while(!(TWCR & (1 << TWINT))); //wait
}

void TWI_ReadByte(){
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA); //start receive byte
	while(!(TWCR & (1 << TWINT))); //wait
}

void TWI_ReadLastByte(){
	TWCR = (1 << TWINT) | (1 << TWEN); //start receive byte
	while(!(TWCR & (1 << TWINT))); //wait
}

uint8_t TWI_GetReadByte(){
	return TWDR;
}

uint8_t TWI_GetAddr(uint8_t _addr, uint8_t _wr){ //0x00 - write, 0x01 - read
	return (0x00 | (_addr << 5) | _wr);
}