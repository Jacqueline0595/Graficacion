#ifndef CANNON_H
#define CANNON_H

#pragma once

#include <iostream>
#include "Vertex.h"

using namespace std;

class Cannon
{
public:
    Cannon(float x, float y, float z);
    void shoot();

private:
    Vertex position;
};

#endif