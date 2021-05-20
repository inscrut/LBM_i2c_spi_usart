/*
 * usart.h
 *
 * Created: 20.05.2021 20:10:03
 *  Author: HodyrevV
 */ 


#ifndef USART_H_
#define USART_H_

#include <avr/io.h>

#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void USART_Init(unsigned int _boud); // Init USART
void USART_Send(uint8_t _data); //Send byte
uint8_t USART_Receive(); //Resieve byte
void USART_Flush(); //Clear buffer, last readed byte

#endif /* USART_H_ */