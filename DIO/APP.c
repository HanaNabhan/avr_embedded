/*
 * APP.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Hana Nabhan
 */

#include"STD_MACROS.h"
#include"DIO.h"
#include<util/delay.h>


int main(void){
//	DIO_voidSetPinDir('D',1,INPUT_PIN);
//	DIO_voidSetPinDir('D',0,OUTPUT_PIN);

	DIO_voidSetPortDir('D',0XFF);
	while(1){
	/*	DIO_voidTogglePin('D',0);
		_delay_ms(1000);*/
//		DIO_voidTogglePort('A');
//		_delay_ms(1000);
//		uint8 value =DIO_u8ReadPin('D',1);
//		DIO_voidWritePin('D',0,value);
		DIO_voidWritePort('D',0XFF);
		_delay_ms(1000);
		DIO_voidWritePort('D',0X00);
		_delay_ms(1000);


	}
}
