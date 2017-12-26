#include "Relays.h"

Relay::Relay()
{
	pin = 0;
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