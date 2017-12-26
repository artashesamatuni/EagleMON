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
		Relay(); //default constuctor
		virtual ~Relay(); //default virtual destructor
		void on();
		void off();
		
	private:
		int pin;
};


#ifdef __cplusplus
}
#endif

#endif /* RELAY_H */

