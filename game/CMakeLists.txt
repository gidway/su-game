cmake_minimum_required(VERSION 3.10)
project(su CXX)

set(SU_SRC
	main.cc
	Game.cc
	)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(su ${SU_SRC})
target_link_libraries(su ${SDL2_LIBRARIES})
