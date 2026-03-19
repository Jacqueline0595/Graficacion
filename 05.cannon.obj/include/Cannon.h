#ifndef CANNON_H
#define CANNON_H

#pragma once

#include <iostream>
#include "Obj.h"
#include "Ply.h"
#include "Vertex.h"
#include "Animation.h"

using namespace std;

class Cannon
{
public:
    Cannon(float x, float y, float z);
    void shoot();
    void set_angel(float inc);
    void set_force(float inc);

private:
    Vertex position;
    Vertex bullet_pos;
    float angel;
    float force; 
    Obj body;
    Obj bullet;
    Ply l_wheel;
    Ply r_wheel;
    vector<Vertex> b_trayectory;
};

#endif