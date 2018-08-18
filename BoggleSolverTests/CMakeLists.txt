cmake_minimum_required(VERSION 3.0.0)
project(BoggleSolver VERSION 0.1.0)

set(BOGGLE_TEST_HEADERS
    "googleTestLib/gtest/gtest.h"
)

set(BOGGLE_TEST_SOURCES
    "../BoggleSolver/Source/BoggleSolver.cpp"
    "../BoggleSolver/Source/Node.cpp"
    "../BoggleSolver/Source/Tree.cpp"
    "../BoggleSolver/Source/Utils.cpp"

    "googleTestLib/gtest/gtest-all.cc"

    "Tests/TreeTests.cpp"
    "Main.cpp"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/googleTestLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BoggleSolver/Include)

find_package (Threads)

add_executable(BoggleSolverTests ${BOGGLE_TEST_HEADERS} ${BOGGLE_TEST_SOURCES})

target_link_libraries (BoggleSolverTests ${CMAKE_THREAD_LIBS_INIT})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})