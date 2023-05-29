cmake_minimum_required(VERSION 3.0)
project(city-scan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20")

set(SRC_LIST 
    src/main.cpp
    src/database.cpp
    src/client.cpp
    src/data_interface.cpp
)

add_executable(city-scan ${SRC_LIST})

find_package(CURL CONFIG REQUIRED)
find_package(unofficial-mysql-connector-cpp CONFIG REQUIRED)

target_link_libraries(city-scan PRIVATE CURL::libcurl)
target_link_libraries(city-scan PRIVATE unofficial::mysql-connector-cpp::connector)