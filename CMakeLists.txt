cmake_minimum_required(VERSION 3.13)
project(WeatherMarkovChain)

set(CMAKE_CXX_STANDARD 14)

add_executable(WeatherMarkovChain main.cpp DataReader.cpp WeatherGraph.cpp)