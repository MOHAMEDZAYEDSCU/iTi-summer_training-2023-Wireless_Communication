/*
 * DIO_Driver.c
 *
 *  Created on: 11 / 08 / 2023
 *      Author: Ahmad Abdelrazik
 */

#include "DIO_Driver.h"

/**
 * DIO_init - initialize the DIO DDR to configure input and output PINS.
 * @PORTNAME: Used to determine the PORT. use either (PORTA, PORTB, ...) or (0, 1, ...)
 * @PORTVALUE: The value to be stored in the DDR, with 0 for input PINS and 1 for output PINS.
 *
 * Return: Void.
 */
void DIO_init(uint8 PORTNAME, uint8 PORTVALUE)
{
	switch(PORTNAME)
	{
	case 0:
		DDRA_REG = PORTVALUE;
		break;
	case 1:
		DDRB_REG = PORTVALUE;
		break;
	case 2:
		DDRC_REG = PORTVALUE;
		break;
	case 3:
		DDRD_REG = PORTVALUE;
		break;
	}
}

/**
 * DIO_WriteChannel - used to set or clear the output PINS.
 * @PIN: the PIN name in this format (PORTA0, PORTA1, ..., PORTD7).
 * @BIT: either 1 or 0.
 *
 * Return: Void.
 */
void DIO_WriteChannel(uint8 PIN, uint8 BIT)
{

	if (PIN < 8)
	{
		switch (BIT)
		{
		case 0:
			Clr_Bit(DDRA_REG, PIN);
			break;
		case 1:
			Set_Bit(DDRA_REG, PIN);
			break;
		}
	}
	else if (PIN < 16)
	{
		PIN -= 8;
		switch (BIT)
				{
				case 0:
					Clr_Bit(DDRB_REG, PIN);
					break;
				case 1:
					Set_Bit(DDRB_REG, PIN);
					break;
				}
	}
	else if (PIN < 24)
	{
		PIN -= 16;
		switch (BIT)
				{
				case 0:
					Clr_Bit(DDRC_REG, PIN);
					break;
				case 1:
					Set_Bit(DDRC_REG, PIN);
					break;
				}
	}
	else
	{
		PIN -= 24;
		switch (BIT)
				{
				case 0:
					Clr_Bit(DDRD_REG, PIN);
					break;
				case 1:
					Set_Bit(DDRD_REG, PIN);
					break;
				}
	}

}

/**
 * DIO_ReadChannel - Read the bit in the specific port.
 * @PIN: the PIN name in this format (PORTA0, PORTA1, ..., PORTD7).
 *
 * Return: 1 if PIN is HIGH, 0 if PIN is LOW.
 */

uint8 DIO_ReadChannel(uint8 PIN)
{
	if (PIN < 8)
	{
		return (Read_Bit(DDRA_REG, PIN));
	}
	else if (PIN < 16)
	{
		PIN -= 8;
		return (Read_Bit(DDRB_REG, PIN));	}
	else if (PIN < 24)
	{
		PIN -= 16;
		return (Read_Bit(DDRC_REG, PIN));
	}
	else
	{
		PIN -= 24;
		return (Read_Bit(DDRD_REG, PIN));
	}

}
