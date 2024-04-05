//
// Created by branp on 31/03/2024.
//

#include <iostream>
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

Celda* rehash(int* size, Celda*& tablaVieja, Celda *nuevaTabla) {
    int nuevoTamano = *size * 2;
    nuevaTabla = new Celda[nuevoTamano];
    for (int i = 0; i < *size; ++i) {
        if (!tablaVieja[i].Nombre.empty()) {
            std::string xd= tablaVieja[i].Nombre;
            int nuevoIndice = funcionHash(xd, nuevoTamano);
            while (!nuevaTabla[nuevoIndice].orden.empty()) {
                nuevoIndice = (nuevoIndice + 1) % nuevoTamano; // Manejar colisiones con linear probing
            }
            nuevaTabla[nuevoIndice] = tablaVieja[i];
        }
    }
    delete[] tablaVieja;
    tablaVieja = nuevaTabla;
    *size = nuevoTamano;
    return tablaVieja;
}

Celda * hash::insertarTabla1(int *size, const std::string& nombre, Celda* Meter, Celda * datos, int * elementos, double carga, const std::string& cadena, Celda *asd) {
    if ((double)*elementos / *size >= carga) {
        datos = rehash(size, datos, asd);
    }

    int indice = funcionHash(nombre, *size);
    while (!datos[indice].orden.empty()) {
        indice = (indice + 1) % *size; // Manejar colisiones con linear probing
    }
    const std::string& orden = cadena;
    datos[indice].Tabla = Meter;
    datos[indice].orden = orden;
    datos[indice].Nombre = nombre;
    (*elementos)++;
    return datos;
}
void hash::insertarTabla2(int *size, const std::string& nombre, ArbolAVL* Meter, Celda * datos, int * elementos, double carga, Celda* rej) {
    if ((double)*elementos / *size >= carga) {
        rehash(size, datos, rej);
    }
    int indice = funcionHash(nombre, *size);
    while (!datos[indice].Nombre.empty()) {
        indice = (indice + 1) % *size; // Manejar colisiones con linear probing
    }
    datos[indice].Arbol = Meter;
    datos[indice].Nombre = nombre;
    (*elementos)++;
}
//metodo de hash para buscar y devolver la dirección de memoria
Celda * hash::buscarCelda(const std::string& nombre, int size, Celda* datos) {
    int indice = funcionHash(nombre, size);
    int intentos = 0;
    while (!datos[indice].Tabla && datos[indice].Nombre != nombre) {
        indice = (indice + 1) % size; // Avanzar al siguiente índice
        intentos++;
        if (intentos == size) { // Evitar bucle infinito
            break;
        }
    }
    if (datos[indice].Nombre == nombre) {
        return datos[indice].Tabla;
    } else {
        return nullptr;
    }
}

//metodo de hash para buscar y devolver la dirección de memoria
std::string hash::buscarCeldaOrden(const std::string& nombre, int size, Celda* datos) {
    int indice = funcionHash(nombre, size);
    int intentos = 0;
    while (!datos[indice].Tabla && datos[indice].Nombre != nombre) {
        indice = (indice + 1) % size; // Avanzar al siguiente índice
        intentos++;
        if (intentos == size) { // Evitar bucle infinito
            break;
        }
    }
    if (datos[indice].Nombre == nombre) {
        return datos[indice].orden;
    } else {
        return "";
    }
}
//metodo de hash para buscar el arbol en mi tabla 2
ArbolAVL * hash::buscarArbol(const std::string& nombre, int size, Celda* datos) {
    int indice = funcionHash(nombre, size);
    int intentos = 0;
    while (!datos[indice].Arbol && datos[indice].Nombre != nombre) {
        indice = (indice + 1) % size; // Avanzar al siguiente índice
        intentos++;
        if (intentos == size) { // Evitar bucle infinito
            break;
        }
    }
    if (datos[indice].Nombre == nombre) {
        ArbolAVL * XD = datos[indice].Arbol;
        return datos[indice].Arbol;
    } else {
        return nullptr;
    }
}
//metodo para imprimir tabla
void hash::imprimirTabla(Celda* c, int size){
    for (size_t i = 0; i < size; ++i) {
        if (c) {
            std::cout << c->Nombre << " | tabla:" << c->Tabla <<"|Arbol: "<<c->Arbol<<std::endl;
            c++;
        } else {
            std::cout << c->Nombre << " | tabla:" <<std::endl;
            c++;
            std::cout << "El puntero es nulo." << std::endl;
        }

    }
}