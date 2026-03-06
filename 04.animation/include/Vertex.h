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
    // reactivo 1
    void printOctant();
    arma::Col<float> h();
};

#endif