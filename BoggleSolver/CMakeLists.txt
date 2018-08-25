cmake_minimum_required(VERSION 3.0.0)
project(BoggleSolver VERSION 0.1.0)

set(BOGGLE_HEADERS
    "Include/BoggleSolver.h"
    "Include/Node.h"
    "Include/Tree.h"
    "Include/Utils.h"
    "Include/Board.h"
    "Include/Results.h"
    "Include/Timer.h"
)

set(BOGGLE_SOURCES
    "Source/BoggleSolver.cpp"
    "Source/Node.cpp"
    "Source/Tree.cpp"
    "Source/Utils.cpp"
    "Source/Timer.cpp"
    "Source/Board.cpp"
    
    "Main.cpp"
)

add_executable(BoggleSolver ${BOGGLE_HEADERS} ${BOGGLE_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})