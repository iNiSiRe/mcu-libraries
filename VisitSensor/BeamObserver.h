//
// Created by user18 on 01.03.18.
//

#ifndef MCU_LIBRARIES_BEAMSTATE_H
#define MCU_LIBRARIES_BEAMSTATE_H

#include "Beam.h"

struct BeamState {
    bool open;
    bool changed;
};

class BeamObserver
{

private:
    Beam beam;
    BeamState state;

    void update();

public:
    BeamObserver(Beam beam);
    BeamState getState();
};


#endif //MCU_LIBRARIES_BEAMSTATE_H
