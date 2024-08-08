cmake_minimum_required(VERSION 3.18)

project(AOCF)


string(TOLOWER ${CMAKE_SYSTEM_NAME} PLATFORM)
if (PLATFORM STREQUAL "windows")
    set(PLATFORM "win64")
elseif(PLATFORM STREQUAL "linux")
    set(PLATFORM "linux")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(AOCF SHARED 
    src/aocf_platform_${PLATFORM}.cpp
)

target_compile_definitions(AOCF PRIVATE AOCF_EXPORTS)


# executable example
add_executable(example
    example/main.cpp
)
target_link_libraries(example AOCF)