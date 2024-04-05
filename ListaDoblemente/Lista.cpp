//
// Created by branp on 1/04/2024.
//

#include <vector>
#include <iostream>
#include "Lista.h"
#include "Controlador.h"

Controlador* Lista::RecorrerNodoI(Controlador* Centinela){

    while (Centinela->Anterior != nullptr) {
        Centinela = Centinela->Anterior;
    }

    return Centinela;
}
Controlador* Lista::RecorrerNodoD(Controlador* Centinela){

    while (Centinela->Siguiente != nullptr) {
        Centinela = Centinela->Siguiente;
    }

    return Centinela;
}
void Lista::AgregarNodoDoble(Controlador* temp, Controlador* Nuevo){
    temp->Siguiente=Nuevo;
    Nuevo->Anterior=temp;
}
void Lista::ImprimirBuscar(Controlador* Centinela) {
    try {
        while (Centinela->Siguiente != nullptr) {
            Centinela = Centinela->Siguiente;
            Nodo* nodoActual = Centinela->Info;
            std::cout << Centinela->Tipo <<" : " << Centinela->Info->dato.DevolverValor() << std::endl;
        }
    } catch (...) {
        std::cout <<"No sé encontro datos unu"<< std::endl;
    }
}

