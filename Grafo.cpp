#include "Grafo.h"
#include <iostream>
#include <string>
#include <fstream>  // Asegúrate de incluir <fstream> si estás utilizando archivos
#include "Cola.h"

using namespace std;

Grafo::Grafo(string nomArch) {
    /** Obtener número de vértices, leer primera línea del archivo */
    arch.open(nomArch, ios::in); // Abre el archivo en modo lectura
    string s;
    if (arch.fail()) {
        cout << "No se puede abrir el archivo: " << nomArch << endl;
        exit(1); /** Termina la ejecución del programa */
    }
    /** Leer la primera línea */
    getline(arch, s);
    cout << "Numero de vertices = " << s << endl;

    /** Convertir cadena a número */
    numV = stoi(s);
    cout << "Numero de vertices = " << numV << endl;

    listaV = new Vertice[numV]; // Crea un array de vértices

    /** Crear matriz de adyacencia */
    matAdj = new int* [numV];
    for (int i = 0; i < numV; i++) {
        listaV[i].setNomV("");
        matAdj[i] = new int[numV];
        for (int j = 0; j < numV; j++) {
            matAdj[i][j] = 0;
        }
    }
}

void Grafo::generaListaV() {
    string s;
    for (int i = 0; i < numV; i++) {
        getline(arch, s);
        listaV[i].setNomV(s);
    }
}

void Grafo::generarMatAdj() {
    string s, cad, ori, des;
    while (!arch.eof()) {
        getline(arch, s);
        int pos1 = 0;
        int pos2 = 0;
        int peso = 0;
        int ren, col;
        / separar origen, destino, peso /
            pos2 = s.find("*", pos1);
        ori = s.substr(pos1, pos2 - pos1);
        cout << "origen: " << ori << endl;
        ren = buscarVertice(ori); / posicion del vertice en la lista /
            cout << ren << endl;
        pos1 = pos2 + 1;
        pos2 = s.find("*", pos1);
        des = s.substr(pos1, pos2 - pos1);
        cout << "destino: " << des << endl;
        col = buscarVertice(des); / posicion del vertice en la lista /
            cout << col << endl;
        pos1 = pos2 + 1;
        cad = s.substr(pos1, s.length() - pos1);
        cout << "peso: " << cad << endl;
        peso = stoi(cad);
        matAdj[ren][col] = peso;
    }
}

int Grafo::buscarVertice(string nomV) {
    int i = 0;
    while ((i < numV) && (listaV[i].getNomV() != nomV)) {
        i++;
    }
    if (i < numV)
        return i;
    else
        return -1;
    //return ((i<numV)?i:-1);
}

void Grafo::mostrarListaV() {
    for (int i = 0; i < numV; i++) {
        cout << listaV[i].getNomV() << endl;
    }
}

void Grafo::mostrarMatAdj() {
    for (int i = 0; i < numV; i++) {
        for (int j = 0; j < numV; j++) {
            cout << matAdj[i][j] << "\t";
        }
        cout << endl;
    }
}

void Grafo::inicializarVVisitados() {
    for (int i = 0; i < numV; i++)
        listaV[i].setVisitado(false);
}

void Grafo::recorridoEnProf(string origen) {
    int inOrigen = buscarVertice(origen);
    if (inOrigen == -1) {
        cout << "Vertice no encontrado en el grafo." << endl;
        return;
    }

    listaV[inOrigen].setVisitado(true);
    cout << listaV[inOrigen].getNomV() << endl;
    int j = 0;
    while ((j < numV)) {
        if ((matAdj[inOrigen][j] != 0) && (!listaV[j].getVisitado()))
            recorridoEnProf(listaV[j].getNomV());
        j++;

    }
}

void Grafo::recorridoEnAnch(string origen) {
    Cola c;
    Vertice v;
    Vertice listaVRecorrido[numV];
    int k = 0;
    int j = 0;
    int inOrigen = buscarVertice(origen);
    if (inOrigen == -1) {
        cout << "Vertice no encontrado en el grafo." << endl;
        return;
    }

    listaV[inOrigen].setVisitado(true);
    c.enqueue(listaV[inOrigen]);
    while (!c.colaVacia()) {
        / Obtener elemento de cola /
            v = c.dequeue();
        listaVRecorrido[k] = v;
        inOrigen = buscarVertice(v.getNomV());
        / inOrigen = buscarVertice(/*listaV[]);/
        /meter adyacentes a cola/
    for(int j=0; j<numV; j++){
        if((matAdj[inOrigen][j]!=0) && (listaV[j].getVisitado()==false)){
            listaV[j].setVisitado(true);
            c.enqueue(listaV[j]);
        }
    }
    k++;
}
for (j=0; j<numV; j++)
    cout<<listaVRecorrido[j].getNomV()<<endl;

}