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
    
    // cout << "v1p: " << v1p.t() << endl;
    // cout << "v2p: " << v2p.t() << endl;

    // paso 2 llevamos al plano YZ
    arma::Mat<float> Ry2 = an.Ry(-14.81);
    
    // cout << "v1pp: " << v1pp.t() << endl;
    // cout << "v2pp: " << v2pp.t() << endl;

    // paso 3 rotar en x para que v1pp quede sobre el eje z
    arma::Mat<float> Rx3 = an.Rx(-35.41);

    // matriz compuesta
    arma::Mat<float> MC = Rx3 * Ry2 * T1;

    arma::Mat<float> v1p = MC * v1.h();
    arma::Mat<float> v2p = MC * v2.h();

    cout << "v1p: " << v1p.t() << endl;
    cout << "v2p: " << v2p.t() << endl; 
    return 0;
}