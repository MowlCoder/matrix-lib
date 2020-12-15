project(matrix-exe)

SET(SOURCES
        ../include/matrix/matrix.cpp
        ../main.cpp
        ../include/random/random.cpp)

include_directories(${MATRIX_INCLUDE})
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} matrix)