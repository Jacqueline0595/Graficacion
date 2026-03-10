#include <iostream>
#include <armadillo>
#include "include/Obj.h"
#include "include/Ply.h"
#include "include/Animation.h"

using namespace std;
using namespace arma;

int main()
{
    Animation an;
    // mover punto a traves de una trayectoria linea

    // punto a mover
    Vertex P1(-3.1, 4.7, -0.3);
    Vertex P2(0.1, -4.2, 11.8);

    // paso 1
    arma::Mat<float> T = an.T(-P1.get_x(), -P1.get_y(), -P1.get_z());
    // paso 2 
    float D1 = sqrt(powf(P2.get_z()-P1.get_z(), 2) + powf(P2.get_x()-P1.get_x(), 2));
    arma::Mat<float> Ry = { { P2.get_z()-P1.get_z() / D1, 0, P2.get_x()-P1.get_x() / D1, 0},
                            { 0, 1, 0, 0},
                            { -(P2.get_x()-P1.get_x()) / D1, 0, (P2.get_z()-P1.get_z()) / D1, 0},
                            { 0, 0, 0, 1} };
    // paso 3
    float D2 = sqrt(powf(P2.get_x()-P1.get_x(), 2) + powf(P2.get_y()-P1.get_y(), 2) + powf(P2.get_z()-P1.get_z(), 2));
    arma::Mat<float> Rx = { { 1, 0, 0, 0},
                            { 0, (P2.get_z()-P1.get_z()) / D2, -(P2.get_y()-P1.get_y()) / D2, 0},
                            { 0, (P2.get_y()-P1.get_y()) / D2, (P2.get_z()-P1.get_z()) / D2, 0},
                            { 0, 0, 0, 1} };
    return 0;
}