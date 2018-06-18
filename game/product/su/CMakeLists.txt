cmake_minimum_required(VERSION 3.10)
project(su CXX)

set(SU_SRC
	main.cc
	)

add_executable(su
	${SU_SRC}
	)
add_dependencies(su
	engine
	)
target_link_libraries(su
	PUBLIC
		engine
	)
