cmake_minimum_required(VERSION 3.10)
project(filesystem CXX)

add_library(filesystem STATIC
	path.cc
	)

target_include_directories(filesystem
	)
