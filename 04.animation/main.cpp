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

    // punto a mover
    Vertex P1(0, 0, 0); 
    Vertex P2(10, 10, 10);

    Vertex P3(5, 5, 5);

    // paso 1

    arma::Mat<float> T1 = an.T(-P1.get_x(), -P1.get_y(), -P1.get_z());
    // paso 2 
    float D1 = sqrt(powf(P2.get_z()-P1.get_z(), 2) + powf(P2.get_x()-P1.get_x(), 2));
    arma::Mat<float> Ry2 = { { P2.get_z()-P1.get_z() / D1, 0, P2.get_x()-P1.get_x() / D1, 0},
                            { 0, 1, 0, 0},
                            { (P2.get_x()-P1.get_x()) / D1, 0, (P2.get_z()-P1.get_z()) / D1, 0},
                            { 0, 0, 0, 1} };
    // paso 3
    float D2 = sqrt( powf(P2.get_x()-P1.get_x(), 2) + powf(P2.get_y()-P1.get_y(), 2) + powf(P2.get_z()-P1.get_z(), 2) );
    arma::Mat<float> Rx3 = { { 1, 0, 0, 0},
                            { 0, D1/D2, -(P2.get_y()-P1.get_y()) / D2, 0},
                            { 0, (P2.get_y()-P1.get_y()) / D2, D1 / D2, 0},
                            { 0, 0, 0, 1} };

    // paso 4
    arma::Mat<float> Rz4 = an.Rz(180);

    // regresar
    arma::Mat<float> Rx5 = Rx3.i();
    arma::Mat<float> Ry6 = Ry2.i();
    arma::Mat<float> T7 = T1.i();
                            
    arma::Mat<float> MC = T7 * Ry6 * Rx5 * Rz4 * Rx3 * Ry2 * T1;

    arma::Mat<float> p1p = MC * v1.h();

    cout << p1p << endl;

    return 0;
}