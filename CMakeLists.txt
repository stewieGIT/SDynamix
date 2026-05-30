cmake_minimum_required(VERSION 3.10)
project(SDynamix LANGUAGES C VERSION 1.0 )

# Set global behaviors (like creating clangd compilation databases)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the build type" FORCE)
endif()

add_library(sdynamix_core
    STATIC src/vector.c
)

target_include_directories(sdynamix_core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(sdynamix_core
    PRIVATE m
)

if (CMAKE_C_COMPILER_ID STREQUAL "Clang" OR CMAKE_C_COMPILER_ID STREQUAL "GNU")
    target_compile_options(sdynamix_core PRIVATE
        -Wall
        -Wextra
        -Wmissing-field-initializers
        -Werror
    )
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(sdynamix_core PRIVATE DEBUG)
endif()

# testing stuff
enable_testing()
add_executable(run_tests
    tests/test_vector.c
)
target_link_libraries(run_tests
    PRIVATE sdynamix_core
)
add_test(NAME CoreVectorMath COMMAND run_tests)

# documentation
find_package(Doxygen REQUIRED)
if (DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/docs")
    set(DOXYGEN_HTML_OUTPUT ".")
    set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
    set(DOXYGEN_RECURSIVE YES)
    # use mathjax instead of installing latex packages...
    set(DOXYGEN_USE_MATHJAX YES)
    set(DOXYGEN_FILE_PATTERNS "*.c" "*.h" "*.md")
   
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "README.md")

    doxygen_add_docs(doc
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/README.md
        COMMENT "Generating Lib documentation"
    )
endif()