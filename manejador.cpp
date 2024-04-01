//
// Created by branp on 30/03/2024.
//

#include "manejador.h"
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

manejador::manejador(std::string * a) {
    Th1 = a;
    valorArreglo = 5;
    elementos = 0;
};
//metodos privados
//metodo para el hash
int funcionHash(const std::string& clave, const int size) {
    int hash = 0;
    for (char c : clave) {
        hash += c;
    }
    return hash % size;
}

void rehash(int* size, std::string*& tablaVieja) {
    int nuevoTamano = *size * 2;
    auto* nuevaTabla = new std::string[nuevoTamano];

    // Reinsertar todos los elementos en la nueva tabla hash
    for (int i = 0; i < *size; ++i) {
        if (!tablaVieja[i].empty()) {
            int nuevoIndice = funcionHash(tablaVieja[i], nuevoTamano);
            while (!nuevaTabla[nuevoIndice].empty()) {
                nuevoIndice = (nuevoIndice + 1) % nuevoTamano; // Manejar colisiones con linear probing
            }
            nuevaTabla[nuevoIndice] = tablaVieja[i];
        }
    }

    // Liberar la memoria de la antigua tabla
    delete[] tablaVieja;

    // Actualizar la tabla y el tamaño
    tablaVieja = nuevaTabla;
    *size = nuevoTamano;
}

void insertar(int *size, const std::string& nombre, std::string* Meter, std::string* datos, int * elementos, double carga) {
    if ((double)*elementos / *size >= carga) {
        rehash(size, datos);
    }

    int indice = funcionHash(nombre, *size);
    while (!datos[indice].empty()) {
        indice = (indice + 1) % *size; // Manejar colisiones con linear probing
    }
    std::cout << &Meter<< std::endl;
    datos[indice - 1] = *Meter;
    (*elementos)++;
}

//metodo para Crear el arbol
std::string* crearArbol(){
    return (std::string *) "XD";
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
            std::string fields_section = comando.substr(indice_fields + 7); // El +7 es para saltar "FIELDS "
            fields_section.pop_back();
            fields_section.pop_back();
            // Dividir los campos
            std::vector<std::string> campos = split(fields_section, ',');
            insertar(&valorArreglo, palabras[2], CrearGrupoNuevo(campos,tablaNueva),Th1,&elementos,0.6);
        }
    } else if (palabras[0] == "ADD" && palabras[1] == "CONTACT" && palabras[2] == "IN") {
        // Procesar comando para agregar contacto
        if (palabras.size() < 5) {
            std::cout << "Error: Comando inválido." << std::endl;
            return;
        }
        std::cout << "Agregando contacto al grupo: " << palabras[3] << std::endl;
        // Aquí puedes llamar a una función para manejar la inserción de contactos
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
std::string* manejador::CrearGrupoNuevo(std::vector<std::string> Datos, std::string* tablaNueva){
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
            insertar(&val, nombre_tipo[0],crearArbol(),tablaNueva,&elementos,0.6);
        }
    }
    return tablaNueva;
}

