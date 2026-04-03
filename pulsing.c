/*
 * pulsing.c
 *
 *  Created on: Apr 2, 2026
 *      Author: andjelko
 */

#include "pulsing.h"

void pinPulsing(uint8_t port, uint8_t pin, uint8_t brPulsiranja, uint32_t period)
{
	for (uint8_t i = 0; i < brPulsiranja; i++)
		pinPulse(port, pin, period);
}

void pinPulse(uint8_t port, uint8_t pin, uint32_t period)
{
	pinSetValue(port, pin, HIGH);
	timer0DelayMs(calculateHalfPeriod(period));
	pinSetValue(port, pin, LOW);
	timer0DelayMs(calculateHalfPeriod(period));
}



