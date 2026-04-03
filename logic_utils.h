/**
 * logic_utils.h - file containing declaration of functions for bit logical operations
 * @author Aleksandar Andjelkovic
 * @time 03-04-2026 10:20
 */

#ifndef LOGIC_UTILS_H_
#define LOGIC_UTILS_H_

#include <stdint.h>

/// Length in bits of a half-word
#define HW_LENGTH 16

/// Length in bits of a byte
#define B_LENGTH 8

/// Position of bits in a word
typedef enum bit_positons_t {B0, B1, B2, B3, B4, B5, B6, B7, B8, B9, B10,
							 B11, B12, B13, B14, B15} bit_positions_t;

/**
 * SetBit - set bit on position bit_num to 1
 * @param reg - half_word to be modified
 * @param bit_num - number of bit to be modified
 * @return modified reg value
 */
uint16_t SetBit(uint16_t reg, uint8_t bit_num);

/**
 * ClearBit - set bit on position bit_num to 0
 * @param reg - half_word to be modified
 * @param bit_num - number of bit to be modified
 * @return modified reg value
 */
uint16_t ClearBit(uint16_t reg, uint8_t bit_num);

/**
 * ToggleBit - invert bit on position bit_num
 * @param reg - half_word to be modified
 * @param bit_num - number of bit to be modified
 * @return modified reg value
 */
uint16_t ToggleBit(uint16_t reg, uint8_t bit_num);

/**
 * CheckBit - get bit value on position bit_num
 * @param reg - half_word to be check bit from
 * @param bit_num - number of bit to be checked
 * @return value of bit on bit_num
 */
uint16_t CheckBit(uint16_t reg, uint8_t bit_num);

/**
 * BitmaskSet - set bits in reg to 1, according to mask
 * @param reg - half_word to be check bit from
 * @param mask - collection of bits to be set
 * @return modified reg value
 */
uint16_t BitmaskSet(uint16_t reg, uint16_t mask);

/**
 * BitmaskClear - set bits in reg to 0, according to mask
 * @param reg - half_word to be check bit from
 * @param mask - collection of bits to be cleared
 * @return modified reg value
 */
uint16_t BitmaskClear(uint16_t reg, uint16_t mask);

/**
 * Not - invert bits in input
 * @param input - hald_word to be inverted
 * @return modified input value
 */
uint16_t Not(uint16_t input);

/**
 * And - and bit operation
 * @param input1 - operand 1 to be and-ed
 * @param input2 - operand 2 to be and-ed
 * @return and operation result
 */
uint16_t And(uint16_t input1, uint16_t input2);

/**
 * Or - or bit operation
 * @param input1 - operand 1 to be or-ed
 * @param input2 - operand 2 to be or-ed
 * @return or operation result
 */
uint16_t Or(uint16_t input1, uint16_t input2);

/**
 * Xor - or bit operation
 * @param input1 - operand 1 to be xor-ed
 * @param input2 - operand 2 to be xor-ed
 * @return xor operation result
 */
uint16_t Xor(uint16_t input1, uint16_t input2);

/**
 * ShiftLeft - shift bits in input for num_of_shifts to the left
 * @param input - input to be shifted
 * @param num_of_shifts - number of shift positions to the left
 * @return shifted input
 */
uint16_t ShiftLeft(uint16_t input, uint16_t num_of_shifts);

/**
 * ShiftRight - shift bits in input for num_of_shifts to the right
 * @param input - input to be shifted
 * @param num_of_shifts - number of shift positions to the right
 * @return shifted input
 */
uint16_t ShiftRight(uint16_t input, uint16_t num_of_shifts);

#endif /* LOGIC_UTILS_H_ */
