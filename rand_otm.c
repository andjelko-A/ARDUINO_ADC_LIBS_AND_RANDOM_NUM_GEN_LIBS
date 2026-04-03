/**
 * rand_mto.c - file containing definitions of functions for one-to-many random
 * 				number generation(Galois configuration)
 * @author Aleksandar Andjelkovic
 * @time 03-04-2026 18:09
 */

#include "rand_otm.h"

/// State of the linear feedback shift register type
typedef struct LFSR_STATE
{
	uint16_t state_value;
	uint8_t direction;
} lfsr_state_t;

/// Actual structure representing LFSR state
volatile lfsr_state_t current_lfsr_state =
{
		.state_value = 0,
		.direction = RIGHT_DIR	/// Default direction
};

/*****************************************/

void InitRand(uint16_t seed)
{
	current_lfsr_state.state_value = seed;
}

/*****************************************/

void SetDirection(uint8_t dir) /// Does not include wrong input protection
{
	current_lfsr_state.direction = dir;
}

/*****************************************/

uint16_t Rand()
{
	uint8_t new_bit = GetMSB(current_lfsr_state.state_value);

	current_lfsr_state.state_value = ShiftAndToggle(
			current_lfsr_state.state_value, new_bit);

	return current_lfsr_state.state_value;
}

/*****************************************/

uint16_t RandRange(uint16_t min, uint16_t max)
{
	return (Rand() % (max - min)) + min;
}

/*****************************************/

uint8_t GetMSB(uint16_t state)
{
	if (current_lfsr_state.direction == RIGHT_DIR)
		return CheckBit(state, B0);
	else
		return CheckBit(state, B15);
}

/*****************************************/

uint16_t ShiftAndToggle(uint16_t state, uint8_t bit)
{
	if (current_lfsr_state.direction == RIGHT_DIR)
	{
		state = ShiftRight(state, 1);
		state = Or(state, ShiftLeft(((uint16_t) bit), B15));
		state = Xor(state, ShiftLeft(((uint16_t) bit), B13));
		state = Xor(state, ShiftLeft(((uint16_t) bit), B12));
		state = Xor(state, ShiftLeft(((uint16_t) bit), B10));
	}
	else
	{
		state = ShiftLeft(state, 1);
		state = Or(state, ShiftLeft(((uint16_t) bit), B0));
		state = Xor(state, ShiftLeft(((uint16_t) bit), B2));
		state = Xor(state, ShiftLeft(((uint16_t) bit), B3));
		state = Xor(state, ShiftLeft(((uint16_t) bit), B5));
	}

	return state;
}

/*****************************************/
