#include "Vertice.h"

Vertice::Vertice() {
    nomV = "";
    visitado = false;
}

Vertice::Vertice(string nom) {
    nomV = nom;
    visitado = false;
}

string Vertice::getNomV() {
    return nomV;
}

void Vertice::setNomV(string nom) {
    nomV = nom;
}

bool Vertice::getVisitado() {
    return visitado;
}

void Vertice::setVisitado(bool v) {
    visitado = v;
}