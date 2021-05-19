/*
 * mega_twi.h
 *
 * Created: 19.05.2021 20:54:58
 *  Author: HodyrevV
 */ 


#ifndef MEGA_TWI_H_
#define MEGA_TWI_H_

#include <util/twi.h>
#include <stdint.h>

#define TWI_STATUS_S_DATA_ASK 0x28 //master transceive data, slave accept enter data
#define TWI_STATUS_M_DATA_ASK 0x50 //master receive data and transceive accept
#define TWI_STATUS_S_DATA_NASK 0x58 //master transceive data, slave without accept enter data

void TWI_Init(); //setup frq

void TWI_StartCnd(); //start condition

void TWI_StopCnd(); //set stop condition

void TWI_SendByte(uint8_t _byte); //send byte on line

void TWI_ReadByte(); //read byte from line
void TWI_ReadLastByte(); //read last byte from line
uint8_t TWI_GetReadByte(); //return read byte

uint8_t TWI_GetAddr(uint8_t _addr, uint8_t _wr); //return MSB address and write|read

#endif /* MEGA_TWI_H_ */