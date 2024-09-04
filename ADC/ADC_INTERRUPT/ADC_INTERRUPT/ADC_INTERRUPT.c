/*
 * ADC_INTERRUPT.c
 *
 * Created: 8/3/2024 7:48:30 PM
 *  Author: Hana Nabhan
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_MACROS.h"
#include "ADC.h"


int main(void)
{
	ADC_vInit(0);
	sei();
	SET_BIT(ADCSRA,ADIE);
	LED_voidINIT('D',0);
	LED_voidINIT('D',1);
    while(1)
    {
        //TODO:: Please write your application code 
		SET_BIT(ADCSRA,ADSC);
		_delay_ms(1);
		LED_voidON('D',0);
		LED_voidOFF('D',1);
		_delay_ms(1000);
    }
}
ISR(ADC_vect){
	LED_voidON('D',1);
    LED_voidOFF('D',0);
	_delay_ms(1000);
}