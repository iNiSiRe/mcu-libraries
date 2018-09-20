#ifndef FIRMWARE_ABSTRACTPLATFORM_H
#define FIRMWARE_ABSTRACTPLATFORM_H

namespace inisire_mcu_libraries {

    class Platform {

    public:

        enum PinState {
            HIGH = 1,
            LOW = 0
        };

        enum PinMode {
            INPUT = 1;
            OUTPUT = 2;
        };

        virtual void setPinMode(int pin, PinMode mode) = 0;
        virtual int analogRead(int pin) = 0;
        virtual int digitalRead(int pin) = 0;
        virtual unsigned int millis() = 0;


        virtual void print(const char *) = 0;
        virtual void println(const char *) = 0;
    };

    extern Platform * platform;

};

#endif //FIRMWARE_ABSTRACTPLATFORM_H
