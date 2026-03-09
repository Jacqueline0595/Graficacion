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

    // paso 3
    arma::Mat<float> Rz3 = an.Rz(-40.6126);
    arma::Mat<float> v1ppp = Rz3 * v1pp;
    arma::Mat<float> v2ppp = Rz3 * v2pp;

    cout << "v1ppp: " << v1ppp.t() << endl;
    cout << "v2ppp: " << v2ppp.t() << endl;

    return 0;
}