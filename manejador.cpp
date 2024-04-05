//
// Created by branp on 30/03/2024.
//

#include "manejador.h"
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdint>
#include "Arbol/ArbolAVL.h"
#include "Arbol/Nodo.h"
#include "ListaDoblemente/Controlador.h"
#include "TablasHash/Celda.h"


manejador::manejador(Celda * a) {
    Th1 = a;
    valorArreglo = 5;
    elementos = 0;
};

//metodo para insertar contenido en un grupo
void manejador::InsertarContenidoTabla2(Celda*tabla, std::vector<std::string> Orden, std::vector<std::string> campos){
    if(Orden.size()==campos.size()){
        auto *Centinela = new Controlador();
        for (size_t i = 0; i < Orden.size(); ++i) {
                auto *Lista = new Controlador();
                Lista->Tipo = Orden[i];
                ManejadorHash.buscarArbol(Orden[i],Ntabla2,tabla)->insertar(Informacion(campos[i],"", Centinela), *Lista);
                ManejadorLista.AgregarNodoDoble(ManejadorLista.RecorrerNodoD(Centinela),Lista);
        }
    }else{
        std::cout << "No escribiste todos los campos requerridos" << std::endl;
    }

}
//metodo para buscar un dato
void manejador::BuscarDato(Celda*tabla, std::vector<std::string> campos){
    auto* Lista = new Controlador();
    Nodo* nodo;
    if(ManejadorHash.buscarArbol(campos[0],Ntabla2,tabla)){
        nodo = ManejadorHash.buscarArbol(campos[0],Ntabla2,tabla)->raiz;
        Lista = ManejadorArbol.buscarDato(nodo,campos[1],Lista);
        ManejadorLista.ImprimirBuscar(Lista);
    }else{
        std::cout << "No se encontro el campo al que te refieres" << std::endl;
    }

}
//metodo principal
void manejador::procesarComando(const std::string &comando){
    std::vector<std::string> palabras = split(comando, ' ');
    if (palabras.size() < 3) {
        std::cout << "Error: Comando inválido." << std::endl;
        return;
    }
    if (palabras[0] == "ADD" && palabras[1] == "NEW-GROUP") {
        auto* tablaNueva = new Celda [Ntabla2];
        Celda *Rehash = nullptr;
        // Obtener el índice donde comienza la sección "FIELDS"
        size_t indice_fields = comando.find("FIELDS");
        if (indice_fields != std::string::npos) {
            std::string fields_section = comando.substr(indice_fields +8); // El +7 es para saltar "FIELDS "
            fields_section.pop_back();
            fields_section.pop_back();
            // Dividir los campos
            std::vector<std::string> campos = split(fields_section, ',');
            ArbolAVL NuevoArbol;
            std::string cadena  = CrearGrupoNuevo(campos,tablaNueva,&NuevoArbol);
            Th1 = ManejadorHash.insertarTabla1(&valorArreglo, palabras[2], &tablaNueva[0],Th1, &elementos,0.6,cadena,Rehash);
            std::cout << "chi funco." << std::endl;
        }
    } else if (palabras[0] == "ADD" && palabras[1] == "CONTACT" && palabras[2] == "IN") {
        if(ManejadorHash.buscarCelda(palabras[3], valorArreglo,Th1)){
            std::string Orden = ManejadorHash.buscarCeldaOrden(palabras[3], valorArreglo,Th1);
            size_t indice_fields = comando.find('(');
            if (indice_fields != std::string::npos) {
                std::string fields_section = comando.substr(indice_fields +1);
                fields_section.pop_back();
                fields_section.pop_back();
                // Dividir los campos
                std::vector<std::string> campos = split(fields_section, ',');
                std::vector<std::string> ordenASeguir = split(Orden, ' ');
                InsertarContenidoTabla2(ManejadorHash.buscarCelda(palabras[3], valorArreglo,Th1),ordenASeguir,campos);
                std::cout << "chi funco." << std::endl;
            }
        }else{
            std::cout << "No se a encontrado el grupo al que te refieres." << std::endl;
        }
    } else if (palabras[0] == "FIND" && palabras[1] == "CONTACT" && palabras[2] == "IN") {
        std::cout << "Buscando contacto en el grupo: " << palabras[3] << std::endl;
        size_t indice_fields = comando.find("FIELD");
        std::string fields_section = comando.substr(indice_fields +6);
        fields_section.pop_back();
        std::vector<std::string> campos = split(fields_section, '=');
        if(ManejadorHash.buscarCelda(palabras[3], valorArreglo,Th1)){
            Celda * celda = ManejadorHash.buscarCelda(palabras[3], valorArreglo,Th1);
            BuscarDato(celda,campos);
        }else {
            std::cout << "No se encontro el grupo: " << palabras[3] << std::endl;
        }
    }
}

std::vector<std::string> manejador::split(const std::string &str, char delim) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

//metodo encargado de imprimir la consola
void manejador::Consola() {
    bool seguir = true;
    std::string Comando;
    while (seguir){
        std::cout << "Escriba el comando a continuacion (si desea salir escriba 'salir')"<< std::endl;
        std::getline(std::cin, Comando); // Leer la línea completa en lugar de solo una palabra
        if(Comando.find("salir") != std::string::npos){
            seguir = false;
        } else{
            procesarComando(Comando);
        }
        Comando = "";
    }
}
//metodo encargado si se crea un nuevo grupo:
std::string manejador::CrearGrupoNuevo(std::vector<std::string> Datos, Celda * tablaNueva, ArbolAVL * NuevoArbol){
    int val = 10;
    int elementos = 0;
    std::string orden = "";
    Celda *Rehash = nullptr;
    for (const auto &campo : Datos) {
        // Eliminar espacios en blanco al inicio y al final del campo
        std::string campo_trimmed = campo;
        campo_trimmed.erase(0, campo_trimmed.find_first_not_of(" "));
        campo_trimmed.erase(campo_trimmed.find_last_not_of(" ") + 1);
        // Dividir el campo en nombre y tipo
        std::vector<std::string> nombre_tipo = split(campo_trimmed, ' ');
        if (nombre_tipo.size() == 2) {
            auto * Na = new ArbolAVL();
            ManejadorHash.insertarTabla2(&val, nombre_tipo[0], Na,tablaNueva,&elementos,0.9,Rehash);
            orden += nombre_tipo[0]+" ";
        }
    }
    return orden;
}
void manejador::imprimirTabla(){
    ManejadorHash.imprimirTabla(Th1,valorArreglo);
}