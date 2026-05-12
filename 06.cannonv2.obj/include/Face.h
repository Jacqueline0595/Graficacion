#ifndef FACE_H
#define FACE_H
#include <vector>

#pragma once

using namespace std;

class Face
{
public:
    Face(vector<unsigned int> vindex);
    vector<unsigned int> get_indices();
private:
    vector<unsigned int> vindex;
};

#endif