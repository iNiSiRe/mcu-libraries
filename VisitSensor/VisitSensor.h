#ifndef MCU_LIBRARIES_BEAMINTERSECTIONSENSOR_H
#define MCU_LIBRARIES_BEAMINTERSECTIONSENSOR_H

#include "Beam.h"
#include "BeamObserver.h"

enum Direction {
    NONE = 0,
    IN = 1,
    OUT
};

class VisitSensor
{

private:

    unsigned long changedAt = 0;
    int resetTime = 1000;

    enum State {
        BEGIN = 0,
        L1,
        R1,
        L0,
        R0
    };

    State state = BEGIN;
    Direction direction = NONE;

    BeamObserver beam1, beam2;

    void setState(State state);
    void intersection(int beam, int value);

public:

    bool debug = false;
//    std::function<void(int)> callback;

    Direction detectedDirection = NONE;

    VisitSensor(int leftPin, int rightPin, int resetTime = 1000) :
            beam1(BeamObserver(Beam(IRSensor(leftPin)))),
            beam2(BeamObserver(Beam(IRSensor(rightPin)))),
            resetTime(resetTime)
    {
        
    }

    void loop();
};


#endif //MCU_LIBRARIES_BEAMINTERSECTIONSENSOR_H
