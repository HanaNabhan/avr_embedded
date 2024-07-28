/*
 * APP.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Hana Nabhan
 */
#include<avr/io.h>
#include<util/delay.h>
#include"STD_MACROS.h"
#include"LED.h"

int main(void){

	BUTTON_voidINIT('D',0);
	LED_voidINIT('A',0);

	while(1){
		if(BUTTON_u8Read('D',0)){
			LED_voidON('A',0);
		}
		else {
			LED_voidOFF('A',0);
		}
	}
	_delay_ms(200);

}
