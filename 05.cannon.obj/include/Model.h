#ifndef MODEL_H
#define MODEL_H

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Vertex.h"
#include "Face.h"
#include <vector>

class Model
{
public:
    // Model() = {};
    Model();
    void info();
    // pasar un parametro
    virtual void load(string file_name) = 0;
    vector<Vertex> get_vertices();

protected:
    vector<Vertex> vertices;
    vector<Face> faces;
    string name;
    string file_name;
    
    vector<string> split(string org_str, char delim);
};

#endif