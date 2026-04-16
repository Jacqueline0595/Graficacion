#include <iostream>
#include "../include/Vertex.h"

using namespace std;

Vertex::Vertex(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vertex::print()
{
    cout << "(" << this->x << ", " << this->y << ", " << this->z << ")";
}

Vertex Vertex::operator-(Vertex op2)
{
    Vertex v((this->x - op2.x), (this->y - op2.y), (this->z - op2.z));
    return(v);
}

Vertex Vertex::operator*(float op2)
{
    Vertex v((this->x * op2), (this->y * op2), (this->z * op2));
    return(v);
}

Vertex Vertex::operator+(Vertex op2)
{
    Vertex v((this->x + op2.x), (this->y + op2.y), (this->z + op2.z));
    return(v);
}

float Vertex::get_x() 
{
    return(this->x);
}
float Vertex::get_y() 
{
    return(this->y);
}
float Vertex::get_z() 
{
    return(this->z);
}

void Vertex::set_x(float x) 
{
    this->x = x;
}

void Vertex::set_y(float y) 
{
    this->y = y;
}

void Vertex::set_z(float z) 
{
    this->z = z;
}

arma::Col<float> Vertex::h()
{
    arma::Col<float> ch = {this->x, this->y, this->z, 1};
    return(ch);
}

// Es casi la misma, solo que aqui se pasa el valor de la w
arma::Col<float> Vertex::EspToHomogenous(float w)
{
    arma::Col<float> homo = {};

    // Con una validacion por si acaso
    if(w > 0)
        homo = {this->x, this->y, this->z, w};

    return(homo);
}

Vertex Vertex::homoToEsp(arma::Col<float> P, float w)
{
    Vertex P1 = {};

    if(w > 0)
    {
        P1.set_x(P(0) / w);
        P1.set_y(P(1) / w);
        P1.set_z(P(2) / w);
    }

    return(P1);
}