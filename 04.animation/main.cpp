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
    Vertex v1(-3.1, 4.7, -0.3);
    Vertex v2(0.1, -4.2, 11.8);

    // paso 1 trasladar v2 al origen
    arma::Mat<float> T1 = an.T(-v2.get_x(), -v2.get_y(), -v2.get_z());
    arma::Mat<float> v1p = T1 * v1.h();
    arma::Mat<float> v2p = T1 * v2.h();

    cout << "v1p: " << v1p.t() << endl;
    cout << "v2p: " << v2p.t() << endl;

    // v1p = (-3.2, 8.9, -12.1)
    // v2p = (0,0,0)

    // tan ^ -1 ( -3.2 / -12.1 ) = 14.8134

    // paso 2 llevamos al plano YZ
    arma::Mat<float> Ry2 = an.Ry(-14.81);
    arma::Mat<float> v1pp = Ry2 * v1p;
    arma::Mat<float> v2pp = Ry2 * v2p;

    cout << "v1pp: " << v1pp.t() << endl;
    cout << "v2pp: " << v2pp.t() << endl;

    // v1pp = (0.0008, 8.9, -12.5160)
    // v2pp = (0,0,0)

    // tan ^ -1 ( 8.9 / -12.5160 ) = -35.4162

    // paso 3 rotar en x para que v1pp quede sobre el eje z
    arma::Mat<float> Rx3 = an.Rx(-35.41);
    arma::Mat<float> v1ppp = Rx3 * v1pp;
    arma::Mat<float> v2ppp = Rx3 * v2pp;

    cout << "v1ppp: " << v1ppp.t() << endl;
    cout << "v2ppp: " << v2ppp.t() << endl; 
    return 0;
}