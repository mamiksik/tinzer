cmake_minimum_required(VERSION 2.8)
project(KetchupHouse CXX)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_CXX_COMPILER arm-linux-gnueabi-g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -D_GLIBCXX_USE_NANOSLEEP -pthread")

#if ()
#message(STATUS "Cross-compiling")
#include(CMakeForceCompiler)
#CMAKE_FORCE_CXX_COMPILER(/Volumes/xtools/arm-none-linux-gnueabi/bin/arm-none-linux-gnueabi-g++ GNU)
#CMAKE_FORCE_CXX_COMPILER(/Volumes/EV3-EABI/arm-none-linux-gnueabi/bin/arm-none-linux-gnueabi-g++ GNU)
#endif ()

set(FRAMEWORK_FILES
    framework/hardware/IMotor.h
    framework/structures/Coordinate.h
    framework/structures/Instruction.h
    framework/sensor/AbstractSensor.cpp
    framework/control/motors/AbstractMotor.cpp
    framework/looper/looper.cpp
    app/Config.h
    main.cpp
    )

set(SOURCE_FILES
    app/threads/sensors/IEncoder.h
    app/threads/sensors/IEncoderCallback.h
    app/hardware/ev3dev.cpp
    app/hardware/motor/Motor.cpp
    app/hardware/encoder/Encoder.cpp
    app/threads/controls/MotorControl.cpp
    app/threads/sensors/EncoderSensor.cpp
    app/threads/LogicThread.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

add_executable(KetchupHouse ${FRAMEWORK_FILES} ${SOURCE_FILES})

