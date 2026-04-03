/**
 * @file pulsing.c - file containing declarations of
 * functions for led blink
 * @author Aleksandar Andjelkovic
 * @time 03-04-2026 10:20
 */

#ifndef PULSING_H_
#define PULSING_H_

#include "timer0.h"
#include "utils.h"
#include "pin.h"
#include <stdint.h>

#define FAST 200
#define SLOW 1000

#define FAST_REPS 15
#define SLOW_REPS 3

void pinPulsing(uint8_t port, uint8_t pin, uint8_t brPulsiranja, uint32_t period);
void pinPulse(uint8_t port, uint8_t pin, uint32_t period);

#endif /* PULSING_H_ */
