#ifndef EJEMPLO_H
#define EJEMPLO_H

#pragma once

#include "OpenGL.h"


class Ejemplo
{
public:
    Ejemplo();
    void main_loop();
    
private:
    OpenGL gl;
    unsigned int object_1;
    unsigned int object_2;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif