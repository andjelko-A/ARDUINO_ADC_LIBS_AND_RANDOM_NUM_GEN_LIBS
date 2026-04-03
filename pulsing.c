/**
 * @file pulsing.c - file containing definitions of
 * functions for led blink
 * @author Aleksandar Andjelkovic
 * @time 03-04-2026 10:20
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



