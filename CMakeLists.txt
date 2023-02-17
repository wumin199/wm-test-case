cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(test_cpp)

macro(cxx_17)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    if(MSVC_VERSION GREATER_EQUAL "1900" AND CMAKE_VERSION LESS 3.10)
        include(CheckCXXCompilerFlag)
        check_cxx_compiler_flag("/std:c++17" _cpp_latest_flag_supported)
        if(_cpp_latest_flag_supported)
            add_compile_options("/std:c++17")
        endif()
    endif()
endmacro()

cxx_17()
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug"
        AND NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    message(FATAL_ERROR "Unknown build type \"${CMAKE_BUILD_TYPE}\".
        Allowed values are Debug, Release")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
    add_definitions(-D_USE_MATH_DEFINES)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_ENABLE_EXTENDED_ALIGNED_STORAGE)
    add_definitions(-DGLOG_NO_ABBREVIATED_SEVERITIES)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    add_compile_options(/bigobj)
    add_compile_options("/Zc:preprocessor")
else()
    add_compile_options(-fPIC)
endif()

###############################################
# find packages
###############################################
find_package(absl REQUIRED)
find_package(Eigen3 3.3.4 REQUIRED CONFIG)
find_package(GTest REQUIRED)
find_package(fmt REQUIRED)
find_package(cyber REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core)

find_package(glog QUIET)
if(glog_FOUND)
    set(glog_LIBRARIES glog::glog)
else()
    set(glog_LIBRARIES glog)
endif()

include_directories(
        include
        ${EIGEN3_INCLUDE_DIRS}
        ${GTEST_INCLUDE_DIRS}
        ${cyber_INCLUDE_DIRS}
        ${CMAKE_BINARY_DIR}/include
)

set(required_libraries
        Eigen3::Eigen
        absl::status
        absl::statusor
        absl::base
        absl::strings
        yaml-cpp
        fmt::fmt
        ${glog_LIBRARIES}
        ${gtest_LIBRARIES}
        )

###############################################
# eigen_test test
###############################################
add_executable(main main.cc)


###############################################
# eigen_test test
###############################################
add_subdirectory(src/test_eigen)

