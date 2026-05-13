#ifndef EDGE_H
#define EDGE_H

#pragma once

#include <iostream>
#include "Vertex.h"

using namespace std;

class Edge
{
public:
    Vertex vi, ve;
    Edge(Vertex vi, Vertex ve);
    void print();

private:
    
};

#endif