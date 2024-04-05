//
// Created by branp on 1/04/2024.
//

#include <iostream>
#include "ArbolAVL.h"

int altura(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}

int obtenerBalance(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return altura(nodo->izquierdo) - altura(nodo->derecho);
}

Nodo* rotacionDerecha(Nodo* y) {
    Nodo* x = y->izquierdo;
    Nodo* T2 = x->derecho;

    x->derecho = y;
    y->izquierdo = T2;

    y->altura = std::max(altura(y->izquierdo), altura(y->derecho)) + 1;
    x->altura = std::max(altura(x->izquierdo), altura(x->derecho)) + 1;

    return x;
}

Nodo* rotacionIzquierda(Nodo* x) {
    Nodo* y = x->derecho;
    Nodo* T2 = y->izquierdo;

    y->izquierdo = x;
    x->derecho = T2;

    x->altura = std::max(altura(x->izquierdo), altura(x->derecho)) + 1;
    y->altura = std::max(altura(y->izquierdo), altura(y->derecho)) + 1;

    return y;
}

Nodo* ArbolAVL::insertar(Nodo* nodo, Informacion dato, Controlador Lista) {
    if (nodo == nullptr) {
        Lista.Info = new Nodo(dato);
        return Lista.Info;
    }

    if (dato.DevolverValor() < nodo->dato.DevolverValor()) {
        nodo->izquierdo = insertar(nodo->izquierdo, dato, Lista);
    } else if (dato.DevolverValor() > nodo->dato.DevolverValor()) {
        nodo->derecho = insertar(nodo->derecho, dato, Lista);
    } else {
        // El dato ya existe, puedes manejarlo según tus necesidades
        return nodo;
    }

    nodo->altura = 1 + std::max(altura(nodo->izquierdo), altura(nodo->derecho));

    int balance = obtenerBalance(nodo);

    // Realizar rotaciones si es necesario

    // Caso izquierda-izquierda
    if (balance > 1 && dato.DevolverValor() < nodo->izquierdo->dato.DevolverValor())
        return rotacionDerecha(nodo);

    // Caso derecha-derecha
    if (balance < -1 && dato.DevolverValor() > nodo->derecho->dato.DevolverValor())
        return rotacionIzquierda(nodo);

    // Caso izquierda-derecha
    if (balance > 1 && dato.DevolverValor() > nodo->izquierdo->dato.DevolverValor()) {
        nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        return rotacionDerecha(nodo);
    }

    // Caso derecha-izquierda
    if (balance < -1 && dato.DevolverValor() < nodo->derecho->dato.DevolverValor()) {
        nodo->derecho = rotacionDerecha(nodo->derecho);
        return rotacionIzquierda(nodo);
    }

    // Si no se requieren rotaciones, retornar el nodo sin cambios

    return nodo;
}


Nodo * ArbolAVL::insertar(Informacion dato, Controlador Lista) {
    raiz = insertar(raiz, dato, Lista);
    return raiz;
}

void ArbolAVL::recorrerInorden(Nodo* nodo) {
    if (nodo == nullptr) return;

    recorrerInorden(nodo->izquierdo);
    std::cout << "Nombre: " << nodo->dato.DevolverValor() << ",Tipo: " << nodo->dato.Tipo << std::endl;
    recorrerInorden(nodo->derecho);
}
Controlador* ArbolAVL::buscarDato(Nodo* nodo, const std::string& datoBuscado, Controlador* listaResultados) {
    if (nodo == nullptr) return listaResultados;

    listaResultados = buscarDato(nodo->izquierdo, datoBuscado, listaResultados);

    // Verificar si el dato del nodo coincide con el dato buscado
    if (nodo->dato.DevolverValor() == datoBuscado) {
        // Si coincide, agregarlo a la lista de resultados
        listaResultados= nodo->dato.Direccion;
    }

    listaResultados = buscarDato(nodo->derecho, datoBuscado, listaResultados);

    return listaResultados;
}

void ArbolAVL::recorrerInorden() {
    recorrerInorden(raiz);
}