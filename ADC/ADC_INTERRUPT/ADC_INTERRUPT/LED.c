/*
 * LED.c
 *
 *  Created on: Feb 12, 2024
 *      Author: Hana Nabhan
 */




#include"STD_MACROS.h"
#include"DIO.h"
#include"LED.h"

void LED_voidINIT(uint8 port, uint8 pin){

	DIO_voidSetPinDir(port,pin , OUTPUT_PIN);

}
void LED_voidON(uint8 port, uint8 pin){

	DIO_voidWritePin(port,pin,HIGH);

}
void LED_voidOFF(uint8 port, uint8 pin){

	DIO_voidWritePin(port,pin,LOW);

}
void LED_voidToggle(uint8 port ,uint8 pin){
	DIO_voidTogglePin(port,pin);
}
uint8 LED_u8ReadStatus(uint8 port ,uint8 pin){

	return DIO_u8ReadPin(port ,pin);
}

