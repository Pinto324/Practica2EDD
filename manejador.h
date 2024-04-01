//
// Created by branp on 30/03/2024.
//

#ifndef GESTIONCONTACTOS_MANEJADOR_H
#define GESTIONCONTACTOS_MANEJADOR_H


#include <vector>
#include <string>

class manejador {
    private:

    public:
        manejador();
        void Consola();

    std::vector<std::string> split(const std::__cxx11::basic_string<char> &str, char delim);

    void procesarComando(const std::string &comando);
};


#endif //GESTIONCONTACTOS_MANEJADOR_H
