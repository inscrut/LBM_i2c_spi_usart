/*
 * SPI.h
 *
 * Created: 20.05.2021 20:26:14
 *  Author: HodyrevV
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

#define PORT_SPI PORTB //renaming
#define PORT_MOSI PB3
#define PORT_MISO PB4
#define PORT_SCK PB5

#define DDR_SPI DDRB
#define DD_MOSI DDB3
#define DD_MISO DDB4
#define DD_SCK DDB5

void SPI_MasterInit();
void SPI_MasterTransmit(uint8_t _cData);
uint8_t SPI_MasterReceive();
void SPI_SlaveInit();
uint8_t SPI_SlaveReceive();

#endif /* SPI_H_ */