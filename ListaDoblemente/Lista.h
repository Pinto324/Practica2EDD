//
// Created by branp on 1/04/2024.
//

#ifndef GESTIONCONTACTOS_LISTA_H
#define GESTIONCONTACTOS_LISTA_H


#include "Controlador.h"
#include "../Arbol/Nodo.h"
class Lista {
public:
    Controlador *RecorrerNodoI(Controlador *Centinela);

    void AgregarNodoDoble(Controlador *temp, Controlador *Nuevo);

    Controlador *RecorrerNodoD(Controlador *Centinela);

    void ImprimirBuscar(Controlador *Centinela);
};


#endif //GESTIONCONTACTOS_LISTA_H
