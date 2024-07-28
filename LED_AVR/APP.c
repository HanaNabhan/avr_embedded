/*
 * app.c
 *
 * Created: 2/12/2024 9:47:19 PM
 *  Author: Hana Nabhan
 */


#include<avr/io.h>
#include <util/delay.h>
#include "STD_MACROS.h"


int main(void){

	LED_voidINIT('D',0);
	LED_voidINIT('D',1);
	LED_voidINIT('D',2);
	uint8 i =1 ;
	while(1){
		/*LED_voidON('A',2);
		_delay_ms(1000);
		LED_voidOFF('A',2);
		_delay_ms(1000);
		LED_voidToggle('A',2);
		_delay_ms(250);
		LED_voidToggle('A',2);
		_delay_ms(250);
		LED_voidToggle('A',2);
		_delay_ms(250);
		LED_voidToggle('A',2);
		_delay_ms(250);*/


		LED_voidToggle('D',0);
		if(i%2==0){
			LED_voidToggle('D',1);
		}
		 if(i%3==0){
			LED_voidToggle('D',2);
		}
		_delay_ms(1000);
		i++;

	}
}
