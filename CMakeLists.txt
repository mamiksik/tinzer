cmake_minimum_required(VERSION 2.8)
project(KetchupHouse CXX)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	SET(CMAKE_CXX_COMPILER arm-linux-gnueabi-g++)
elseif ((NOT ${CMAKE_SYSTEM_NAME} MATCHES "OSX"))
	SET(CMAKE_CXX_COMPILER /Volumes/ARM-LINUX/arm-unknown-linux-gnueabi/bin/arm-unknown-linux-gnueabi-g++)
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread")

set(FRAMEWORK_FILES
    )

set(SOURCE_FILES
    )

add_executable(KetchupHouse ${FRAMEWORK_FILES} ${SOURCE_FILES})

