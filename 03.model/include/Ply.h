#ifndef PLY_H
#define PLY_H

#pragma once


#include "Model.h"
#include <vector>

class Ply: public Model
{
public:
    Ply(string file_name);

private:
    void load();
};

#endif