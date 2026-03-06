#include "../include/Curve.h"
#include <iostream>
#include <cmath>


Curve::Curve(Vertex p1, Vertex p2, Vertex p3, Vertex p4)
{
    this->P0 = p1;
    this->P1 = p2;
    this->P2 = p3;
    this->P3 = p4;
}

void Curve::printPoint(float t)
{
    if(t < 0.0f || t > 1.0f)
    {
        cout << "t debe estar en el rango [0,1]" << endl;
        return;
    }

    arma::Mat<float> MB = {
        { -1,  3, -3,  1},
        {  3, -6,  3,  0},
        { -3,  3,  0,  0},
        {  1,  0,  0,  0}
    };

    arma::Mat<float> GB = {
        { P0.get_x(), P0.get_y(), P0.get_z() },
        { P1.get_x(), P1.get_y(), P1.get_z() },
        { P2.get_x(), P2.get_y(), P2.get_z() },
        { P3.get_x(), P3.get_y(), P3.get_z() }
    };

    float t2 = t * t;
    float t3 = t2 * t;

    arma::Row<float> T = { t3, t2, t, 1.0f };

    arma::Mat<float> Qt = T * MB * GB;

    Vertex result(Qt(0,0), Qt(0,1), Qt(0,2));

    cout << "P(" << t << ") = ";
    result.print();
    cout << endl;
}

float Curve::approximateLength(float dt)
{
    arma::Mat<float> MB = {
        { -1,  3, -3,  1},
        {  3, -6,  3,  0},
        { -3,  3,  0,  0},
        {  1,  0,  0,  0}
    };

    arma::Mat<float> GB = {
        { P0.get_x(), P0.get_y(), P0.get_z() },
        { P1.get_x(), P1.get_y(), P1.get_z() },
        { P2.get_x(), P2.get_y(), P2.get_z() },
        { P3.get_x(), P3.get_y(), P3.get_z() }
    };

    float length = 0.0f;

    arma::Row<float> T0 = {0, 0, 0, 1};
    arma::Mat<float> Q0 = T0 * MB * GB;
    Vertex prev(Q0(0,0), Q0(0,1), Q0(0,2));

    for(float t = dt; t <= 1.0f; t += dt)
    {
        arma::Row<float> T = { t*t*t, t*t, t, 1 };
        arma::Mat<float> Qt = T * MB * GB;

        Vertex current(Qt(0,0), Qt(0,1), Qt(0,2));

        float dx = current.get_x() - prev.get_x();
        float dy = current.get_y() - prev.get_y();
        float dz = current.get_z() - prev.get_z();

        float segment = sqrt(dx*dx + dy*dy + dz*dz);

        length += segment;
        prev = current;
    }

    return length;
}