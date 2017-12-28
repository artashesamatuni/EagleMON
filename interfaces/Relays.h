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
        Relay(int PinNumber, bool SetPol); // default constructor
        virtual ~Relay();                   // default virtual destructor
        void on();                          // Switch Relay On
        void off();                         // Switch Relay Off
        bool SWstate();                     // Returns relay switching state
        bool POLstate();                    // Returns relay Polarity state
        void polarity(bool SetPol);
        
    private:
        int pin;                            // Physical pin
        bool pol;                           // Polarity flag
        bool swtch;                         // Switching flag
};


#ifdef __cplusplus
}
#endif

#endif /* RELAY_H */

