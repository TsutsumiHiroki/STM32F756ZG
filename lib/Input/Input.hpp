#pragma once
#include <Arduino.h>

class Input
{
public:
    Input(uint8_t pinNumber, bool hasExternalPullup);

    bool isHigh();

private:
    uint8_t _pinNumber;
    bool _hasExternalPullup;
};