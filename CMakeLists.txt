cmake_minimum_required(VERSION 3.27)
project(GestionContactos)

set(CMAKE_CXX_STANDARD 17)

add_executable(GestionContactos main.cpp
        manejador.cpp
        manejador.h
        hash.cpp
        hash.h)
