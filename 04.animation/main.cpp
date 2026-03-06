#include <iostream>
#include <armadillo>
#include "include/Obj.h"
#include "include/Ply.h"
#include "include/Animation.h"
#include "include/Curve.h"

using namespace std;
using namespace arma;

int main()
{
    Animation an;

    // mover punto a traves de una trayectoria linea

    // punto a mover
    Vertex v1(2, 3, 7);
    Vertex v2(5, 8, 2);

    // paso 1
    arma::Mat<float> T1 = an.T(-v1.get_x(), -v1.get_y(), -v1.get_z());
    arma::Mat<float> v1p = T1 * v1.h();
    arma::Mat<float> v2p = T1 * v2.h();

    // paso 2
    arma::Mat<float> Ry2 = an.Ry(-59.0362);
    arma::Mat<float> v1pp = Ry2 * v1p;
    arma::Mat<float> v2pp = Ry2 * v2p;
    cout << "v1pp: " << v1pp.t() << endl;
    cout << "v2pp: " << v2pp.t() << endl;
    return 0;
}