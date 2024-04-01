//
// Created by branp on 1/04/2024.
//

#ifndef GESTIONCONTACTOS_NODO_H
#define GESTIONCONTACTOS_NODO_H
#include "Informacion.h"

class Nodo {
public:
    Informacion dato;
    Nodo* izquierdo;
    Nodo* derecho;
    int altura;

    Nodo(Informacion dato) : dato(dato), izquierdo(nullptr), derecho(nullptr), altura(1) {}
};


#endif //GESTIONCONTACTOS_NODO_H
