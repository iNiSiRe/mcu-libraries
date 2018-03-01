#include "IRSensor.h"

IRSensor::IRSensor(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

int IRSensor::getSignal()
{
    return analogRead(this->pin);
}
