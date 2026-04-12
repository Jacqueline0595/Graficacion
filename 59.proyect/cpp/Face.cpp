#include "../include/Face.h"
#include <iostream>

using namespace std;

Face::Face(vector <unsigned int> vindex)
{
    this->vindex = vindex;
}

vector<unsigned int> Face::get_indices()
{
    return(this->vindex);
}
