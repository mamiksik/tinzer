cmake_minimum_required(VERSION 3.3)
project(KetchupHouse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}") #[[-std=c++11 -stdlib=libstdc++]]

find_package(OpenCV REQUIRED)
find_library(LIBSTDCXX NAMES stdc++)

#set(SOURCE_FILES Study/multipleObjectTracking.cpp Study/Fruit.cpp Study/Fruit.h)

set(SOURCE_FILES main.cpp app/control/Control.cpp app/control/Control.h app/api/Engine.cpp app/api/Engine.h app/grid/Position.cpp app/grid/Position.h app/Config.h app/threads/ControlThread.h app/threads/LogicThread.h)

#add_compile_options(-stdlib=libstdc++)
add_executable(KetchupHouse ${SOURCE_FILES})
target_link_libraries(KetchupHouse ${OpenCV_LIBS})

