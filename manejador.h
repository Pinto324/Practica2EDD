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
    const int Ntabla2 = 10;
    public:
        manejador(Celda *);
        void Consola();

    std::vector<std::string> split(const std::__cxx11::basic_string<char> &str, char delim);
    std::string crearArbol();
    void procesarComando(const std::string &comando);

    std::string CrearGrupoNuevo(std::vector<std::string> Datos, Celda *tablaNueva);

    ArbolAVL * crearArbol(std::string Tipo);

    void InsertarContenidoArbol(Nodo *Nodo, std::string contenido);

    void InsertarContenidoTabla2(Celda *tabla, std::vector<std::string> Orden, std::vector<std::string> campos,
                                 ArbolAVL NuevoArbol);
};


#endif //GESTIONCONTACTOS_MANEJADOR_H
