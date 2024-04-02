//
// Created by branp on 30/03/2024.
//

#ifndef GESTIONCONTACTOS_MANEJADOR_H
#define GESTIONCONTACTOS_MANEJADOR_H


#include <vector>
#include <string>
#include "hash.h"
#include "Arbol/ArbolAVL.h"

class manejador {
    private:
    std::string * Th1;
    int valorArreglo;
    static const double FACTOR_CARGA_MAXIMO;
    int elementos;
    hash ManejadorHash;
    ArbolAVL ManejadorArbol;

    public:
        manejador(std::string *);
        void Consola();

    std::vector<std::string> split(const std::__cxx11::basic_string<char> &str, char delim);
    std::string crearArbol();
    void procesarComando(const std::string &comando);

    void CrearGrupoNuevo(std::vector<std::string> Datos, std::string *tablaNueva);

    std::string crearArbol(std::string Tipo);
};


#endif //GESTIONCONTACTOS_MANEJADOR_H
