///*
// * app.c
// *
// *  Created on: Jul 1, 2024
// *      Author: Hana Nabhan
// */
//
#include <avr/io.h>
#include <avr/interrupt.h>
//#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_MACROS.h"
#include "LED.h"

int main(void)
{
    // Initialize LEDs
    LED_voidINIT('A', 0);
    LED_voidINIT('A', 1);
    LED_voidINIT('A', 2);

    // Enable global interrupts
    sei();

    // Enable external interrupts INT0, INT1, and INT2
    SET_BIT(GICR, INT0);
    SET_BIT(GICR, INT1);
    SET_BIT(GICR, INT2);

    // Set rising edge for INT0
    SET_BIT(MCUCR, ISC00);
    SET_BIT(MCUCR, ISC01);

    // Set rising edge for INT1
    SET_BIT(MCUCR, ISC10);
    SET_BIT(MCUCR, ISC11);

     //Set rising edge for INT2
    SET_BIT(MCUCSR, ISC2);

    while(1)
    {
        // Turn off all LEDs
        LED_voidOFF('A', 0);
        LED_voidOFF('A', 1);
        LED_voidOFF('A', 2);
    }
}

ISR(INT0_vect)
{
    // Ensure global interrupts are enabled (usually not needed in ISR)
    sei();
    // Turn on LED connected to PA0 and wait for 1 second
    LED_voidON('A', 0);
    _delay_ms(1000);
}

ISR(INT1_vect)
{
    sei();
    LED_voidON('A', 1);
    _delay_ms(1000);
}

ISR(INT2_vect)
{
    //sei();
    LED_voidON('A', 2);
    _delay_ms(1000);
}
