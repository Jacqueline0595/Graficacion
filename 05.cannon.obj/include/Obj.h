#ifndef OBJ_H
#define OBJ_H

#pragma once


#include "Model.h"
#include <vector>

using namespace std;

class Obj: public Model
{
public:
    Obj();
    void load(string file_name);
    
private:  
    // 
};

#endif