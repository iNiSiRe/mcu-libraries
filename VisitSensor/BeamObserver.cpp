#include "BeamObserver.h"

BeamObserver::BeamObserver(Beam beam) : beam(beam) {

}

void BeamObserver::update()
{
    bool open = beam.isOpen();
    state.changed = open != state.open;
    state.open = open;
}

BeamState BeamObserver::getState() {
    return state;
}
