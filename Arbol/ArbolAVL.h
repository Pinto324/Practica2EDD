//
// Created by branp on 1/04/2024.
//

#ifndef GESTIONCONTACTOS_ARBOLAVL_H
#define GESTIONCONTACTOS_ARBOLAVL_H
#include "Nodo.h"

class ArbolAVL {
public:
    Nodo* raiz;
    ArbolAVL() : raiz(nullptr) {}

    Nodo * insertar(Informacion dato);

    void recorrerInorden();

    Nodo *insertar(Nodo *nodo, Informacion dato);

    void recorrerInorden(Nodo *nodo);
};


#endif //GESTIONCONTACTOS_ARBOLAVL_H
