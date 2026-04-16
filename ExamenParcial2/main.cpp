#include <iostream>
#include <armadillo>
#include "../include/Animation.h"

using namespace std;

int main()
{
    Animation an;

    Vertex P1(0, 0, 0);
    Vertex P2(3.8, 4.5, 0);

    cout << "Espaciales: " << endl;
    P1.print();
    cout << endl;
    P2.print();
    cout << endl;

    cout << "Homogeneas: " << endl;
    arma::Col<float> hP1 = P1.h();
    arma::Col<float> hP2 = P2.h();

    hP1.print("hP1:");
    cout << endl;
    hP2.print("hP2:");
    cout << endl;

    cout << "Regresar a espaciales: " << endl;

    Vertex eP1 = P1.homoToEsp(hP1, 1);
    Vertex eP2 = P2.homoToEsp(hP2, 1);
    
    eP1.print();
    cout << endl;
    eP2.print();
    cout << endl;
    return(0);
}