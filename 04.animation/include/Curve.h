#ifndef CURVE_H
#define CURVE_H

#pragma once

#include "Vertex.h"
#include <armadillo>

using namespace std;
using namespace arma;

class Curve
{
public:
    Curve(Vertex p0, Vertex p1, Vertex p2, Vertex p3);
    void printPoint(float t);
    float approximateLength(float dt);

private:
    Vertex P0, P1, P2, P3;
};

#endif