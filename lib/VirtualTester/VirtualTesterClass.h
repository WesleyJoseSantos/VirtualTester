/**
 * @file VirtualTesterClass.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __VIRTUALTESTERCLASS__H__
#define __VIRTUALTESTERCLASS__H__

#include "Functions.h"
#include "ChannelSerial.h"

struct Hardware
{
    int pc;
    int64_t digitalPinsForced;
    int64_t digitalValues;
    int analogValues[32];
    uint8_t pwmValues[16];
};

class VirtualTesterClass
{
private:
    ChannelSerial defChannel;
    ChannelTester *channel;
    Hardware hardware;
    void processCmd();
    bool enable;
public:
    VirtualTesterClass();
    void begin();
    void task();
    void log(String text);
    void sendData(uint8_t *data, uint8_t len);
    void setChannel(ChannelTester channel);
    bool enabled();
    int getAnalogValue(uint8_t pin);
    uint64_t getDigitalValues();
    uint64_t getDigitalForced();
};

extern VirtualTesterClass VirtualTester;

#endif  //!__VIRTUALTESTERCLASS__H__