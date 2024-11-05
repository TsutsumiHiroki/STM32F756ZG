#pragma once
#include <Arduino.h>

class Output
{
    bool _isHigh = false;
    bool _testIsHigh = false;

    void updateOutput();

public:
    Output(uint8_t pinNumber);

    void on();

    void off();

    void toggle();

    void blink();

    void set(bool isHigh);

    bool isHigh();

    void setTestOn();
    void setTestOff();

private:
    uint8_t _pinNumber;
};