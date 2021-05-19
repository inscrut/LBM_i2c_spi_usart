/*
 * EEPROM_Ext.c
 *
 * Created: 19.05.2021 22:02:25
 *  Author: HodyrevV
 */ 

#include "EEPROM_Ext.h"

uint8_t mng_err = 0x00;

void EE_InitMasterWrite(uint8_t _slave_addr, uint8_t _mbr, uint8_t _lbr){
	TWI_StartCnd(); // start cond
	TWI_SendByte(TWI_GetAddr(_slave_addr, 0x00)); //slave, write
	TWI_SendByte(_mbr); //MBR of address
	TWI_SendByte(_lbr); //LBR of address EEPROM
}

void EE_InitMasterRead(uint8_t _slave_addr, uint8_t _mbr, uint8_t _lbr){
	TWI_StartCnd(); // start cond
	TWI_SendByte(TWI_GetAddr(_slave_addr, 0x00)); //slave, write
	TWI_SendByte(_mbr); //MBR of address
	TWI_SendByte(_lbr); //LBR of address EEPROM
	TWI_StartCnd();
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

uint8_t EE_ReadStatus(){
	if(mng_err != 0x00){
		mng_err = 0x00;
		return 1;
	}
	else return 0;
}