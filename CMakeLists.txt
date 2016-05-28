cmake_minimum_required(VERSION 2.8)
project(KetchupHouse CXX)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)


if (APPLE)
	SET(CMAKE_CXX_COMPILER /Volumes/ARM-LINUX/arm-unknown-linux-gnueabi/bin/arm-unknown-linux-gnueabi-g++)
elseif (WIN32)
	#TODO windows compiler
elseif (UNIX)
	SET(CMAKE_CXX_COMPILER arm-linux-gnueabi-g++)
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread -D_GLIBCXX_USE_NANOSLEEP ")

set(FRAMEWORK_FILES
    app/threads/MainThread.h
    app/Config.h
    main.cpp
    framework/Helpers/Helpers.cpp framework/Helpers/Helpers.h)

set(SOURCE_FILES
    )

add_executable(KetchupHouse ${FRAMEWORK_FILES} ${SOURCE_FILES})

