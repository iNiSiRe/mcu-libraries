#include "IRSensor.h"
#include "../Platform.h"

using namespace inisire_mcu_libraries;

IRSensor::IRSensor(int pin)
{
    this->pin = pin;
    platform->setPinMode(pin, Platform::INPUT);
}

int IRSensor::getSignal()
{
    return platform->analogRead(this->pin);
}
