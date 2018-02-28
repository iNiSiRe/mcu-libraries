#include "IRSensor.h"

IRSensor::IRSensor(uint8_t pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

int IRSensor::getSignal()
{
    return analogRead(this->pin);
}
