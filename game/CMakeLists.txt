cmake_minimum_required(VERSION 3.10)
project(game CXX)


set(CMAKE_MODULE_PATH
	${CMAKE_CURRENT_SOURCE_DIR}/common/cmake/
	)
add_subdirectory(common)

add_subdirectory(engine)
add_subdirectory(product)
