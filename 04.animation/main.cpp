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

    for(float theta = 0.0; theta <= 50.0; theta += 5.0)
    {
        arma::Mat<float> mc = an.Rp1p2(P1, P2, theta);

        arma::Mat<float> v1p = mc * v1.h();
        cout << "Angulo: " << theta << endl;
        cout << v1p << endl;
    }

    cin.get();
    return 0;
}