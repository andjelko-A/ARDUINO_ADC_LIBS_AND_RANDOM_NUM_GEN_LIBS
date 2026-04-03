/**
 *	adc_utils.h - file containing declarations of functions for setup and work with adc
 *	@author Aleksandar Andjelkovic
 *	@time 03-04-2026 11:26
 */

#ifndef ADC_UTILS_H_
#define ADC_UTILS_H_

#include <avr/io.h>
#include <stdint.h>
/// Bit logical operations
#include "logic_utils.h"

/// Macros for enabling and disabling ADC
#define ENABLE_ADC 1
#define DISABLE_ADC 0

/// Reference voltage bits in ADMUX register
#define REFS1 7
#define REFS0 6

/// Chennel bits clear mask for ADMUX
#define CHANNEL_CLEAR 0x1F

/// Left align bit in ADMUX register
#define ADLAR 5

/// ADC enable bit in ADCSRA register
#define ADEN 7

/// ADC start conversion bit in ADCSRA register
#define ADSC 6

/// ADC free-running mode bit in ADCSRA register
#define ADFR 5

/// Pres-scaler set bits in ADCSRA register
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

/// Type for possible reference voltage sources for adc
typedef enum REF_VOLTAGE {AREF, AVCC, INTER_VREF} ref_voltage_t;

typedef enum INPUT_CHANNEL {ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7, ADC8} adc_channel_t;

/**
 * InitADC - function for initialization of ADC
 * @param reference - used reference voltage for adc
 * @param division_factor - used for setting frequency pre-scaler
 * @return none
 */
void InitADC(uint8_t reference, uint8_t division_factor);

/**
 * ReadADC - function for reading ADC conversion value
 * @param channel - input channel to read value from
 * @return read conversion value
 */
uint16_t ReadADC(uint8_t channel);

/**
 * SetVref - function for setting adc reference voltage
 * @param reference - value
 * @return none
 */
void SetVref(uint8_t reference);

/**
 * SetPrescaler - function for setting adc frequency pre-scaler
 * @param division_factor - pre_scaler value
 * @return none
 */
void SetPrescaler(uint8_t division_factor);

/**
 *	SetEnable - set adc enable bit
 *	@param enable - value to be set
 *	@return none
 */
void SetEnable(uint8_t enable);

/**
 *	SetChannel - set adc channel to read from
 *	@param channel - number of desired input channel
 *	@return none
 */
void SetChannel(uint8_t channel);

/**
 *	RunConversion - function that implements process of conversion
 *	@return none
 */
void RunConversion();

#endif /* ADC_UTILS_H_ */
