/**
 * rand_mto.h - file containing declaration of functions for one-to-many random
 * 				number generation(Galois configuration)
 * @author Aleksandar Andjelkovic
 * @time 03-04-2026 18:03
 */

#ifndef RAND_OTM_H_
#define RAND_OTM_H_

#include "logic_utils.h"

#define LEFT_DIR 0
#define RIGHT_DIR 1

/**
 * InitRand - set seed for random number generation
 * @param seed - starting number of the generator
 * @return none
 */
void InitRand(uint16_t seed);

/**
 * SetDiretcion - function that sets direction of LFSR Galois generator
 * @param dir - direction indicator
 * @return none
 */
void SetDirection(uint8_t dir);

/**
 * Rand - function that generates random number
 * @return generated number
 */
uint16_t Rand();

/**
 * RandRange - function generating random number from min to max range
 * @param min - minimal value that can be generated
 * @param max - maximal value that can be generated
 * @return generated number
 */
uint16_t RandRange(uint16_t min, uint16_t max);

/**
 * GetMSB - function that retrieves current MSB value
 * @param state - current generator state
 * @return MSB of current state
 */
uint8_t GetMSB(uint16_t state);

/**
 * ShiftAndToggle - function that updates current LFSR state
 * @param - current state of LFSR
 * @param - MSB that is going to be used for generating new state
 * @return new LFSR state
 */
uint16_t ShiftAndToggle(uint16_t state, uint8_t bit);

#endif /* RAND_OTM_H_ */
