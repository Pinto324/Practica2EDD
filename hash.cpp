//
// Created by branp on 31/03/2024.
//

#include "hash.h"
#include "TablasHash/Celda.h"

hash::hash() {

}

//metodos privados
//metodo para el hash
int funcionHash(const std::string& clave, const int size) {
    int hash = 0;
    for (char c : clave) {
        hash += c;
    }
    return hash % size;
}

void rehash(int* size, Celda*& tablaVieja) {
    int nuevoTamano = *size * 2;
    auto* nuevaTabla = new Celda[nuevoTamano];
    for (int i = 0; i < *size; ++i) {
        if (!tablaVieja[i].orden.empty()) {
            int nuevoIndice = funcionHash(tablaVieja[i].Nombre, nuevoTamano);
            while (!nuevaTabla[nuevoIndice].orden.empty()) {
                nuevoIndice = (nuevoIndice + 1) % nuevoTamano; // Manejar colisiones con linear probing
            }
            nuevaTabla[nuevoIndice] = tablaVieja[i];
        }
    }
    delete[] tablaVieja;
    tablaVieja = nuevaTabla;
    *size = nuevoTamano;
}

void hash::insertar(int *size, const std::string& nombre, const std::string& Meter, Celda * datos, int * elementos, double carga, const std::string& cadena) {
    if ((double)*elementos / *size >= carga) {
        rehash(size, datos);
    }

    int indice = funcionHash(nombre, *size);
    while (!datos[indice].orden.empty()) {
        indice = (indice + 1) % *size; // Manejar colisiones con linear probing
    }
    const std::string& info = Meter;
    const std::string& orden = cadena;
    datos[indice].tabla = info;
    datos[indice].orden = orden;
    (*elementos)++;
}
//metodo de hash para buscar
std::string* hash::buscar(const std::string& nombre, int size, std::string* datos) {
    int indice = funcionHash(nombre, size);
    int intentos = 0;
    while (!datos[indice].empty() && datos[indice] != nombre) {
        indice = (indice + 1) % size; // Avanzar al siguiente índice
        intentos++;
        if (intentos == size) { // Evitar bucle infinito
            break;
        }
    }
    if (datos[indice] == nombre) {
        return &datos[indice];
    } else {
        return nullptr;
    }
}