#ifndef FACE_H
#define FACE_H

#pragma once

#include <vector>

using namespace std;

class Face
{
private:
    vector<unsigned int> vindex;
public:
    Face(vector<unsigned int> vindex);
    // reactivo 1
    void printPoly();
};

#endif