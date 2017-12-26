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

void Relay::on()
{
	digitalWrite (pin, HIGH);
}

void Relay::off()
{
	digitalWrite (pin, LOW);
}