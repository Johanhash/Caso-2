#include "Nodo.h"


Nodo::Nodo()
{
    /*this->v = nullptr;
    v = new Vertice();*/
    sig = nullptr;
}

Nodo::Nodo(Vertice v) {
    this->v = v;
    sig = nullptr;
}
void Nodo::setV(Vertice v) {
    this->v = v;
}
Vertice Nodo::getV() {
    return v;
}