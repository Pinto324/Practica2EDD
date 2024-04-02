//
// Created by branp on 1/04/2024.
//

#ifndef GESTIONCONTACTOS_INFORMACION_H
#define GESTIONCONTACTOS_INFORMACION_H
#include <string>
#include "../ListaDoblemente/Controlador.h"

class Informacion {
    public:
    std::string Valor;
    std::string Tipo;
    Controlador* Direccion;

    Informacion(std::string Valor, std::string Tipo,Controlador* Direccion) : Valor(Valor), Tipo(Tipo), Direccion(Direccion){}

    std::string DevolverValor();
};


#endif //GESTIONCONTACTOS_INFORMACION_H
