cmake_minimum_required(VERSION 3.0.0)
project(BoggleSolver VERSION 0.1.0)

set(BOGGLE_HEADERS
    "Include/FuncToTest.h"
)

set(BOGGLE_SOURCES
    "Source/FuncToTest.cpp"
    "Main.cpp"
)

add_executable(BoggleSolver ${BOGGLE_HEADERS} ${BOGGLE_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})