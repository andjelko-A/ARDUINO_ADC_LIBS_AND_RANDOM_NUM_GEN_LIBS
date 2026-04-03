/**
 * logic_utils.c - file containing definitions of functions for bit logical operations
 * @author Aleksandar Andjelkovic
 * @time 03-04-2026 10:36
 */

#include "logic_utils.h"

/******************************************************************/

uint16_t SetBit(uint16_t reg, uint8_t bit_num)
{
	return (reg | (1 << bit_num));
}

/******************************************************************/

uint16_t ClearBit(uint16_t reg, uint8_t bit_num)
{
	return (reg & (~(1 << bit_num)));
}

/******************************************************************/

uint16_t ToggleBit(uint16_t reg, uint8_t bit_num)
{
	return (reg ^ (1 << bit_num));
}

/******************************************************************/

uint16_t CheckBit(uint16_t reg, uint8_t bit_num)
{
	if ((reg & (1 << bit_num)) == 0)
		return 0;
	else
		return 1;

}

/******************************************************************/

uint16_t BitmaskSet(uint16_t reg, uint16_t mask)
{
	/// Bits to be set are set to 1 in mask
	return (reg | mask);
}

/******************************************************************/

uint16_t BitmaskClear(uint16_t reg, uint16_t mask)
{
	/// Bits to be cleared are set to 1 in mask
	return (reg & (~mask));
}

/******************************************************************/

uint16_t Not(uint16_t input)
{
	return ~input;
}

/******************************************************************/

uint16_t And(uint16_t input1, uint16_t input2)
{
	return input1 & input2;
}

/******************************************************************/

uint16_t Or(uint16_t input1, uint16_t input2)
{
	return input1 | input2;
}

/******************************************************************/

uint16_t Xor(uint16_t input1, uint16_t input2)
{
	return input1 ^ input2;
}

/******************************************************************/

uint16_t ShiftLeft(uint16_t input, uint16_t num_of_shifts)
{
	return (input << num_of_shifts);
}

/******************************************************************/

uint16_t ShiftRight(uint16_t input, uint16_t num_of_shifts)
{
	return (input >> num_of_shifts);
}

/******************************************************************/


