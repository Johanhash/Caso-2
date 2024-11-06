#ifndef COLA_H
#define COLA_H
#include "Nodo.h"


class Cola
{
    Nodo* inicio;
    Nodo* fin;
public:
    Cola();
    void enqueue(Vertice v);
    Vertice dequeue();
    bool colaVacia();
    Vertice first();

};

#endif // COLA_H
