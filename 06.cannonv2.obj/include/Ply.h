#ifndef PLY_H
#define PLY_H

#pragma once

#include "Model.h"
#include <vector>

using namespace std;

class Ply: public Model
{
public:
    Ply();
    void load(string file_name);

private:
    // 
};

#endif