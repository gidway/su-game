cmake_minimum_required(VERSION 3.10)
project(common CXX)

add_library(common_filesystem STATIC
	filesystem/path.cc
	)

target_sources(common_filesystem
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/filesystem/path.hh
	)

target_include_directories(common_filesystem
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
	)
