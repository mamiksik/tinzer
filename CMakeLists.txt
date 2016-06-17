cmake_minimum_required(VERSION 2.8)
project(KetchupHouse CXX)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)


if (APPLE)
	SET(CMAKE_CXX_COMPILER /Volumes/ARM-LINUX/arm-unknown-linux-gnueabi/bin/arm-unknown-linux-gnueabi-g++)
	#SET(CMAKE_CXX_COMPILER g++)
elseif (WIN32)
	#TODO windows compiler
elseif (UNIX)
	SET(CMAKE_CXX_COMPILER arm-linux-gnueabi-g++)
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread  -D_GLIBCXX_USE_NANOSLEEP")

set(FRAMEWORK_FILES
    main.cpp
    app/Config.h
    app/threads/Boostrap.h
    framework/looper/looper.cpp
    framework/hardware/IEncoder.h
    framework/hardware/IMotor.h
    framework/Helpers/Helpers.cpp
    framework/control/motors/AbstractMotor.cpp
    framework/threading/Threading.cpp
    framework/looper/StopWatch.h
    app/threads/BrainThread.cpp
    app/threads/BrainThread.h)

set(SOURCE_FILES
    app/hardware/ev3dev.cpp
    app/threads/sensors/motorEncoder/EncoderSensor.cpp
    app/threads/controls/MotorControl.cpp
    app/hardware/encoder/Encoder.cpp
    app/hardware/motor/Motor.cpp
    app/hardware/button/Button.cpp

    framework/structures/Coordinate.h
    framework/structures/Instruction.h
    app/threads/sensors/stopButton/StopButtonSensor.cpp
    app/threads/BrainThread.cpp
    app/threads/BrainThread.h)

add_executable(KetchupHouse ${FRAMEWORK_FILES} ${SOURCE_FILES})

