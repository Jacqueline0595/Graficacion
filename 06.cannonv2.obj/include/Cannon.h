#ifndef CANNON_H
#define CANNON_H

#pragma once

#include <iostream>
#include "Obj.h"
#include "Ply.h"
#include "Vertex.h"
#include "Animation.h"
#include "OpenGL.h"

using namespace std;

class Cannon
{
public:
    Cannon(float x, float y, float z, GLFWkeyfun callback);
    void shoot();
    void set_angle(float inc);
    void set_force(float inc);
    void main_loop();
    void set_view(glm::mat4 view);

private:
    OpenGL gl;
    
    Vertex position;
    Vertex bullet_pos;

    float angle;
    float force; 

    Obj body;
    Obj bullet;

    Ply l_wheel;
    Ply r_wheel;

    vector<Vertex> b_trayectory;

    unsigned int b_index;

    glm::mat4 View;
    glm::mat4 Projection;

    bool shooted;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif