//
// Created by branp on 30/03/2024.
//

#include "manejador.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

manejador::manejador() {

};
//metodo principal
void manejador::procesarComando(const std::string &comando){
    std::vector<std::string> palabras = split(comando, ' ');
    if (palabras.size() < 3) {
        std::cout << "Error: Comando inválido." << std::endl;
        return;
    }
    if (palabras[0] == "ADD" && palabras[1] == "NEW-GROUP") {
        // Procesar comando para agregar nuevo grupo
        std::cout << "Agregando nuevo grupo: " << palabras[2] << std::endl;
        // Aquí puedes llamar a una función para manejar la creación de grupos
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
    while (seguir){
        std::string Comando;
        std::cout << "Escriba el comando a continuacion (si desea salir escriba 'salir')";
        std::cin >> Comando;
        if(Comando.find("salir") != std::string::npos){
            seguir = false;
        } else{
            procesarComando(Comando);
        }
    }
}