cmake_minimum_required(VERSION 3.25)
project(Pac_Man)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(Pac_Man Model/main.cpp Model/Ventana_Principal.cpp View-Controller/Ventana_Principal.h Model/Nivel1.cpp View-Controller/Nivel1.h Model/Pac_Man.cpp View-Controller/Pac_Man.h Model/Fantasma1.cpp View-Controller/Fantasma1.h Algoritmos/Algoritmo_A_Pathfindig.cpp Algoritmos/Algoritmo_A_Pathfindig.h Model/Fantasma2.cpp View-Controller/Fantasma2.h Model/Nivel2.cpp View-Controller/Nivel2.h)

target_link_libraries(Pac_Man sfml-graphics sfml-audio)