/**
 * @file DataFormat.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __DATAFORMAT__H__
#define __DATAFORMAT__H__

#define MAX_SIZE 10

#define DATA_PIN 1
#define DATA_VALUE_BYTE1 2
#define DATA_VALUE_BYTE2 3

enum Functions {
    RESET_PC,
    PIN_MODE,
    DIGITAL_READ,
    DIGITAL_WRITE,
    ANALOG_READ,
    ANALOG_WRITE,
    DELAY,
    FORCE_DIGITAL,
    FORCE_ANALOG,
    FORCE_PWM,
    LOG_TEXT,
    END_DATA,
};

#endif  //!__DATAFORMAT__H__