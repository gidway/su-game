cmake_minimum_required(VERSION 3.10)
project(build-scripts CXX)

file(COPY        ${CMAKE_CURRENT_SOURCE_DIR}/run
     DESTINATION ${CMAKE_BINARY_DIR})

