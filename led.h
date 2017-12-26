#ifndef LED_H
#define LED_H

#ifdef __cplusplus
extern "C" {
#endif

#pragma once

#include <wiringPi.h>
    
class Led
{
	public:
		Led(); //default constuctor
		virtual ~Led(); //default virtual destructor
		void on();
		void off();
		
	private:
		int pin;
};


#ifdef __cplusplus
}
#endif

#endif /* LED_H */

