#include "Relays.h"

Relay::Relay(int PinNumber, bool SetPol)
{
    pin = PinNumber;
    pol = SetPol;
    wiringPiSetup () ;
    pinMode (pin, OUTPUT) ;
}

Relay::~Relay()
{

}

void Relay::on()
{
    swtch = true;
    if (pol)
    {digitalWrite (pin, LOW);}
    else
    {digitalWrite (pin, HIGH);}
}

void Relay::off()
{
    swtch = false;
    if (pol)
    {digitalWrite (pin, HIGH);}
    else
    {digitalWrite (pin, LOW);}
}

bool Relay::SWstate()
{
    return swtch;
}

bool Relay::POLstate()
{
    return pol;
}


void Relay::polarity(bool SetPol)
{
    pol = SetPol;      // false - normal, true - inversed
    if(pol)
    {
        if(swtch)
        {digitalWrite(pin, LOW);}
        else
        {digitalWrite(pin, HIGH);}
    }
    else
    {
        if(swtch)
        {digitalWrite(pin, HIGH);}
        else
        {digitalWrite(pin, LOW);}
    }
}