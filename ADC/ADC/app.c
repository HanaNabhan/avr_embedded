/*
 * app.c
 *
 * Created: 8/2/2024 11:56:34 PM
 *  Author: Hana Nabhan
 */ 
#include <avr/io.h>
#include "STD_MACROS.h"
#include "LED.h"
#include "ADC.h"


int main(void){
	ADC_vInit(1);
	LED_voidINIT('D',0);
	LED_voidINIT('D',1);
	LED_voidINIT('D',2);
	LED_voidINIT('D',3);
    LED_voidINIT('D',4);
	LED_voidINIT('D',5);
	LED_voidINIT('D',6);
	LED_voidINIT('D',7);
	
	while(1){
		PORTD=ADC_u16Read();
	}
}