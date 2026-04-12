#ifndef ARCHER_H
#define ARCHER_H

#pragma once

#include <iostream>
#include "Obj.h"
#include "Ply.h"
#include "Vertex.h"
#include "Animation.h"
#include "OpenGL.h"

using namespace std;

class Archer
{
public:
    Archer(float x, float y, float z);
    void shootBow();
    void set_angel(float inc);
    void set_force(float inc);
    void main_loop();

private:
    OpenGL gl;
    Vertex position;
    Vertex arrow_pos;
    float angel;
    float force; 
    Obj upperBody;
    Obj lowerBody;
    Obj target;
    Ply bow;
    Ply arrow;
    vector<Vertex> arrow_trayectory;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif