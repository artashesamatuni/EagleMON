#ifndef DIGITAL_INPUT_H
#define DIGITAL_INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#pragma once

#include <wiringPi.h>

class digital_input {
public:
    digital_input(int PinNumber, int Pull);
    bool read();
    virtual ~digital_input();
private:
    int pin;

};

#ifdef __cplusplus
}
#endif

#endif /* DIGITAL_INPUT_H */

