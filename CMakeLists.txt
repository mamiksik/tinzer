cmake_minimum_required(VERSION 2.8)
project(KetchupHouse CXX)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

#SET(CMAKE_CXX_COMPILER arm-linux-gnueabi-g++)
SET(CMAKE_CXX_COMPILER /Volumes/ARM-LINUX/arm-unknown-linux-gnueabi/bin/arm-unknown-linux-gnueabi-g++)
#SET(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread")

set(FRAMEWORK_FILES
    framework/hardware/IMotor.h
    framework/structures/Coordinate.h
    framework/structures/Instruction.h
    framework/sensor/AbstractSensor.cpp
    framework/control/motors/AbstractMotor.cpp
    framework/looper/looper.cpp
    framework/hardware/EncoderSync.cpp
    framework/hardware/EncoderSync.h
    app/Config.h
    main.cpp
    framework/Helpers.cpp framework/Helpers.h)

set(SOURCE_FILES
    framework/hardware/IEncoder.h
    app/threads/sensors/IEncoderCallback.h
    app/hardware/ev3dev.cpp
    app/hardware/motor/Motor.cpp
    app/hardware/encoder/Encoder.cpp
    app/threads/controls/MotorControl.cpp
    app/threads/sensors/EncoderSensor.cpp
    app/threads/MainThread.h
    )

add_executable(KetchupHouse ${FRAMEWORK_FILES} ${SOURCE_FILES})

