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
#include "Objetos/Controlador.h"


manejador::manejador(std::string * a) {
    Th1 = a;
    valorArreglo = 5;
    elementos = 0;
};
std::string direccionDeMemoriaComoString(Nodo* direccion) {
    // Usamos reinterpret_cast para convertir la dirección de memoria a un tipo entero
    // Luego, lo convertimos a una cadena utilizando std::to_string
    std::stringstream ss;
    ss << reinterpret_cast<std::uintptr_t>(direccion); // Convertir dirección de memoria a entero
    return ss.str(); // Devuelve la dirección de memoria como una cadena
}
//metodo para Crear el arbol
std::string manejador::crearArbol(std::string Tipo){
    auto * Le = new Controlador();
    Informacion Infor = *new Informacion("", Tipo, Le);
    Le->Info = ManejadorArbol.insertar(Infor);
    return (direccionDeMemoriaComoString(Le->Info));
}
//metodo principal
void manejador::procesarComando(const std::string &comando){
    std::vector<std::string> palabras = split(comando, ' ');
    if (palabras.size() < 3) {
        std::cout << "Error: Comando inválido." << std::endl;
        return;
    }
    if (palabras[0] == "ADD" && palabras[1] == "NEW-GROUP") {
        auto* tablaNueva = new std::string[5];
        // Obtener el índice donde comienza la sección "FIELDS"
        size_t indice_fields = comando.find("FIELDS");
        if (indice_fields != std::string::npos) {
            std::string fields_section = comando.substr(indice_fields +8); // El +7 es para saltar "FIELDS "
            fields_section.pop_back();
            fields_section.pop_back();
            // Dividir los campos
            std::vector<std::string> campos = split(fields_section, ',');
            CrearGrupoNuevo(campos,tablaNueva);
            std::stringstream ss;
            ss << &tablaNueva[0];
            std::string direccionDeMemoria = ss.str();
            ManejadorHash.insertar(&valorArreglo, palabras[2], direccionDeMemoria,Th1,&elementos,0.6);
            std::cout << "chi funco." << std::endl;
        }
    } else if (palabras[0] == "ADD" && palabras[1] == "CONTACT" && palabras[2] == "IN") {
        std::string Direccion = reinterpret_cast<const char *>(ManejadorHash.buscar(palabras[3], valorArreglo, Th1));

    } else if (palabras[0] == "FIND" && palabras[1] == "CONTACT" && palabras[2] == "IN") {
        // Procesar comando para buscar contacto
        if (palabras.size() < 7 || palabras[3] != "CONTACT-FIELD" || palabras[5] != "=") {
            std::cout << "Error: Comando inválido." << std::endl;
            return;
        }
        std::cout << "Buscando contacto en el grupo: " << palabras[3] << std::endl;
        // Aquí puedes llamar a una función para manejar la búsqueda de contactos
    } else {
        std::cout << "Error: Comando no reconocido." << std::endl;
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
void manejador::CrearGrupoNuevo(std::vector<std::string> Datos, std::string* tablaNueva){
    int val = 5;
    int elementos = 0;
    for (const auto &campo : Datos) {
        // Eliminar espacios en blanco al inicio y al final del campo
        std::string campo_trimmed = campo;
        campo_trimmed.erase(0, campo_trimmed.find_first_not_of(" "));
        campo_trimmed.erase(campo_trimmed.find_last_not_of(" ") + 1);
        // Dividir el campo en nombre y tipo
        std::vector<std::string> nombre_tipo = split(campo_trimmed, ' ');
        if (nombre_tipo.size() == 2) {
            ManejadorHash.insertar(&val, nombre_tipo[0],crearArbol(nombre_tipo[1]),tablaNueva,&elementos,0.6);
        }
    }
}

