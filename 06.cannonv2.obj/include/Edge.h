#ifndef EDGE_H
#define EDGE_H

#pragma once

#include <iostream>
#include "Vertex.h"

class Edge
{
public:
    Vertex vi, ve;

private:
    Edge(Vertex vi, Vertex ve);
    void print();

};

#endif