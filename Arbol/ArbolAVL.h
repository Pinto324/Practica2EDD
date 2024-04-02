//
// Created by branp on 1/04/2024.
//

#ifndef GESTIONCONTACTOS_ARBOLAVL_H
#define GESTIONCONTACTOS_ARBOLAVL_H
#include "Nodo.h"
#include "../ListaDoblemente/Controlador.h"
class ArbolAVL {
public:
    Nodo* raiz;
    ArbolAVL() : raiz(nullptr) {}


    void recorrerInorden();

    Nodo *insertar(Informacion dato, Controlador Lista);

    void recorrerInorden(Nodo *nodo);

    Nodo *insertar(Nodo *nodo, Informacion dato, Controlador Lista);
};


#endif //GESTIONCONTACTOS_ARBOLAVL_H
