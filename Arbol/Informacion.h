//
// Created by branp on 1/04/2024.
//

#ifndef GESTIONCONTACTOS_INFORMACION_H
#define GESTIONCONTACTOS_INFORMACION_H
#include <string>

class Informacion {
    public:
    std::string Valor;
    std::string Tipo;
    int Indice;
    std::string* Direccion;

    Informacion(std::string Valor, std::string Tipo,int Indice,std::string* Direccion) : Valor(Valor), Tipo(Tipo), Indice(Indice), Direccion(Direccion){}

    std::string DevolverValor();
};


#endif //GESTIONCONTACTOS_INFORMACION_H
