//
// Created by branp on 1/04/2024.
//

#ifndef GESTIONCONTACTOS_INFORMACION_H
#define GESTIONCONTACTOS_INFORMACION_H

#include <string>

// Declaración de avance de Controlador
class Controlador;

class Informacion {
public:
    std::string Valor;
    std::string Tipo;
    Controlador* Direccion;

    Informacion(std::string Valor, std::string Tipo, Controlador* Direccion) : Valor(Valor), Tipo(Tipo), Direccion(Direccion) {}

    std::string DevolverValor();
};

#endif //GESTIONCONTACTOS_INFORMACION_H
