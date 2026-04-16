#ifndef ANIMATION_H
#define ANIMATION_H

#pragma once

#include "Vertex.h"
#include <iostream>
#include <armadillo>
#include <cmath>
#include <numbers>
#include <vector>

using namespace std;

class Animation
{
public:
    Animation();
    vector<Vertex> line(Vertex v1, Vertex v2, float dt);
    vector<Vertex> bezier(Vertex P1, Vertex P2, Vertex P3, Vertex P4, float dt);
    arma::Mat<float> T(float dx, float dy, float dz);
    arma::Mat<float> S(float sx, float sy, float sz);
    arma::Mat<float> Rx(float theta);
    arma::Mat<float> Ry(float theta);
    arma::Mat<float> Rz(float theta);
    arma::Mat<float> Rp1p2(Vertex P1, Vertex P2, float theta);
    vector<Vertex> homoToEsp(Vertex homo, float w);
    vector<Vertex> EspToHomo(Vertex espacial, float w);
private:

};

#endif