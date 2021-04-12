/**
 * @file ChannelSerial.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __CHANNELSERIAL__H__
#define __CHANNELSERIAL__H__

#include "ChannelTester.h"
#include "Arduino.h"

#define ENABLE_DEBUG

class ChannelSerial : public ChannelTester
{
private:
    
public:
    ChannelSerial();
    void begin() override;
    void log(String text) override;
    void sendData(uint8_t *data, uint8_t len) override;
    int dataAvailable() override;
    int getData(uint8_t *data) override;
};

#endif  //!__CHANNELSERIAL__H__