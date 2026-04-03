/**
 *	adc_utils.h - file containing declarations of functions for setup and work with adc
 *	@author Aleksandar Andjelkovic
 *	@time 03-04-2026 11:26
 */

#include "adc_utils.h"

/********************************************************/

void InitADC(uint8_t reference, uint8_t division_factor)
{
	/// Set ref. voltage
	SetVref(reference);

	/// Set pre-scaler
	SetPrescaler(division_factor);

	/// Set enable
	SetEnable(ENABLE_ADC);

	ADCSRA = ClearBit(ADCSRA, ADFR); /// ADFR -> 0 => single conversion mode
}

/********************************************************/

uint16_t ReadADC(uint8_t channel)
{
	SetChannel(channel); /// Set ADC input channel

	RunConversion();

	ADMUX = ClearBit(ADMUX, ADLAR); /// Disable shorter conversion format

	return ADC;

}

/********************************************************/

void SetVref(uint8_t reference)
{
	switch (reference)
		{
			case AREF:
				ADMUX = ClearBit(ADMUX, REFS1);
				ADMUX = ClearBit(ADMUX, REFS0);
				break;
			case AVCC:
				ADMUX = ClearBit(ADMUX, REFS1);
				ADMUX = SetBit(ADMUX, REFS0);
				break;
			default: /// Default reference is INTER_VREF - 2.56V
				ADMUX = SetBit(ADMUX, REFS1);
				ADMUX = SetBit(ADMUX, REFS0);
				break;
		}
}

/********************************************************/

void SetPrescaler(uint8_t division_factor)
{
	switch (division_factor)
		{
			case 2:	/// Pre-scaler 2
				ADCSRA = ClearBit(ADCSRA, ADPS2);
				ADCSRA = ClearBit(ADCSRA, ADPS1);
				ADCSRA = SetBit(ADCSRA, ADPS0);
				break;
			case 4: /// Pre-scaler 4
				ADCSRA = ClearBit(ADCSRA, ADPS2);
				ADCSRA = SetBit(ADCSRA, ADPS1);
				ADCSRA = ClearBit(ADCSRA, ADPS0);
				break;
			case 8: /// Pre-scaler 8
				ADCSRA = ClearBit(ADCSRA, ADPS2);
				ADCSRA = SetBit(ADCSRA, ADPS1);
				ADCSRA = SetBit(ADCSRA, ADPS0);
				break;
			case 16: /// Pre-scaler 16
				ADCSRA = SetBit(ADCSRA, ADPS2);
				ADCSRA = ClearBit(ADCSRA, ADPS1);
				ADCSRA = ClearBit(ADCSRA, ADPS0);
				break;
			case 32: /// Pre-scaler 32
				ADCSRA = SetBit(ADCSRA, ADPS2);
				ADCSRA = ClearBit(ADCSRA, ADPS1);
				ADCSRA = SetBit(ADCSRA, ADPS0);
				break;
			case 64: /// Pre-scaler 64
				ADCSRA = SetBit(ADCSRA, ADPS2);
				ADCSRA = SetBit(ADCSRA, ADPS1);
				ADCSRA = ClearBit(ADCSRA, ADPS0);
				break;
			case 128: /// Pre-scaler 128
				ADCSRA = SetBit(ADCSRA, ADPS2);
				ADCSRA = SetBit(ADCSRA, ADPS1);
				ADCSRA = SetBit(ADCSRA, ADPS0);
				break;
			default:	/// Also 2 pre-scaler factor by default
				ADCSRA = ClearBit(ADCSRA, ADPS2);
				ADCSRA = ClearBit(ADCSRA, ADPS1);
				ADCSRA = ClearBit(ADCSRA, ADPS0);
				break;
		}
}

/********************************************************/

void SetEnable(uint8_t enable)
{
	if (enable != 0)
		ADCSRA = SetBit(ADCSRA, ADEN); /// Enable ADC
	else
		ADCSRA = ClearBit(ADCSRA, ADEN); /// Enable ADC
}

/********************************************************/

void SetChannel(uint8_t channel)
{
	switch (channel)
	{
		case ADC1:
			ADMUX = BitmaskSet(ADMUX, ADC1);
			break;
		case ADC2:
			ADMUX = BitmaskSet(ADMUX, ADC2);
			break;
		case ADC3:
			ADMUX = BitmaskSet(ADMUX, ADC3);
			break;
		case ADC4:
			ADMUX = BitmaskSet(ADMUX, ADC4);
			break;
		case ADC5:
			ADMUX = BitmaskSet(ADMUX, ADC5);
			break;
		case ADC6:
			ADMUX = BitmaskSet(ADMUX, ADC6);
			break;
		case ADC7:
			ADMUX = BitmaskSet(ADMUX, ADC7);
			break;
		case ADC8:
			ADMUX = BitmaskSet(ADMUX, ADC8);
			break;
		default: /// ADC0 channel set as default
			ADMUX = BitmaskSet(ADMUX, ADC0);
			break;
	}
}

/********************************************************/

void RunConversion()
{
	ADCSRA = SetBit(ADCSRA, ADSC);

	while (CheckBit(ADCSRA, ADSC)); /// Wait for the conversion to end
}

/********************************************************/
