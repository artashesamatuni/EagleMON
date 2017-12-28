#ifndef RELAY_H
#define RELAY_H

#ifdef __cplusplus
extern "C" {
#endif

#pragma once

#include <wiringPi.h>
    
class Relay
{
    public:
        Relay(int PinNumber); //default constructor
        virtual ~Relay(); //default virtual destructor
        bool on();
        bool off();
        bool state();
        bool pol();
        
    private:
        int pin;
        bool pol;
};


#ifdef __cplusplus
}
#endif

#endif /* RELAY_H */

