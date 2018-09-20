cmake_minimum_required(VERSION 3.6)

project(mcu_libraries)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(mcu_libraries
        /home/user18/Downloads/arduino-1.8.1/hardware/arduino/avr/variants/standard
        /home/user18/Downloads/arduino-1.8.1/hardware/arduino/avr/cores/arduino
        /home/user18/Downloads/arduino-1.8.1/hardware/arduino/avr/libraries
        /home/user18/Downloads/arduino-1.8.1/hardware/tools/avr/avr/include
        /home/user18/Downloads/arduino-1.8.1/libraries
)

set(SOURCE_FILES
        VisitSensor/VisitSensor.h
        VisitSensor/VisitSensor.cpp
        VisitSensor/Beam.cpp VisitSensor/Beam.h
        IRSensor/IRSensor.cpp IRSensor/IRSensor.h
        VisitSensor/BeamObserver.cpp VisitSensor/BeamObserver.h Platform.cpp Platform.h)

add_definitions(
        -DUBRRH
)

add_library(mcu_libraries ${SOURCE_FILES})