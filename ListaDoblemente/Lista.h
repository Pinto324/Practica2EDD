//
// Created by branp on 1/04/2024.
//

#ifndef GESTIONCONTACTOS_LISTA_H
#define GESTIONCONTACTOS_LISTA_H


#include "Controlador.h"

class Lista {

    Controlador *RecorrerNodoI(Controlador *Centinela);

    void AgregarNodoDoble(Controlador *temp, Controlador *Nuevo);

    Controlador *RecorrerNodoD(Controlador *Centinela);
};


#endif //GESTIONCONTACTOS_LISTA_H
