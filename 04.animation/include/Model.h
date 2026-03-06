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
    Model(string file_name);
    void info();
    
    // reactivo 1
    void printPolygons();
protected:
    vector<Vertex> vertices;
    vector<Face> faces;
    string name;
    string file_name;
    
    virtual void load() = 0;
    vector<string> split(string org_str, char delim);
};

#endif