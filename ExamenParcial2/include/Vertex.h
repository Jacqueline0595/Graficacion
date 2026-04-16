#ifndef VERTEX_H
#define VERTEX_H

#pragma once
#include <armadillo>

class Vertex
{
private:
    float x, y, z;
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

    arma::Col<float> h();
    // Tiene mas sentido hacerlo desde aqui para mi 
    arma::Col<float> EspToHomogenous(float w);
    Vertex homoToEsp(arma::Col<float> P, float w);
};

#endif