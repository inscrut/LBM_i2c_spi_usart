/*
 * EEPROM_Ext.c
 *
 * Created: 19.05.2021 22:02:25
 *  Author: HodyrevV
 */ 

#include "EEPROM_Ext.h"

uint8_t mng_err = 0x00;

void EE_InitMasterWrite(uint8_t _slave_addr, uint8_t _paddr){
	TWI_StartCnd(); // start cond
	TWI_SendByte(TWI_GetAddr(_slave_addr, 0x00)); //slave, write
	TWI_SendByte(_paddr); //Page address
}

void EE_InitMasterReadPage(uint8_t _slave_addr){
	TWI_StartCnd(); // start cond
	TWI_SendByte(TWI_GetAddr(_slave_addr, 0x01)); //slave, read
}

void EE_Stop(){
	TWI_StopCnd();
}

uint8_t EE_WriteByte(uint8_t _byte){
	TWI_SendByte(_byte);
	if((TWSR & 0xF8) != TWI_STATUS_S_DATA_ASK) return 1;
	return 0;
}

uint8_t EE_ReadByte(){
	TWI_ReadByte();
	if((TWSR & 0xF8) != TWI_STATUS_M_DATA_ASK) {
		mng_err = 0x01;
		return 0xFF;
	}
	return TWI_GetReadByte();
}

uint8_t EE_ReadLastByte(){
	TWI_ReadLastByte();
	if((TWSR & 0xF8) != TWI_STATUS_S_DATA_NASK) {
		mng_err = 0x01;
		return 0xFF;
	}
	return TWI_GetReadByte();
}

uint8_t EE_RandomRead(uint8_t _slave_addr, uint8_t _wordpage){
	uint8_t _d = 0xFF;
	TWI_StartCnd(); // start cond
	TWI_SendByte(TWI_GetAddr(_slave_addr, 0x00)); //slave, write
	TWI_SendByte(_wordpage); //MBR of address
	//TWI_SendByte(_lbr); //LBR of address EEPROM
	TWI_StartCnd();
	TWI_SendByte(TWI_GetAddr(_slave_addr, 0x01)); //slave, read
	_d = EE_ReadLastByte();
	EE_Stop();
	return _d;
}

void EE_ByteWrite(uint8_t _slave_addr, uint8_t _wordpage, uint8_t _data){
	TWI_StartCnd(); // start cond
	TWI_SendByte(TWI_GetAddr(_slave_addr, 0x00)); //slave, write
	TWI_SendByte(_wordpage); //Address
	TWI_SendByte(_data); //DATA
	EE_Stop();
}

uint8_t EE_ReadStatus(){
	if(mng_err != 0x00){
		mng_err = 0x00;
		return 1;
	}
	else return 0;
}