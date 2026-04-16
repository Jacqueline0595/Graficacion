#include "../include/Animation.h"

Animation::Animation()
{

}

vector<Vertex> Animation::line(Vertex v1, Vertex v2, float dt)
{
    vector <Vertex> l = {};
    for(float t = 0.0; t<= 1.0+dt;t+=dt)
    {
        Vertex v = v1 + (v2 - v1) * t;
        l.push_back(v);
    }
    return(l);
}

vector<Vertex> Animation::bezier(Vertex P1, Vertex P2, Vertex P3, Vertex P4, float dt)
{
    vector <Vertex> c = {};
    arma::Mat<float> MB = {{ -1, 3, -3 , 1},
                           { 3, -6, 3, 0},
                           { -3, 3, 0, 0},
                           { 1, 0, 0, 0}}; 
    arma::Mat<float> GB = { { P1.get_x(), P1.get_y(), P1.get_z() },
                            { P2.get_x(), P2.get_y(), P2.get_z() }, 
                            { P3.get_x(), P3.get_y(), P3.get_z() }, 
                            { P4.get_x(), P4.get_y(), P4.get_z() }};

    for(float t = 0.0; t < 1.0; t += dt)
    {
        arma::Row<float> T = { powf(t, 3), powf(t, 2), t, 1.0f };
        arma::Mat<float> Qt = T * MB * GB;
        Vertex v(Qt.at(0,0), Qt.at(0,1), Qt.at(0,2));
        c.push_back(v);
    }

    return(c);
}

arma::Mat<float> Animation::T(float dx, float dy, float dz)
{
    arma::Mat<float> tr = { {1, 0, 0, dx},
                            {0, 1, 0, dy},
                            {0, 0, 1, dz},
                            {0, 0, 0, 1}};
    return(tr);
}

arma::Mat<float> Animation::S(float sx, float sy, float sz)
{
    arma::Mat<float> tr = { {sx, 0, 0, 0},
                            {0, sy, 0, 0},
                            {0, 0, sz, 0},
                            {0, 0, 0, 1}};
    return(tr);
}

arma::Mat<float> Animation::Rx(float theta)
{
    float rtheta = theta * M_PI / 180;
    arma::Mat<float> r = { {1, 0, 0, 0},
                            {0, cos(rtheta), -sin(rtheta), 0},
                            {0, sin(rtheta), cos(rtheta), 0},
                            {0, 0, 0, 1}};
    return(r);
}

arma::Mat<float> Animation::Ry(float theta)
{
    float rtheta = theta * M_PI  / 180;
    arma::Mat<float> r = { {cos(rtheta), 0, sin(rtheta), 0},
                            {0, 1, 0, 0},
                            {-sin(rtheta), 0, cos(rtheta), 0},
                            {0, 0, 0, 1}};
    return(r);
}

arma::Mat<float> Animation::Rz(float theta)
{
    float rtheta = theta * M_PI  / 180;
    arma::Mat<float> r = { {cos(rtheta), -sin(rtheta), 0, 0},
                            {sin(rtheta), cos(rtheta), 0, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 1}};
    return(r);
}

arma::Mat<float> Animation::Rp1p2(Vertex P1, Vertex P2, float theta)
{
    // paso 1
    arma::Mat<float> T1 = this->T(-P1.get_x(), -P1.get_y(), -P1.get_z());

    // paso 2 
    float D1 = sqrt(powf(P2.get_z()-P1.get_z(), 2) + powf(P2.get_x()-P1.get_x(), 2));
    arma::Mat<float> Ry2 = { { (P2.get_z()-P1.get_z()) / D1, 0, -(P2.get_x()-P1.get_x()) / D1, 0 },
                            { 0, 1, 0, 0 },
                            { (P2.get_x()-P1.get_x()) / D1, 0, (P2.get_z()-P1.get_z()) / D1, 0 },
                            { 0, 0, 0, 1 } };
                            
    // paso 3
    float D2 = sqrt( powf(P2.get_x()-P1.get_x(), 2) + powf(P2.get_y()-P1.get_y(), 2) + powf(P2.get_z()-P1.get_z(), 2) );
    arma::Mat<float> Rx3 = { { 1, 0, 0, 0 },
                            { 0, D1 / D2, -(P2.get_y()-P1.get_y()) / D2, 0 },
                            { 0, (P2.get_y()-P1.get_y()) / D2, D1 / D2, 0 },
                            { 0, 0, 0, 1 } };

    // paso 4: rotar 180 grados en z
    arma::Mat<float> Rz4 = this->Rz(theta);

    // regresar
    arma::Mat<float> Rx5 = Rx3.i();
    arma::Mat<float> Ry6 = Ry2.i();
    arma::Mat<float> T7 = T1.i();
                            
    arma::Mat<float> MC = T7 * Ry6 * Rx5 * Rz4 * Rx3 * Ry2 * T1;

    return (MC);
}
