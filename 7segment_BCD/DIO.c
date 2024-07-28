/*
 * main.c
 *
 *  Created on: Jan 25, 2024
 *      Author: Hana Nabhan
 *
 */

///////////////////////////////////////////////////////////////
				        //Includes//
///////////////////////////////////////////////////////////////

#include<avr/io.h>
#include"STD_MACROS.h"
#include"DIO.h"




///////////////////////////////////////////////////////////////
				        //FUNCTIONS//
///////////////////////////////////////////////////////////////


/*
 * FUNCTION NAME : DIO_voidSetPinDir
 * ARGUMENTS : uint8 PortName , uint8 PinNumber , DIOPinDIR value
 * DESCRIPTION : Used to set the specific pin from a specific port as input or output
 * RETURN : No return
 */


void DIO_voidSetPinDir(uint8 PortName , uint8 PinNumber , DIOPinDIR value){
	switch(PortName){
		case'A':
		case'a':
			if(value == OUTPUT_PIN){

				SET_BIT( DDRA , PinNumber);

			}
			else{

				CLR_BIT( DDRA , PinNumber);

			}
		break;
		case'B':
		case'b':
			if(value == OUTPUT_PIN){

				SET_BIT( DDRB , PinNumber);

			}
			else{

				CLR_BIT( DDRB , PinNumber);

			}
		break;
		case'C':
		case'c':
			if(value == OUTPUT_PIN){

				SET_BIT( DDRC , PinNumber);

			}
			else{

				CLR_BIT( DDRC , PinNumber);

			}
		break;
		case'D':
		case'd':
			if(value == OUTPUT_PIN){

				SET_BIT( DDRD , PinNumber);

			}
			else{

				CLR_BIT( DDRD , PinNumber);

			}
		break;
		default:
			break;

	}
}

///////////////////////////////////////////////////////////////


/*
 * FUNCTION NAME : DIO_voidWritePin
 * ARGUMENTS : uint8 PortName , uint8 PinNumber , uint8 value
 * DESCRIPTION : Used to write on specific pin from a specific port as logic high or low
 * RETURN : No return
 */

void DIO_voidWritePin(uint8 PortName , uint8 PinNumber , uint8 value){
	switch(PortName){
		case'A':
		case'a':
			if(value == HIGH){

				SET_BIT( PORTA , PinNumber);

			}
			else{

				CLR_BIT( PORTA , PinNumber);

			}
		break;
		case'B':
		case'b':
			if(value == HIGH){

				SET_BIT( PORTB , PinNumber);

			}
			else{

				CLR_BIT( PORTB , PinNumber);

			}
		break;
		case'C':
		case'c':
			if(value == HIGH){

				SET_BIT( PORTC , PinNumber);

			}
			else{

				CLR_BIT( PORTC , PinNumber);

			}
		break;
		case'D':
		case'd':
			if(value == HIGH){

				SET_BIT( PORTD , PinNumber);

			}
			else{

				CLR_BIT( PORTD , PinNumber);

			}
		break;
		default:
		break;

	}
}
///////////////////////////////////////////////////////////////


/*
 * FUNCTION NAME : DIO_u8ReadPin
 * ARGUMENTS : uint8 PortName , uint8 PinNumber
 * DESCRIPTION : Used to read specific pin from a specific port
 * RETURN : Reading of the pin
 */


uint8 DIO_u8ReadPin(uint8 PortName , uint8 PinNumber){
	uint8 value;
	switch(PortName){
		case'A':
		case'a':
			value=READ_BIT(PINA , PinNumber);
		break;
		case'B':
		case'b':
			value=READ_BIT(PINB , PinNumber);

		break;
		case'C':
		case'c':
			value=READ_BIT(PINC , PinNumber);

		break;
		case'D':
		case'd':
			value=READ_BIT(PIND , PinNumber);
		break;
		default:
		break;

	}
	return value;
}
///////////////////////////////////////////////////////////////


/*
 * FUNCTION NAME : DIO_voidTogglePin
 * ARGUMENTS : uint8 PortName , uint8 PinNumber
 * DESCRIPTION : Used to toggle specific pin from a specific port
 * RETURN : No return
 */
void DIO_voidTogglePin(uint8 PortName , uint8 PinNumber){
	switch(PortName){
		case'A':
		case'a':
			TOG_BIT(PORTA , PinNumber);
		break;
		case'B':
		case'b':
			TOG_BIT(PORTB , PinNumber);

		break;
		case'C':
		case'c':
			TOG_BIT(PORTC , PinNumber);

		break;
		case'D':
		case'd':
			TOG_BIT(PORTD , PinNumber);
		break;
		default:
		break;

	}
}



///////////////////////////////////////////////////////////////

/*
 * FUNCTION NAME : DIO_voidSetPortDir
 * ARGUMENTS : uint8 PortName , uint8 value
 * DESCRIPTION : Used to set  specific port as input or output
 * RETURN : No return
 */

void DIO_voidSetPortDir(uint8 PortName , uint8 value){
	switch(PortName){
		case'A':
		case'a':

			DDRA=value;

		break;

		case'B':
		case'b':

			DDRB=value;

		break;

		case'C':
		case'c':

			DDRC=value;

		break;

		case'D':
		case'd':

			DDRD=value;

		break;
		default:
			break;

	}
}

///////////////////////////////////////////////////////////////

/*
 * FUNCTION NAME : DIO_voidWritePort
 * ARGUMENTS : uint8 PortName , uint8 value
 * DESCRIPTION : Used to write on  specific port as logic high or low
 * RETURN : No return
 */

void DIO_voidWritePort(uint8 PortName , uint8 value){
	switch(PortName){
			case'A':
			case'a':

				PORTA=value;

			break;

			case'B':
			case'b':

				PORTB=value;

			break;

			case'C':
			case'c':

				PORTC=value;

			break;

			case'D':
			case'd':

				PORTD=value;

			break;
			default:
				break;


	}
}
///////////////////////////////////////////////////////////////

/*
 * FUNCTION NAME : DIO_u8ReadPort
 * ARGUMENTS : uint8 PortName
 * DESCRIPTION : Used to read specific port
 * RETURN : Reading of the port
 */

uint8 DIO_u8ReadPort(uint8 PortName){
	uint8 value;
	switch(PortName){
		case'A':
		case'a':
			value=PINA;
		break;
		case'B':
		case'b':
			value=PINB;

		break;
		case'C':
		case'c':
			value=PINC;

		break;
		case'D':
		case'd':
			value=PIND;
		break;
		default:
		break;

	}
	return value;
}
///////////////////////////////////////////////////////////////


/*
 * FUNCTION NAME : DIO_voidTogglePort
 * ARGUMENTS : uint8 PortName
 * DESCRIPTION : Used to toggle specific port
 * RETURN : No return
 */

void DIO_voidTogglePort(uint8 PortName){
	switch(PortName){
		case'A':
		case'a':
			TOG_REG(PORTA);
		break;
		case'B':
		case'b':
			TOG_REG(PORTB);

		break;
		case'C':
		case'c':
			TOG_REG(PORTC);

		break;
		case'D':
		case'd':
			TOG_REG(PORTD);
		break;
		default:
		break;

	}
}




/*
 * FUNCTION NAME : DIO_voidwritenibble
 * ARGUMENTS : uint8 PortName ,uint8 value ,uint8 nibble
 * DESCRIPTION : Used to toggle specific port
 * RETURN : No return
 */

void DIO_voidWriteNibble(uint8 PortName , uint8 value ,uint8 nibble){
	value&=0x0f; // to take only first 4 bits

	if(nibble){ //LAST 4 PINS
	value=value<<4;
	switch(PortName){
			case'A':
			case'a':

				PORTA&=0x0f;
				PORTA|=value;


			break;

			case'B':
			case'b':
				PORTB&=0x0f;
				PORTB|=value;

			break;

			case'C':
			case'c':
				PORTC&=0x0f;
				PORTC|=value;

			break;

			case'D':
			case'd':
				PORTD&=0x0f;
				PORTD|=value;

			break;
			default:
				break;
	}}
	else{
		switch(PortName){
			case'A':
			case'a':

					PORTA&=0xf0;
					PORTA|=value;


			break;

		    case'B':
			case'b':
					PORTB&=0xf0;
					PORTB|=value;

			break;

			case'C':
			case'c':
					PORTC&=0xf0;
					PORTC|=value;

			break;

			case'D':
			case'd':
					PORTD&=0xf0;
					PORTD|=value;

			break;
			default:
			break;
				}

	}
}

//////////////////////////////////////////////////////////////////////////////
/*
 * FUNCTION NAME : DIO_voidConnectPullUp
 * ARGUMENTS : uint8 PortName , uint8 PinNumber , uint8 connect
 * DESCRIPTION :
 	 to activate pull up
	 * SFIOR=0 by default
	 * DDRx N must be INPUT
	 * PORT xN =1
 * RETURN : No return
 */
void DIO_voidConnectPullUp(uint8 PortName , uint8 PinNumber , uint8 connect){
	DIO_voidWritePin(PortName,PinNumber,connect);


}
