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
    Archer(float x, float y, float z, GLFWkeyfun callback);
    void shootBow();
    void set_angel(float inc);
    void set_force(float inc);
    void main_loop();
    void set_view(glm::mat4 view);

private:
    OpenGL gl;

    Vertex position;
    Vertex arrow_pos;

    float angel;
    float force; 

    // Modelos Obj
    Obj upperBody;
    Obj lowerBody;
    Obj target;

    // Modelos Ply
    Ply bow;
    Ply arrow;

    vector<Vertex> arrow_trayectory;

    unsigned int arrow_index;

    glm::mat4 View;
    glm::mat4 Projection;

    bool shooted;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif