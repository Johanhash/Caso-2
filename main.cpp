#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"

using namespace std;

int main() {
    Grafo g("grafop.txt");
    g.generaListaV();
    //g.mostrarListaV();
    g.generarMatAdj();
    cout << "\n Lista Adyacente" << endl;
    g.mostrarMatAdj();
    cout << "\nRecorrido en profundidad:" << endl;
    g.recorridoEnProf("Pachuca");
    g.inicializarVVisitados();
    cout << "\nRecorrido en anchura:" << endl;
    g.recorridoEnAnch("Pachuca");

    return 0;
}