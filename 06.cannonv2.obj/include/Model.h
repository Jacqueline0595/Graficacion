#ifndef MODEL_H
#define MODEL_H

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Vertex.h"
#include "Face.h"
#include "OpenGL.h"

class Model
{
public:
    Model();
    void info();
    virtual void load(string file_name) = 0;
    vector<Vertex> get_vertices() { return faces; }
    vector<Face> get_faces();
    unsigned int get_object();
    void set_object(unsigned int object);
    void set_color(float r, float g, float b);
    vector <GLfloat> get_vertex_buffer_data();
    vector <GLfloat> get_color_buffer_data();
    glm::mat4 get_model_matrix();

protected:
    vector<Vertex> vertices;
    vector<Face> faces;
    string name;
    string file_name;
    unsigned int gl_object;
    float r, g, b;
    glm::mat4 Mmodel;

    vector<string> split(string org_str, char delim);
};

#endif