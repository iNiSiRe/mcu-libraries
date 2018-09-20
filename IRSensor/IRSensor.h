//
// Created by user18 on 20.02.18.
//

#ifndef MCU_LIBRARIES_IRSENSOR_H
#define MCU_LIBRARIES_IRSENSOR_H

#include <Platform.h>

class IRSensor {

private:
    int pin;

public:
    IRSensor(int pin);

    int getSignal();
};


#endif //MCU_LIBRARIES_IRSENSOR_H
