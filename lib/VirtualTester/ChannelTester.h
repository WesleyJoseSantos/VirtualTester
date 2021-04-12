/**
 * @file ChannelTester.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __CHANNELTESTER__H__
#define __CHANNELTESTER__H__

#include "Arduino.h"
#include "DataFormat.h"

class ChannelTester
{
private:
    
public:
    ChannelTester();
    virtual void begin();
    virtual void log(String text);
    virtual void sendData(uint8_t *data, uint8_t len);
    virtual int dataAvailable();
    virtual int getData(uint8_t *data);
};

#endif  //!__CHANNELTESTER__H__