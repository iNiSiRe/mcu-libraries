#ifndef MCU_LIBRARIES_BEAMINTERSECTIONDETECTOR_H
#define MCU_LIBRARIES_BEAMINTERSECTIONDETECTOR_H

#include <Arduino.h>
#include <IRSensor.h>

class Beam {

private:
    IRSensor sensor;

    int threshold = 200;
    bool open = true;

public:

    Beam(IRSensor sensor) : sensor(sensor)
    {

    }

    bool isOpen()
    {
        open = sensor.getSignal() > threshold;

        return open;
    }
};

#endif //MCU_LIBRARIES_BEAMINTERSECTIONDETECTOR_H
