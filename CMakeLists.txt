cmake_minimum_required(VERSION 3.17.3)

project(ALL VERSION 1.0.0)

set(3RD_SOURCE_DIR "${CMAKE_SOURCE_DIR}/3rd")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    set(VCPKG_INSTALLED_DIR "${3RD_SOURCE_DIR}/vcpkg/installed/x64-windows")
    set(VCPKG_INSTALLED_DIR_STATIC "${3RD_SOURCE_DIR}/vcpkg/installed/x64-windows-static")
elseif(APPLE)
    set(VCPKG_INSTALLED_DIR "${3RD_SOURCE_DIR}/vcpkg/installed/x64-osx")
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  mark_as_advanced(CMAKE_BUILD_TYPE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

add_subdirectory(src)