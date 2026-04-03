/**
 * main.c - file containing main function and usage of functions included in headers
 * @author Aleksandar Andjelkovic
 * @time 03-04-2026 10:20
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "timer0.h"
#include "pin.h"
#include "pulsing.h"
#include "logic_utils.h"
#include "adc_utils.h"
#include "rand_otm.h"

/**
 * main - function that implements random number generation based on seed from ADC
 * 		  making diode blink generated number of times
 * @return 0
 */
int16_t main()
{
	pinInit(PORT_B, DIODE_PIN, OUTPUT);
	InitADC(AVCC, 128);
	timer0InteruptInit();

	BitmaskClear(ADMUX, CHANNEL_CLEAR);
	InitRand(ReadADC(ADC3));
	SetDirection(LEFT_DIR);

	uint16_t pulse_number = 0;
	while (1)
	{
		pulse_number = RandRange(2, 9);
		pinPulsing(PORT_B, DIODE_PIN, pulse_number, 600);

		timer0DelayMs(2000);
	};

	return 0;
}


