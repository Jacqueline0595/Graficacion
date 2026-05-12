#include <iostream>
#include <armadillo>
#include "../include/Vertex.h"

using namespace std;

Vertex::Vertex(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->nx = 0.0;
    this->ny = 0.0;
    this->nz = 0.0;
}

void Vertex::print()
{
    cout << "(" << this->x << ", " << this->y << ", " << this->z << ")";
}

Vertex Vertex::operator+(Vertex op2)
{
    Vertex v((this->x + op2.x), (this->y + op2.y), (this->z + op2.z));
    return(v);
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

float Vertex::get_nx()
{
    return(this->nx);
}

float Vertex::get_ny()
{
    return(this->ny);
}

float Vertex::get_nz()
{
    return(this->nz);
}

void Vertex::set_nx(float nx)
{
    this->nx = nx;
}

void Vertex::set_ny(float ny)
{
    this->ny = ny;
}

void Vertex::set_nz(float nz)
{
    this->nz = nz;
}

void Vertex::normal_average()
{
    arma::vec3 nrm = {this->nx, this->ny, this->nz};
    arma::vec3 nnrm = arma::normalise(nrm);
    this->nx = nnrm.at(0);
    this->ny = nnrm.at(1);
    this->nz = nnrm.at(2);
}