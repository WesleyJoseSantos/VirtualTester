/**
 * @file Functions.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "VirtualTesterClass.h"
#include "Functions.h"

void pinModeFunction(uint8_t pin, uint8_t mode){
    pinMode(pin, mode);
    if (VirtualTester.enabled())
    {
        uint8_t data[] = { PIN_MODE, pin, mode };
        VirtualTester.sendData(data, 3);
    }
}

int digitalReadFunction(uint8_t pin){
    if (VirtualTester.enabled())
    {
        int forced = VirtualTester.getDigitalForced();
        int value;
        if(bitRead(forced, pin)){
            value = VirtualTester.getDigitalValues();
        }else{
            value = digitalRead(pin);
        }
        uint8_t data[] = { DIGITAL_READ, pin, lowByte(value)};
        VirtualTester.sendData(data, 3);
    }
    return digitalRead(pin);
}

void digitalWriteFunction(uint8_t pin, uint8_t val){
    digitalWrite(pin, val);
    if (VirtualTester.enabled())
    {
        uint8_t data[] = { DIGITAL_WRITE, pin, val };
        VirtualTester.sendData(data, 3);
    }
}

int analogReadFunction(uint8_t pin){
    if (VirtualTester.enabled())
    {
        int value = VirtualTester.getAnalogValue(pin);
        if(value == -1){
            value = analogRead(pin);
        }
        uint8_t b1 = lowByte(value);
        uint8_t b2 = highByte(value);
        uint8_t data[] = { ANALOG_READ, pin, b1, b2};
        VirtualTester.sendData(data, 4);
    }
    return analogRead(pin);
}

#ifndef ESP32
void analogWriteFunction(uint8_t pin, uint8_t val){
    analogWrite(pin, val);
    if (VirtualTester.enabled())
    {
        uint8_t data[] = { DIGITAL_WRITE, pin };
        VirtualTester.sendData(data, 2);
    }
}
#endif

void delayFunction(unsigned long ms){
    delay(ms);
    if (VirtualTester.enabled())
    {
        uint8_t b1 = ms;
        uint8_t b2 = ms >> 8;
        uint8_t b3 = ms >> 16;
        uint8_t b4 = ms >> 24;
        uint8_t data[] = { DELAY, b1, b2, b3, b4 };
        VirtualTester.sendData(data, 5);;
    }
}