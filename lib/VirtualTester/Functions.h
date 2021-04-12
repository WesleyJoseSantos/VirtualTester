/**
 * @file Functions.h
 * @author Wesley José Santos
 * @brief 
 * @version 0.1
 * @date 2021-04-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __FUNCTIONS__H__
#define __FUNCTIONS__H__

#include "VirtualTesterClass.h"
#include "DataFormat.h"
#include "Arduino.h"

void pinModeFunction(uint8_t pin, uint8_t mode);
int  digitalReadFunction(uint8_t pin);
void digitalWriteFunction(uint8_t pin, uint8_t val);
int  analogReadFunction(uint8_t pin);
void analogWriteFunction(uint8_t pin, uint8_t val);
void delayFunction(unsigned long ms);

#endif  //!__FUNCTIONS__H__