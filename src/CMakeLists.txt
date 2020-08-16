project(Dawplr VERSION 0.1.0)

file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/*.h"
    "${PROJECT_SOURCE_DIR}/*.cpp")

add_executable(Dawplr)

if(MSVC)
    set_property(TARGET Dawplr PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded")
endif()

target_sources(
    ${PROJECT_NAME} PRIVATE ${SOURCES}
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}
)