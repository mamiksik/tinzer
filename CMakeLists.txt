cmake_minimum_required(VERSION 3.2)
project(KetchupHouse CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(FRAMEWORK_FILES
    framework/control/AbstractControl.h
    framework/control/Stack.cpp
    main.cpp)

set(SOURCE_FILES
    app/Config.h
    app/control/Control.cpp
    app/control/Control.h
    app/api/Engine.cpp app/api/Engine.h
    app/grid/Position.cpp
    app/grid/Position.h
    app/threads/ControlThread.h
    app/threads/LogicThread.h
    framework/structures/Coordinate.h
    framework/structures/Instruction.h
    app/structures/SensorsArray.h
    app/threads/sensors/EncoderSensor.cpp
    app/threads/sensors/EncoderSensor.h
    app/threads/controls/EngineControl.cpp
    app/threads/controls/EngineStack.h)


add_executable(KetchupHouse ${FRAMEWORK_FILES} ${SOURCE_FILES})

