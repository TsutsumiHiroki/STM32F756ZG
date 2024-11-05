#include <Input.hpp>

Input::Input(uint8_t pinNumber, bool hasExternalPullup)
{
    _pinNumber = pinNumber;
    pinMode(_pinNumber, INPUT);
    _hasExternalPullup = hasExternalPullup;
}

bool Input::isHigh()
{
    return digitalRead(_pinNumber) == (_hasExternalPullup ? LOW : HIGH);
}