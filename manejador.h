//
// Created by branp on 30/03/2024.
//

#ifndef GESTIONCONTACTOS_MANEJADOR_H
#define GESTIONCONTACTOS_MANEJADOR_H


#include <vector>
#include <string>
#include "hash.h"
class manejador {
    private:
    std::string * Th1;
    int valorArreglo;
    static const double FACTOR_CARGA_MAXIMO;
    int elementos;
    hash ManejadorHash;
    public:
        manejador(std::string *);
        void Consola();

    std::vector<std::string> split(const std::__cxx11::basic_string<char> &str, char delim);

    void procesarComando(const std::string &comando);

    void CrearGrupoNuevo(std::vector<std::string> Datos, std::string *tablaNueva);
};


#endif //GESTIONCONTACTOS_MANEJADOR_H
