/**
 * @file VirtualTesterClass.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "VirtualTesterClass.h"

VirtualTesterClass::VirtualTesterClass(){
    for (size_t i = 0; i < 32; i++)
    {
        this->hardware.analogValues[i] = -1;
    }
}

void VirtualTesterClass::begin(){
    this->channel = &defChannel;
    this->channel->begin();
    this->enable = true;
}

void VirtualTesterClass::task(){
    uint8_t data[] = {RESET_PC};
    hardware.pc = 0;
    this->channel->sendData(data, 1);
    this->processCmd();
}

void VirtualTesterClass::log(String text){
    this->channel->log(text);
}

void VirtualTesterClass::processCmd(){
    if (this->channel->dataAvailable())
    {
        uint8_t *data;
        switch (data[0])
        {
        case FORCE_DIGITAL:
        {
            int pin = data[DATA_PIN];
            int value = data[DATA_VALUE_BYTE1];
            bitSet(this->hardware.digitalPinsForced, pin);
            bitSet(this->hardware.digitalValues, value);
            break;
        }
        case FORCE_ANALOG:
        {
            int idx = A0 - data[DATA_PIN];
            int val = lowByte(data[DATA_VALUE_BYTE1]);
                val += highByte(data[DATA_VALUE_BYTE2]);
            this->hardware.analogValues[idx] = val;
            break;
        }
        case FORCE_PWM:
        {
            int pin = data[DATA_PIN];
            int value = data[DATA_VALUE_BYTE1];
            this->hardware.pwmValues[pin] = value; 
            break;
        }
        default:
            break;
        }
    }
}

void VirtualTesterClass::sendData(uint8_t *data, uint8_t len){
    hardware.pc++;
    this->channel->sendData(data, len);
}

void VirtualTesterClass::setChannel(ChannelTester channel){
    this->channel = &channel;
}

bool VirtualTesterClass::enabled(){
    return this->enable;
}

int VirtualTesterClass::getAnalogValue(uint8_t pin){
    int idx = A0 - pin;
    return this->hardware.analogValues[idx];
}

uint64_t VirtualTesterClass::getDigitalValues(){
    return this->hardware.digitalValues;
}

uint64_t VirtualTesterClass::getDigitalForced(){
    return this->hardware.digitalPinsForced;
}

VirtualTesterClass VirtualTester;