/**
 * rand_mto.c - file containing definitions of functions for many-to-one random
 * 				number generation
 * @author Aleksandar Andjelkovic
 * @time 03-04-2026 17:24
 */

#include "rand_mto.h"

/// State of the linear feedback shift register
volatile uint16_t current_lfsr_state = 0;

/*****************************************************/

void InitRand(uint16_t seed)
{
	current_lfsr_state = seed;
}

/*****************************************************/

uint16_t Rand()
{
	uint8_t new_bit = GenerateNextBit(current_lfsr_state);

	current_lfsr_state = UpdateState(current_lfsr_state, new_bit);

	return current_lfsr_state;
}

/*****************************************************/

uint16_t RandRange(uint16_t min, uint16_t max)
{
	return (Rand() % (max - min)) + min;
}

/*****************************************************/

uint8_t GenerateNextBit(uint16_t current_state)
{
	uint8_t b0 = CheckBit(current_state, B0);
	uint8_t b2 = CheckBit(current_state, B2);
	uint8_t b3 = CheckBit(current_state, B3);
	uint8_t b5 = CheckBit(current_state, B5);

	return (Xor(b5, Xor(b3, Xor(b2, b0))));
}

/*****************************************************/

uint16_t UpdateState(uint16_t state, uint8_t bit)
{
	return (ShiftRight(state, 1) | ShiftRight((uint16_t) bit, B15));
}

/*****************************************************/












