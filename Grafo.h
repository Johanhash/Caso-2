#ifndef GRAFO_H
#define GRAFO_H
#include <fstream>
#include "Vertice.h"


class Grafo {

    int* matAdj; / representa las aristas /
        int numV;
    fstream arch;
    int buscarVertice(string nomVertice);
public:
    Vertice* listaV;
    Grafo(string nomArch);
    void generaListaV();
    void generarMatAdj();
    void mostrarListaV();
    void mostrarMatAdj();
    void inicializarVVisitados();
    void recorridoEnProf(string origen);
    void recorridoEnAnch(string origen);

};

#endif // GRAFO_H

