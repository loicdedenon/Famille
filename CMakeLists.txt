cmake_minimum_required(VERSION 3.28)

project(exercice LANGUAGES C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Remove warnings when compiling dependencies
message("Disable compile warning for directory ${CMAKE_BINARY_DIR}")
set_property(
    DIRECTORY ${CMAKE_BINARY_DIR}
    APPEND
    PROPERTY COMPILE_OPTIONS -Wno-deprecated-declarations
)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0
    OVERRIDE_FIND_PACKAGE
)

FetchContent_Declare(CSFML
    GIT_REPOSITORY https://github.com/SFML/CSFML.git
    GIT_TAG 2.6.0)

FetchContent_MakeAvailable(SFML CSFML)

add_executable(exercice src/main.c src/my_paint.c
        src/paint_context.c
        src/paint_context.h
        src/paint_state.c
        src/paint_state.h
        src/sfml_utils.c
        src/sfml_utils.h)

# Be pedantic !
if(MSVC)
    target_compile_options(exercice PRIVATE /W4 /WX)
else()
    target_compile_options(exercice PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-unused-variable)
endif()

target_link_libraries(exercice PRIVATE csfml-graphics csfml-window csfml-system sfml-graphics sfml-window sfml-system)

