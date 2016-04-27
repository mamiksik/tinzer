cmake_minimum_required(VERSION 3.2)
project(KetchupHouse CXX)

#set(TOOLCHAIN_DIR /usr/local/Cellar/gcc-arm-none-eabi/20140805/bin)
set(TOOLCHAIN_DIR /usr/local/Cellar/gcc-arm-none-eabi-49/20150609/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(CMAKE_CXX_COMPILER "${TOOLCHAIN_DIR}/arm-none-eabi-g++")
#set(CMAKE_CXX_FLAGS " -std=c++11 -lpthread")

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)


#[[
include(CMakeForceCompiler)
CMAKE_FORCE_C_COMPILER(${TOOLCHAIN_DIR}/arm-none-eabi-gcc-4.9.3 GNU)
CMAKE_FORCE_CXX_COMPILER(${TOOLCHAIN_DIR}/arm-none-eabi-g++ GNU)
]]

message("Cross-compiling")
message(${CMAKE_CXX_FLAGS})


set(FRAMEWORK_FILES
    framework/control/motors/AbstractControl.cpp
    main.cpp)

set(SOURCE_FILES
    app/hardware/motor/Motor.cpp
    app/threads/LogicThread.h
    app/threads/sensors/EncoderSensor.cpp
    app/threads/controls/MotorControl.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

add_executable(KetchupHouse ${FRAMEWORK_FILES} ${SOURCE_FILES})

