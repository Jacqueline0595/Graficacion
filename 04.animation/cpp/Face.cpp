#include "../include/Face.h"
#include <iostream>

using namespace std;

Face::Face(vector <unsigned int> vindex)
{
    this->vindex = vindex;
}

void Face::printPoly()
{
    int lados = vindex.size();

    if (lados == 3)
        cout << "Es un triangulo" << endl;
    else if (lados == 4)
        cout << "Es un cuadrilatero" << endl;
    else if (lados == 5)
        cout << "Es un pentagono" << endl;
    else if (lados == 6)
        cout << "Es un hexagono" << endl;
    else if (lados == 7)
        cout << "Es un heptagono" << endl;
    else if (lados == 8)
        cout << "Es un octogono" << endl;
    else if (lados >= 9)
        cout << "Es un ngon" << endl;
    else
        cout << "Es un poligono sin clasificacion o invalido" << endl;
}