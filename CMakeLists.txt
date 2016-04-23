cmake_minimum_required(VERSION 3.2)
project(KetchupHouse CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(FRAMEWORK_FILES
    framework/control/motors/AbstractControl.cpp
    main.cpp)

set(SOURCE_FILES
    app/hardware/motors/Motor.cpp
    app/threads/sensors/EncoderSensor.cpp
    app/threads/controls/MotorControl.cpp)


add_executable(KetchupHouse ${FRAMEWORK_FILES} ${SOURCE_FILES})

