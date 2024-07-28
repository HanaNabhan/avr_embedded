/*
 * app.c
 *
 *  Created on: Jun 25, 2024
 *      Author: Hana Nabhan
 */

#include"STD_MACROS.h"
#include "EEPROM.h"
int main(void)
{

	EEPROM_vWrite(0x0030,0X50);
    while(1)
    {

    }
}
