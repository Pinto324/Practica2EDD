//
// Created by branp on 31/03/2024.
//

#ifndef GESTIONCONTACTOS_HASH_H
#define GESTIONCONTACTOS_HASH_H

#include <string>
#include "TablasHash/Celda.h"

class hash {
private:

public:
    hash();
    void CrearTabla();


    Celda *buscarCelda(const std::string &nombre, int size, Celda *datos);

    void insertarTabla1(int *size, const std::string &nombre, Celda *Meter, Celda *datos, int *elementos, double carga,const std::string &cadena);

    std::string buscarCeldaOrden(const std::string &nombre, int size, Celda *datos);

    void insertarTabla2(int *size, const std::string &nombre, ArbolAVL *Meter, Celda *datos, int *elementos, double carga);

    ArbolAVL *buscarArbol(const std::string &nombre, int size, Celda *datos);
};


#endif //GESTIONCONTACTOS_HASH_H
