cmake_minimum_required(VERSION 3.27)
project(GestionContactos)

set(CMAKE_CXX_STANDARD 17)

add_executable(GestionContactos main.cpp
        manejador.cpp
        manejador.h
        hash.cpp
        hash.h
        Arbol/Informacion.cpp
        Arbol/Informacion.h
        Arbol/Informacion.h
        Arbol/Nodo.cpp
        Arbol/Nodo.h
        Arbol/ArbolAVL.cpp
        Arbol/ArbolAVL.h
        ListaDoblemente/Controlador.cpp
        ListaDoblemente/Controlador.h
        ListaDoblemente/Lista.cpp
        ListaDoblemente/Lista.h
        TablasHash/Celda.cpp
        TablasHash/Celda.h)
