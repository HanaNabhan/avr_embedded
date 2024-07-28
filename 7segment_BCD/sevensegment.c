
/*
 *
 *
 *  Created on: Jun 22, 2024
 *      Author: Hana Nabhan
 */
#include "STD_MACROS.h"
#include "DIO.h"
#include "SEVEN_SEGMENT.h"



#define cc



void SevenSegment_voidInit(uint8 PortName ){
	DIO_voidSetPortDir(PortName , 0xff);
}
void SevenSegment_voidWrite(uint8 PortName , uint8 value){
#ifndef ca
    uint8 arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
#else
    uint8 arr[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71};
#endif

	DIO_voidWritePort( PortName ,arr[value]);
}
void SevenSegment_voidInitBCD(uint8 PortName , uint8 nibble){
	if(nibble){
		DIO_voidSetPinDir(PortName, 4 , OUTPUT_PIN);
		DIO_voidSetPinDir(PortName,5, OUTPUT_PIN);
		DIO_voidSetPinDir(PortName,6 , OUTPUT_PIN);
		DIO_voidSetPinDir(PortName,7 , OUTPUT_PIN);

	}
	else{ //first four

		DIO_voidSetPinDir(PortName,0 , OUTPUT_PIN);
		DIO_voidSetPinDir(PortName,1 , OUTPUT_PIN);
		DIO_voidSetPinDir(PortName,2 , OUTPUT_PIN);
		DIO_voidSetPinDir(PortName,3 , OUTPUT_PIN);
	}
}
void SevenSegment_voidWriteBCD(uint8 PortName , uint8 value ,uint8 nibble){

	DIO_voidWriteNibble(PortName,value,nibble);

}
