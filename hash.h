//
// Created by branp on 31/03/2024.
//

#ifndef GESTIONCONTACTOS_HASH_H
#define GESTIONCONTACTOS_HASH_H

#include <string>
#include "TablasHash/Celda.h"
#include "ListaDoblemente/Lista.h"
class hash {
private:

public:
    hash();
    void CrearTabla();


    Celda *buscarCelda(const std::string &nombre, int size, Celda *datos);

    Celda *
    insertarTabla1(int *size, const std::string &nombre, Celda *Meter, Celda *datos, int *elementos, double carga, const std::string &cadena, Celda* Rehash);

    std::string buscarCeldaOrden(const std::string &nombre, int size, Celda *datos);

    ArbolAVL *buscarArbol(const std::string &nombre, int size, Celda *datos);

    void imprimirTabla(Celda *c, int size);

    void
    insertarTabla2(int *size, const std::string &nombre, ArbolAVL *Meter, Celda *datos, int *elementos, double carga,
                   Celda *rej);
};


#endif //GESTIONCONTACTOS_HASH_H
