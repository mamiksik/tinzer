cmake_minimum_required(VERSION 3.2)
project(KetchupHouse CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(CMakeForceCompiler)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR armv)

set(TOOLCHAIN_DIR /usr/local/Cellar/gcc-arm-none-eabi/20140805/bin)

CMAKE_FORCE_C_COMPILER(${TOOLCHAIN_DIR}/arm-none-eabi-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(${TOOLCHAIN_DIR}/arm-none-eabi-g++ GNU)

message("Cross-compiling")
message(${CMAKE_CXX_FLAGS})


set(FRAMEWORK_FILES
    framework/control/motors/AbstractControl.cpp
    main.cpp)

set(SOURCE_FILES
    app/hardware/motor/Motor.cpp
    app/threads/sensors/EncoderSensor.cpp
    app/threads/controls/MotorControl.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

add_executable(KetchupHouse ${FRAMEWORK_FILES} ${SOURCE_FILES})

