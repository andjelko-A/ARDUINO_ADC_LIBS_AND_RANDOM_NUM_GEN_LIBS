/*
 * utils.h
 *
 *  Created on: Apr 2, 2026
 *      Author: andjelko
 */

#ifndef UTILS_H_
#define UTILS_H_

#include "timer0.h"
#include <stdint.h>

/**
 * @name calculateHalfPeriod
 * @brief calculated half-period of argument
 * @return calculated half-period
 */
uint32_t calculateHalfPeriod(uint32_t period);

#endif /* UTILS_H_ */
