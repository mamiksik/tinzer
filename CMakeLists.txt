cmake_minimum_required(VERSION 3.2)
project(KetchupHouse CXX)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#find_package(OpenCV REQUIRED)
#find_library(LIBSTDCXX NAMES stdc++)

set(SOURCE_FILES
    main.cpp
    app/Config.h
    app/control/Control.cpp
    app/control/Control.h
    app/api/Engine.cpp app/api/Engine.h
    app/grid/Position.cpp
    app/grid/Position.h
    app/threads/ControlThread.h
    app/threads/LogicThread.h
    app/structures/Coordinates.h
    app/structures/Instruction.h
    app/structures/SensorsArray.h
    app/LineSensore/LineSensore.cpp
    app/LineSensore/LineSensore.h)

#add_compile_options(-stdlib=libstdc++)
add_executable(KetchupHouse ${SOURCE_FILES})
#target_link_libraries(KetchupHouse ${OpenCV_LIBS})

