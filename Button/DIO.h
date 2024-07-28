/*
 * DIO.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Hana Nabhan
 */

#ifndef DIO_H_
#define DIO_H_


typedef enum {
	INPUT_PIN,OUTPUT_PIN
}DIOPinDIR;


void DIO_voidSetPinDir(uint8 PortName , uint8 PinNumber , DIOPinDIR value);
void DIO_voidWritePin(uint8 PortName , uint8 PinNumber , uint8 value);
uint8 DIO_u8ReadPin(uint8 PortName , uint8 PinNumber);
void DIO_voidTogglePin(uint8 PortName , uint8 PinNumber);

void DIO_voidSetPortDir(uint8 PortName , uint8 value);
void DIO_voidWritePort(uint8 PortName , uint8 value);
uint8 DIO_u8ReadPort(uint8 PortName);
void DIO_voidTogglePort(uint8 PortName);




#endif /* DIO_H_ */
