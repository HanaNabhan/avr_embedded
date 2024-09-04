/*
 * ADC.c
 *
 * Created: 8/2/2024 11:35:39 PM
 *  Author: Hana Nabhan
 */ 

#include <avr/io.h>
#include "STD_MACROS.h"

void ADC_vInit(uint8 num){
	// Make AVCC as reference
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADCSRA, ADEN);
	ADMUX &= 0xF0;
	switch(num){
		case 1:
		// Enable ADC1
		SET_BIT(ADMUX, MUX0);
		break;
		case 2:
		// Enable ADC2
		SET_BIT(ADMUX, MUX1);
		break;
		case 3:
		// Enable ADC3
		SET_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		break;
		case 4:
		// Enable ADC4
		SET_BIT(ADMUX, MUX2);
		break;
		case 5:
		// Enable ADC5
		SET_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX2);
		break;
		case 6:
		// Enable ADC6
		SET_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		break;
		case 7:
		// Enable ADC7
		SET_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		break;
		default:
		break;
	}
	// Enable clock to /64
	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
}

uint16 ADC_u16Read(void){
	uint16 read_val;
	// Enable start conversion
	SET_BIT(ADCSRA, ADSC);
	// Wait for conversion to complete
	while(IS_BIT_CLR(ADCSRA,ADIF));//stay in your position till ADIF become 1
	SET_BIT(ADCSRA,ADIF); // clear ADIF
	// Read ADC result
	read_val = (ADCL);
	read_val |= (ADCH << 8);
	return read_val;
}

