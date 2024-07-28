/*
 * eeprom.c
 *
 *  Created on: Jun 25, 2024
 *      Author: Hana Nabhan
 */

#include <avr/io.h>
#include<util/delay.h>
#include "STD_MACROS.h"
#include "EEPROM.h"

void EEPROM_vWrite(uint16 address, uint8 data) {
    // put the address in EEAR register
    EEARL = (sint8) address;
    EEARH = (sint8) (address >> 8);

    // put the data in data register
    EEDR = data;

    // set to write
    SET_BIT(EECR, EEMWE);
    SET_BIT(EECR, EEWE);

    // polling until it is finished
      while (READ_BIT(EECR, EEWE)==1);
}

uint8 EEPROM_u8Read(uint16 address) {
    // put the address in EEAR register
    EEARL = (uint8) address;
    EEARH = (uint8) (address >> 8);

    // set to read
    SET_BIT(EECR, EERE);

    // return the data
  return EEDR;
}
