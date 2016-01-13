/*************************************************************************
Title:    ARD-LTC2499 Driver Library
Authors:  Nathan D. Holmes <maverick@drgw.net>
File:     $Id: $
License:  GNU General Public License v3

LICENSE:
    Copyright (C) 2013 Nathan D. Holmes & Michael D. Petersen

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

*************************************************************************/
#ifndef EE24AA025E48_H
#define EE24AA025E48_H

#include <stdlib.h>
#include <string.h>
#include "Arduino.h"
#include "Wire.h"

#ifndef _BV
#define _BV(a) (1<<(a))
#define _UNDEFINE_BV
#endif

#define EE24AA025E48_SUCCESS      0
#define EE24AA025E48_EEPROM_ERR   1

#define EE24AA025E48_EEP_ADDR_00 0x50
#define EE24AA025E48_EEP_ADDR_0Z 0x51
#define EE24AA025E48_EEP_ADDR_Z0 0x52
#define EE24AA025E48_EEP_ADDR_ZZ 0x53

#define EE24AA025E48_EEPROM_ADDR_EUI48  0xFA

class EE24AA025E48
{
	public:
		EE24AA025E48();
		byte begin(byte eepromAddress);
		const char* eui48Get();
		byte eepromRead(int address, byte defaultOnError);
		byte eepromWrite(int address, byte value, byte blocking);

	private:
		uint8_t init_status;
		uint8_t i2cAddr_eeprom;
		char eui48[6*2+1];
};

extern EE24AA025E48 ee24aa025e48;

#endif // EE24AA025E48_H


