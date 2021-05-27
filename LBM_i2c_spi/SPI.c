/*
 * SPI.c
 *
 * Created: 20.05.2021 20:26:03
 *  Author: HodyrevV
 */ 

#include "SPI.h"

void SPI_MasterInit()
{
	/* Set MOSI and SCK output, all others input */
	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void SPI_MasterTransmit(uint8_t _cData)
{
	/* Start transmission */
	SPDR = _cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
}
uint8_t SPI_MasterReceive(){
	// transmit dummy byte, for CLK generation, mosi high
	SPDR = 0xFF;
	// Wait for reception complete
	while(!(SPSR & (1<<SPIF)));
	// return Data Register
	return SPDR;
}

void SPI_SlaveInit()
{
	DDR_SPI = (1<<DD_MISO);
	/* Enable SPI */
	SPCR = (1<<SPE);
}
uint8_t SPI_SlaveReceive()
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)));
	/* Return Data Register */
	return SPDR;
}