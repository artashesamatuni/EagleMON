#include "Relays.h"

Relay::Relay(int PinNumber)
{
    pin = PinNumber;
    wiringPiSetup () ;
    pinMode (pin, OUTPUT) ;
}

Relay::~Relay()
{

}

bool Relay::on()
{
    digitalWrite (pin, HIGH);
    return true;
}

bool Relay::off()
{
    digitalWrite (pin, LOW);
    return false;
}

bool Relay::pol(bool pol)
{

}

bool Relay::state()
{
    return digitalRead(pin);
}