cmake_minimum_required(VERSION 3.10)

project(SDynamix LANGUAGES C VERSION 1.0 )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(SDynamix src/main.c src/vector.c)

target_include_directories(SDynamix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(SDynamix PRIVATE m)