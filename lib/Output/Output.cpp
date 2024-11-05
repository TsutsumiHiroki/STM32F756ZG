#include <Output.hpp>

void Output::updateOutput()
{
    digitalWrite(_pinNumber, _isHigh || _testIsHigh);
}

Output::Output(uint8_t pinNumber)
{
    _pinNumber = pinNumber;
    pinMode(_pinNumber, OUTPUT);
}

void Output::on()
{
    _isHigh = true;
    updateOutput();
}

void Output::off()
{
    _isHigh = false;
    updateOutput();
}

void Output::toggle()
{
    _isHigh != _isHigh;
    updateOutput();
}

void Output::blink()
{
}

void Output::set(bool isHigh)
{
    _isHigh = isHigh;
    updateOutput();
}

bool Output::isHigh()
{
    return _isHigh;
}

void Output::setTestOn()
{
    _testIsHigh = true;
    updateOutput();
}

void Output::setTestOff()
{
    _testIsHigh = false;
    updateOutput();
}