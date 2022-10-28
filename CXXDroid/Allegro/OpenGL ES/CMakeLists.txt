cmake_minimum_required(VERSION 3.6.0)
project(HelloGLES)
include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/src
)
file(GLOB SRCS
	"${PROJECT_SOURCE_DIR}/include/*"
	"${PROJECT_SOURCE_DIR}/src/*"
)
add_definitions(-DGLES2)
add_executable(HelloGLES ${SRCS})
find_package(Allegro REQUIRED)
target_link_libraries(HelloGLES ${ALLEGRO_LIBRARIES})