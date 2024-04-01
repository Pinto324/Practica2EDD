//
// Created by branp on 31/03/2024.
//

#ifndef GESTIONCONTACTOS_HASH_H
#define GESTIONCONTACTOS_HASH_H

#include <string>
class hash {
private:

public:
    hash();
    void CrearTabla();

    void
    insertar(int *size, const std::string &nombre, std::string Meter, std::string *datos, int *elementos, double carga);

    std::string *buscar(const std::string &nombre, int size, std::string *datos);
};


#endif //GESTIONCONTACTOS_HASH_H
