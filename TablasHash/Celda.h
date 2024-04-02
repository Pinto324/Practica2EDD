//
// Created by branp on 1/04/2024.
//

#ifndef GESTIONCONTACTOS_CELDA_H
#define GESTIONCONTACTOS_CELDA_H


#include <string>

// Declaración de avance de Nodo
class ArbolAVL;

class Celda {
public:
    std::string Nombre;
    std::string orden;
    Celda * Tabla;
    ArbolAVL * Arbol;
    int tamaño;
    Celda(): Tabla(nullptr),Arbol(nullptr){}
};


#endif //GESTIONCONTACTOS_CELDA_H
