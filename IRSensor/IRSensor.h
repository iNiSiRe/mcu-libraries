//
// Created by user18 on 20.02.18.
//

#ifndef MCU_LIBRARIES_IRSENSOR_H
#define MCU_LIBRARIES_IRSENSOR_H

#include <Arduino.h>
//#include <cstdint>

class IRSensor {

private:
    uint8_t pin;

public:
    IRSensor(uint8_t pin);

    int getSignal();
};


#endif //MCU_LIBRARIES_IRSENSOR_H
