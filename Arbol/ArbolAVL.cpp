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

Nodo* ArbolAVL::insertar(Nodo* nodo, Informacion dato) {
    if (nodo == nullptr) return new Nodo(dato);
    if (dato.DevolverValor() < nodo-> dato.DevolverValor()) {
        nodo->izquierdo = insertar(nodo->izquierdo, dato);
    } else if (dato.DevolverValor() > nodo->dato.DevolverValor()) {
        nodo->derecho = insertar(nodo->derecho, dato);
    } else {
        // Si el dato ya existe, no hacemos nada (en este caso, consideramos que los nombres son únicos)
        return nodo;
    }

    nodo->altura = 1 + std::max(altura(nodo->izquierdo), altura(nodo->derecho));

    int balance = obtenerBalance(nodo);

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

    return nodo;
}

void ArbolAVL::insertar(Informacion dato) {
    raiz = insertar(raiz, dato);
}

void ArbolAVL::recorrerInorden(Nodo* nodo) {
    if (nodo == nullptr) return;

    recorrerInorden(nodo->izquierdo);
    std::cout << "Nombre: " << nodo->dato.DevolverValor() << ",Tipo: " << nodo->dato.Tipo << std::endl;
    recorrerInorden(nodo->derecho);
}

void ArbolAVL::recorrerInorden() {
    recorrerInorden(raiz);
}