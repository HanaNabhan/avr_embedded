/*
 * EEPROM.h
 *
 *  Created on: Jun 25, 2024
 *      Author: Hana Nabhan
 */

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_vWrite(uint16 address,uint8 data);
uint8 EEPROM_u8Read(uint16 address);

#endif
