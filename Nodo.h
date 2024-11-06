#ifndef NODO_H
#define NODO_H
#include "Vertice.h"


class Nodo
{
    Vertice v;
public:
    Nodo* sig;
    Nodo();
    Nodo(Vertice v);
    void setV(Vertice v);
    Vertice getV();

};

#endif // NODO_H
