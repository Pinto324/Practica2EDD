//
// Created by branp on 1/04/2024.
//

#ifndef GESTIONCONTACTOS_CONTROLADOR_H
#define GESTIONCONTACTOS_CONTROLADOR_H


#include <string>
#include "../Arbol/Nodo.h"

class Controlador {
    public:
        Controlador* Siguiente, *Anterior;
        std::string Tipo;
        Nodo *Info;
        Controlador(): Siguiente(nullptr), Anterior(nullptr), Tipo(""), Info(nullptr){};
};


#endif //GESTIONCONTACTOS_CONTROLADOR_H
