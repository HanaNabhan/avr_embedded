/*
 * button.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Hana Nabhan
 */
#include"STD_MACROS.h"
#include"DIO.h"
#include"BUTTON.h"

void BUTTON_voidINIT(uint8 port , uint8 pin){
	DIO_voidSetPinDir(port,pin,INPUT_PIN);
}
uint8 BUTTON_u8Read(uint8 port ,uint8 pin){
	return DIO_u8ReadPin(port,pin);
}

