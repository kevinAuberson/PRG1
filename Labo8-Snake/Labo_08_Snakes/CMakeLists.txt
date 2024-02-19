cmake_minimum_required(VERSION 3.23.2)
project(Labo_08_Snakes)

set(CMAKE_CXX_STANDARD 20)


if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(SDL2_INCLUDE_DIR c:/libs/sdl2/include)
    set(SDL2_LIB_DIR path c:/libs/sdl2/lib/x64)
    include_directories(${SDL2_INCLUDE_DIR})
    link_directories(${SDL2_LIB_DIR})
endif()
set(PRJ_SOURCE_FILES
        main.cpp
        annexe.cpp
        annexe.h
        serpents.cpp serpents.h terrain.cpp terrain.h)
# déclaration de la target serpent
add_executable(${PROJECT_NAME}
        ${PRJ_SOURCE_FILES}
        )
# Spécification des librairies pour la target serpent
target_link_libraries(${PROJECT_NAME}
        SDL2main
        SDL2
        )