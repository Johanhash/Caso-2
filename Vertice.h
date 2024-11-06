#ifndef VERTICE_H
#define VERTICE_H
#include<string>

using namespace std;

class Vertice {
    string nomV;
    bool visitado;
public:
    Vertice();
    Vertice(string nom);
    string getNomV();
    void setNomV(string nom);
    bool getVisitado();
    void setVisitado(bool v);
};

#endif // VERTICE_H
