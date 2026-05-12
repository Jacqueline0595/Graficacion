#include "../include/Edge.h"

Edge::Edge(Vertex vi, Vertex ve)
{
    this->vi = vi;
    this->ve = ve;
}

void Edge::print()
{
    vi.print();
    cout << " -> ";
    ve.print();
}