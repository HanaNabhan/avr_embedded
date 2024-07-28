/*
 *
 *
 *  Created on: Jun 22, 2024
 *      Author: Hana Nabhan
 */

#ifndef SEVEN_H_
#define SEVEN_H_



void SevenSegment_voidInit(uint8 PortName );
void SevenSegment_voidWrite(uint8 PortName , uint8 value);

void SevenSegment_voidInitBCD(uint8 PortName , uint8 nibble);
void SevenSegment_voidWriteBCD(uint8 PortName , uint8 value ,uint8 nibble);


#endif
