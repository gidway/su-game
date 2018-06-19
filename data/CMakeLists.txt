cmake_minimum_required(VERSION 3.10)

# TODO make data target for each type of contents
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/fonts DESTINATION ${CMAKE_BINARY_DIR}/bin/data/)
