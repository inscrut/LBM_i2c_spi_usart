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

void TWI_Init(); //setup frq

void TWI_StartCnd(); //start condition

void TWI_StopCnd(); //set stop condition

void TWI_SendByte(uint8_t _byte); //send byte on line

uint8_t TWI_GetAddr(uint8_t _addr, uint8_t _wr); //return MSB address and write|read

#endif /* MEGA_TWI_H_ */