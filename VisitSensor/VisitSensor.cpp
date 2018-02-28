#include "VisitSensor.h"

void VisitSensor::intersection(int beam, int value)
{
    State newState;

    if (beam == 1 && value == HIGH) {
        newState = R1;
    } else if (beam == 1 && value == LOW) {
        newState = R0;
    } else if (beam == 2 && value == HIGH) {
        newState = L1;
    } else if (beam == 2 && value == LOW) {
        newState = L0;
    } else {
        newState = BEGIN;
    }

    if (debug) {
        Serial.print(this->state);
        Serial.print(" ? ");
        Serial.println(newState);
    }

    if (direction == NONE) {

        switch (newState) {
            case L1:

                if (state == BEGIN) {
                    this->setState(newState);
                    this->direction = IN;
                }

                break;

            case R1:

                if (state == BEGIN) {
                    this->setState(newState);
                    this->direction = OUT;
                }

                break;
        }

    } else if (direction == IN) {

        switch (newState) {
            case R1:

                if (state == L1) {
                    this->setState(newState);
                }

                break;

            case L0:

                if (state == R1) {
                    this->setState(newState);
                }
                break;

            case R0:

                if (state == L0) {
                    this->setState(newState);
//                    this->callback(1);
                    detectedDirection = IN;
                }
                break;
        }

    } else if (direction == OUT) {

        switch (newState) {
            case L1:

                if (state == R1) {
                    this->setState(newState);
                }

                break;

            case R0:

                if (state == L1) {
                    this->setState(newState);
                }

                break;

            case L0:

                if (state == R0) {
                    this->setState(newState);
//                    this->callback(2);
                    detectedDirection = OUT;
                }
                break;

        }

    }
}

void VisitSensor::setState(VisitSensor::State state)
{
    unsigned long current = millis();

    if (debug) {
        Serial.print(this->state);
        Serial.print(" -> ");
        Serial.print(state);
        Serial.print("|");
        Serial.println(current - changedAt);
    }

    this->state = state;
    this->changedAt = current;
}

void VisitSensor::loop()
{
    unsigned long current = millis();

    if (state == BEGIN) {
        return;
    }

    if (current - changedAt >= resetTime) {
        state = BEGIN;
        direction = NONE;
        detectedDirection = NONE;
        Serial.println("Reset");
        return;
    }

    BeamState state;

    state = beam1.getState();
    if (state.changed) {
        intersection(1, state.open);
    }

    state = beam2.getState();
    if (state.changed) {
        intersection(2, state.open);
    }
}
