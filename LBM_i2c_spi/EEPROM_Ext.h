/*
 * EEPROM_Ext.h
 *
 * Created: 19.05.2021 22:02:37
 *  Author: HodyrevV
 */ 


#ifndef EEPROM_EXT_H_
#define EEPROM_EXT_H_

#include "mega_twi.h"

void EE_InitMasterWrite(uint8_t _slave_addr, uint8_t _mbr, uint8_t _lbr); // Init for write
void EE_InitMasterRead(uint8_t _slave_addr, uint8_t _mbr, uint8_t _lbr); // Init for read
void EE_Stop(); // Stop connect

uint8_t EE_WriteByte(uint8_t _byte); // Write byte on EEPROM
uint8_t EE_ReadByte(); //Read byte from EEPROM
uint8_t EE_ReadLastByte(); //Read last byte from EEPROM
uint8_t EE_ReadStatus(); //Status of read from line

uint8_t EE_RandomRead(uint8_t _slave_addr, uint8_t _wordpage); //Random Read, one byte
void EE_ByteWrite(uint8_t _slave_addr, uint8_t _wordpage, uint8_t _data); //Write one byte

#endif /* EEPROM_EXT_H_ */