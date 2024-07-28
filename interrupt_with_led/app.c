/*
 * app.c
 *
 *  Created on: Jul 1, 2024
 *      Author: Hana Nabhan
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "STD_MACROS.h"
#include "LED.h"
#include "BUTTON.h"
#include "DIO.h"

int main(void){
	LED_voidINIT('C',0);
	sei();
	BUTTON_voidINIT('D',2);
	SET_BIT(GICR,INT0);
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);// on rising edge

	while(1){
		LED_voidOFF('C',0);
	}
}

ISR(INT0_vect){
	LED_voidON('C',0);
	_delay_ms(1000);

}
