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

    // objeto
    Vertex v1(3, 9, 5);

    arma::Mat<float> mc = an.Rp1p2(P1, P2, 180);
    arma::Mat<float> v1p = mc * v1.h();


    cout << v1p << endl;

    return 0;
}