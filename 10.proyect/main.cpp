#include <iostream>
#include <armadillo>
#include "include/Archer.h"

int main()
{
    Archer my_archer(0, 0, 0);

    my_archer.main_loop();
    
    return 0;
}