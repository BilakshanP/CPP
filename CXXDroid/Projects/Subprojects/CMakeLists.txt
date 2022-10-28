cmake_minimum_required(VERSION 3.6.0)
project(Example)
include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/src
)
file(GLOB SRCS
	"${PROJECT_SOURCE_DIR}/include/*"
	"${PROJECT_SOURCE_DIR}/src/*"
)
add_executable(Example ${SRCS})
add_subdirectory(subproject)
target_link_libraries(Example Subproject)