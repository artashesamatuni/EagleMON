#include "digital_input.h"

digital_input::digital_input(int PinNumber, int Pull)
{
    pin = PinNumber;
    wiringPiSetup () ;
    pinMode (pin, INPUT) ;
    
    if (Pull < 0)
    {
        pullUpDnControl (pin, PUD_DOWN);
    }
    else if (Pull > 0)
    {
        pullUpDnControl (pin, PUD_UP);
    }
    else
    {
        pullUpDnControl (pin, PUD_OFF);
    }
    
}

digital_input::~digital_input()
{
}

bool digital_input::read()
{
    return digitalRead(pin);
}



