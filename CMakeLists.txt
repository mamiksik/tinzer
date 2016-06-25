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
    app/threads/Bootstrap.h
    framework/loop/loop.cpp
    framework/Helpers/Helpers.cpp
    framework/controller/CoordinateController.cpp
    framework/threading/Threading.cpp
    framework/stopWatch/StopWatch.h
    framework/structures/Coordinate.h
    app/threads/controller/Controller.cpp
    app/threads/logic/Logic.cpp
    )

set(SOURCE_FILES
    app/hardware/ev3dev.cpp

    app/hardware/encoder/Encoder.cpp
    app/hardware/motor/Motor.cpp
    app/hardware/diode/Diode.cpp
    app/hardware/button/Button.cpp
    app/hardware/ultrasonicSensor/Ultrasonic.cpp
    app/hardware/reflectiveBar/ReflectiveBar.cpp

    app/model/ultrasonic/UltrasonicModel.cpp
    app/model/encoder/EncodersModel.cpp
    app/model/line/LineModel.cpp

    app/model/button/ButtonsModel.cpp
    app/threads/logic/Logic.cpp framework/hardware/IReflectiveBar.h app/model/ReflectiveBars/ReflectiveModel.cpp app/model/ReflectiveBars/ReflectiveModel.h)

add_executable(KetchupHouse ${FRAMEWORK_FILES} ${SOURCE_FILES})

