#ifndef VERTEX_H
#define VERTEX_H

#pragma once
#include <armadillo>

class Vertex
{
private:
    float x, y, z, w;
    float nx, ny, nz;
public:
    Vertex() {};
    Vertex(float x, float y, float z); 
    void print();
    Vertex operator+(Vertex op2);
    Vertex operator-(Vertex op2);
    Vertex operator*(float op2);
    float get_x();
    float get_y();
    float get_z();

    void set_x(float x);
    void set_y(float y);
    void set_z(float z);

    float get_nx();
    float get_ny();
    float get_nz();

    void set_nx(float x);
    void set_ny(float y);
    void set_nz(float z);

    void normal_average();

    arma::Col<float> h();
};

#endif