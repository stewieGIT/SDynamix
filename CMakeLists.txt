# ==========================================
# STEP 1: Setup & Global Settings
# ==========================================
cmake_minimum_required(VERSION 3.10)
project(SDynamix LANGUAGES C VERSION 1.0 )

# Set global behaviors (like creating clangd compilation databases)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/docs")
    set(DOXYGEN_HTML_OUTPUT ".")
    set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
    set(DOXYGEN_RECURSIVE YES)

    # use mathjax instead of installing latex packages...
    set(DOXYGEN_USE_MATHJAX YES)

    doxygen_add_docs(doc
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        COMMENT "Generating Lib documentation"
    )
endif()

# ==========================================
# STEP 2: Gather Ingredients
# ==========================================
# Collect your source files into a variable
add_executable(SDynamix src/main.c src/vector.c)

# ==========================================
# STEP 4: Decorate & Link the Target
# ==========================================
# Now that SDynamix exists, you can modify it safely:

# Tell it where headers live
target_include_directories(SDynamix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link external or system libraries (like the math library)
target_link_libraries(SDynamix PRIVATE m)

# Add your strict warning flags/guardrails (compiler)
if (CMAKE_C_COMPILER_ID STREQUAL "Clang" OR CMAKE_C_COMPILER_ID STREQUAL "GNU")
    target_compile_options(SDynamix PRIVATE
        -Wall
        -Wextra
        -Wmissing-field-initializers
        -Werror
    )
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(SDynamix PRIVATE DEBUG)
endif()