cmake_minimum_required(VERSION 3.10)
project(engine CXX)

set(ENGINE_SOURCES
	game/Core.cc
	game/State.cc
	)

find_package(SDL2 REQUIRED)
find_package(SDL2TTF REQUIRED)
include_directories(
	${SDL2_INCLUDE_DIRS}
	)

add_library(engine STATIC
	${ENGINE_SOURCES}
	)
target_sources(engine
	PRIVATE
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/game/Core.hh"
        "${CMAKE_CURRENT_LIST_DIR}/sdl/Window.hh"
        "${CMAKE_CURRENT_LIST_DIR}/sdl/UniqueWindow.hh"
        "${CMAKE_CURRENT_LIST_DIR}/sdl/SharedWindow.hh"
        "${CMAKE_CURRENT_LIST_DIR}/sdl/Renderer.hh"
        "${CMAKE_CURRENT_LIST_DIR}/sdl/Surface.hh"
	)
target_include_directories(engine
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}"
		"${CMAKE_CURRENT_LIST_DIR}../"
	)
target_link_libraries(engine
	PUBLIC
		${SDL2_LIBRARIES}
		${SDL2TTF_LIBRARY}
		#common_filesystem
	)
