#include "Cola.h"


Cola::Cola()
{
    inicio = fin = nullptr;
}

void Cola::enqueue(Vertice v) {
    Nodo* p = new Nodo(v);
    if (inicio == nullptr) {
        inicio = p;
        fin = inicio;
    }
    else {
        fin->sig = p;
        fin = p;
    }
}
Vertice Cola::dequeue() {
    Vertice v;
    Nodo* q = inicio;
    if (inicio != nullptr) {
        v = inicio->getV();
        inicio = inicio->sig;
        delete q;
    }
    return v;
}

Vertice Cola::first() {
    Vertice v;
    if (inicio != nullptr)
        return inicio->getV();
    else
        return v;
}

bool Cola::colaVacia() {
    return ((inicio == nullptr) ? true : false);
}