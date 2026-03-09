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

arma::Col<float> Vertex::h()
{
    arma::Col<float> ch = {this->x, this->y, this->z, 1};
    return(ch);
}