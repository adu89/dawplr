project(Dawplr VERSION 0.1.0)

add_definitions(-D_UNICODE -DUNICODE -DWXUSINGDLL -DwxUSE_GUI=1 -D__WXMSW__ -DLINKING_TYPE=dynamic -DWX_PRECOMP)

if(MSVC)
    add_definitions(/MP)
endif()

file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/*.h"
    "${PROJECT_SOURCE_DIR}/*.cpp")

link_directories(
    "${VCPKG_INSTALLED_DIR}$<$<CONFIG:DEBUG>:/debug>/lib" 
)

include_directories(
    "${VCPKG_INSTALLED_DIR}/include"
)

add_executable(Dawplr WIN32)

target_link_libraries(Dawplr PUBLIC
    wxbase31u$<$<CONFIG:DEBUG>:d>_net
    wxmsw31u$<$<CONFIG:DEBUG>:d>_core
    wxbase31u$<$<CONFIG:DEBUG>:d>
    wxmsw31u$<$<CONFIG:DEBUG>:d>_aui
    wxmsw31u$<$<CONFIG:DEBUG>:d>_html
    libpng16$<$<CONFIG:DEBUG>:d>
    zlib$<$<CONFIG:DEBUG>:d>
    comctl32
    Rpcrt4
    AudioFile
)

target_sources(
    ${PROJECT_NAME} PRIVATE ${SOURCES}
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}
)

add_custom_command(TARGET Dawplr POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${VCPKG_INSTALLED_DIR}$<$<CONFIG:DEBUG>:/debug>/bin/"
        ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>)

