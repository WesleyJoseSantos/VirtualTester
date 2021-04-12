/**
 * @file ChannelSerial.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ChannelSerial.h"

ChannelSerial::ChannelSerial(){

}

void ChannelSerial::begin(){
    Serial.begin(9600);
}

void ChannelSerial::log(String text){
    #ifndef  ENABLE_DEBUG
    uint8_t data[] = {LOG_TEXT};
    Serial.print(text);
    #else
    Serial.println(text);
    #endif  //ENABLE_DEBUG
    #ifndef  ENABLE_DEBUG
    data[0] = END_DATA;
    #endif  //ENABLE_DEBUG
}

void ChannelSerial::sendData(uint8_t *data, uint8_t len){
    #ifdef  ENABLE_DEBUG
    for (size_t i = 0; i < len; i++)
    {
        Serial.print(data[i]);
        Serial.print(" ");
    }
    Serial.println(END_DATA);
    #else
    Serial.write(data, len);
    Serial.write(END_DATA);
    #endif  //ENABLE_DEBUG
}

int ChannelSerial::dataAvailable(){
    return Serial.available();
}

int ChannelSerial::getData(uint8_t *data){
    return Serial.readBytesUntil(END_DATA, data, MAX_SIZE);
}