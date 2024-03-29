cmake_minimum_required(VERSION 3.0.0)
project(tetris VERSION 0.1.0)

include(FetchContent)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC 1)
set(SFML_DIR "${PROJECT_SOURCE_DIR}/external/SFML")
set(IMGUI_SFML_DIR "${PROJECT_SOURCE_DIR}/external/imgui-sfml")

add_compile_definitions(SFML_STATIC)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${SFML_DIR}/include)
include_directories(${IMGUI_SFML_DIR}/include)
include_directories(resources)
include(CTest)
enable_testing()

set(PROJECT_SOURCES
    "src/main.cpp"

    "include/Juego.h"
    "src/Juego.cpp"

    "include/Mapa.h"
    "src/Mapa.cpp"

    "include/Bloque.h"
    "src/Bloque.cpp"

    "include/Pieza.h"
    "src/Pieza.cpp"

    "include/Operaciones.h"
    "src/Operaciones.cpp"

    "include/Menu.h"
    "src/Menu.cpp"
)
#set(ImGui-SFML_DIR "${IMGUI_SFML_DIR}/lib/cmake/ImGui-SFML")
#find_package(ImGui-SFML REQUIRED)

add_executable(tetris ${PROJECT_SOURCES})

target_link_directories(tetris PUBLIC "${SFML_DIR}/lib")
target_link_directories(tetris PUBLIC "${IMGUI_SFML_DIR}/lib")


target_link_libraries(tetris
    PUBLIC
        ImGui-SFML
        sfml-window-s
        sfml-system-s
        sfml-graphics-s
        opengl32
        winmm
        gdi32
        imm32
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
