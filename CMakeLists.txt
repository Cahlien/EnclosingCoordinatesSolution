cmake_minimum_required(VERSION 3.16)
project(EnclosingCoordinatesSolution)

set(CMAKE_CXX_STANDARD 20)

include(CTest)
if ($ENV{ENVIRONMENT_DOCKER})
    include(conanbuildinfo.cmake)
    conan_basic_setup()
    set(Boost_INSTALL_DIR ${CONAN_BOOST_ROOT})
    set(Boost_USE_STATIC_LIBS ON)
endif ()

find_package(Boost COMPONENTS program_options unit_test_framework REQUIRED)
if (Boost_FOUND)
    message(STATUS "Boost found")
endif ()

set(${PROJECT_NAME}_SOURCES
        src/main.cpp
        src/shape.cpp
        src/square.cpp
        src/circle.cpp
)

set(${PROJECT_NAME}_CIRCLE_TEST_SOURCES
        src/shape.cpp
        src/circle.cpp
        test/circle/circle.test.cpp
)

set(${PROJECT_NAME}_SQUARE_TEST_SOURCES
        src/shape.cpp
        src/square.cpp
        test/square/square.test.cpp
)

set(${PROJECT_NAME}_INCLUDE_DIRS
        src/include
        ${Boost_INCLUDE_DIRS}
)

set(${PROJECT_NAME}_LIBRARIES
        ${CONAN_LIBS}
        ${Boost_LIBRARIES}
)

add_executable(
        ${PROJECT_NAME}.exe
        ${${PROJECT_NAME}_SOURCES}
)

target_include_directories(
        ${PROJECT_NAME}.exe PRIVATE
        ${${PROJECT_NAME}_INCLUDE_DIRS}
)

target_link_libraries(
        ${PROJECT_NAME}.exe
        ${${PROJECT_NAME}_LIBRARIES}
)

add_executable(${PROJECT_NAME}_CIRCLE_TEST.exe
        ${${PROJECT_NAME}_CIRCLE_TEST_SOURCES}
)

target_include_directories(${PROJECT_NAME}_CIRCLE_TEST.exe
        PRIVATE ${${PROJECT_NAME}_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}_CIRCLE_TEST.exe
        ${${PROJECT_NAME}_LIBRARIES}
)

add_test(
        NAME ${PROJECT_NAME}_CIRCLE_TEST
        COMMAND ${PROJECT_NAME}_CIRCLE_TEST
)

add_executable(${PROJECT_NAME}_SQUARE_TEST.exe
        ${${PROJECT_NAME}_SQUARE_TEST_SOURCES}
)

target_include_directories(${PROJECT_NAME}_SQUARE_TEST.exe
        PRIVATE ${${PROJECT_NAME}_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}_SQUARE_TEST.exe
        ${${PROJECT_NAME}_LIBRARIES}
)

add_test(
        NAME ${PROJECT_NAME}_SQUARE_TEST
        COMMAND ${PROJECT_NAME}_SQUARE_TEST
)

include(CPack)