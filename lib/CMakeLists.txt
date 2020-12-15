project(matrix)

SET(SOURCES
        ../include/matrix/matrix.cpp
        ../include/random/random.cpp
        )

SET(MATRIX_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include" PARENT_SCOPE )
add_library(${PROJECT_NAME} ${SOURCES})