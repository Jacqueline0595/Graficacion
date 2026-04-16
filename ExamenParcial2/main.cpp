#include <iostream>
#include <armadillo>
#include "../include/Animation.h"

using namespace std;

int main()
{
    Animation an;

    // Reactivo 1

    // Un valor ya esta en el origen, solo voy a mover el otro punto
    Vertex P1(0, 0, 0);
    Vertex P2(3.8, 4.5, 0);

    cout << "Puntos a homogeneas: " << endl;
    arma::Col<float> hP1 = P1.h();
    arma::Col<float> hP2 = P2.h();

    // Calculo para alinear el punto con el eje x

    /* 
        Para alinearlo se calcula el angulo usando 
        tangente porque conocemos CO y CA.
        Entonces es tan^-1 ( 4.5 / 3.8 ) = 49.8207
    */

    float theta = atan2(P2.get_y(), P2.get_x()) * 180 / M_PI;

    // Alinear con x rotando en z (se puede poner directamente 49.8207)
    arma::Mat<float> R1 = an.Rz(-theta);

    // rotar 180 grados en x para que quede en -x
    arma::Mat<float> R2 = an.Rz(180);

    // Calculo de la matriz compuesta
    arma::Mat<float> MC = R2 * R1;

    MC.print("Matriz compuesta: ");

    // Extra: Añadi la multiplicacion de los puntos por la matriz
    arma::Col<float> hP1_rot = MC * hP1;
    arma::Col<float> hP2_rot = MC * hP2;

    // Para validar que sea correcto, calcule la distancia entre los puntos originales
    float D = sqrt(powf(P2.get_x()-P1.get_x(), 2) + powf(P2.get_y()-P1.get_y(), 2) + powf(P2.get_z()-P1.get_z(), 2));

    cout << "Distancia entre puntos: " << D << endl;

    // Los converti a puntos espaciales

    // Aplique el reactivo 3 aqui

    Vertex eP1 = P1.homoToEsp(hP1_rot, hP1_rot(3));
    Vertex eP2 = P2.homoToEsp(hP2_rot, hP2_rot(3));

    cout << "Puntos finales en el espacio" << endl;
    
    eP1.print();
    cout << endl;
    eP2.print();
    cout << endl;
    cout << endl;

    // Reactivo 2

    /*
        Considerando la multiplicacion
        xp = 1*x + 0*y + shx*z + 1*1(o la w) 
        yp = 0*x + 1*y + shy*z + 1*1(o la w)
        zp = 0*x + 0*y + 1*z + 1*1(o la w)

        quedan 
        xp = x + shx*z 
        yp = y + shy*z
        que nos dice que se esta moviendo x y y segun el valor de z
        y que z no cambia
    */

    // Reactivo 3

    // Punto original
    Vertex PE1 = {9, 4, 5};

    cout << "Punto original: " << endl;
    PE1.print();
    cout << endl;
    cout << endl;

    arma::Col<float> hPE1 = PE1.EspToHomogenous(2);

    hPE1.print("Punto homogenea: ");
    cout << endl;

    Vertex ePE1 = PE1.homoToEsp(hPE1, hPE1(3));
    cout << "Punto espacial de nuevo: " << endl;
    ePE1.print();

    return(0);
}