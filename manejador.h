//
// Created by branp on 30/03/2024.
//

#ifndef GESTIONCONTACTOS_MANEJADOR_H
#define GESTIONCONTACTOS_MANEJADOR_H


#include <vector>
#include <string>
#include "hash.h"
#include "Arbol/ArbolAVL.h"
#include "TablasHash/Celda.h"

class manejador {
    private:
    Celda * Th1;
    int valorArreglo;
    static const double FACTOR_CARGA_MAXIMO;
    int elementos;
    hash ManejadorHash;
    ArbolAVL ManejadorArbol;

    public:
        manejador(Celda *);
        void Consola();

    std::vector<std::string> split(const std::__cxx11::basic_string<char> &str, char delim);
    std::string crearArbol();
    void procesarComando(const std::string &comando);

    std::string CrearGrupoNuevo(std::vector<std::string> Datos, Celda *tablaNueva);

    std::string crearArbol(std::string Tipo);
};


#endif //GESTIONCONTACTOS_MANEJADOR_H
