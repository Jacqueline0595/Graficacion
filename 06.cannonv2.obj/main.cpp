#include <iostream>
#include <armadillo>
#include "include/Cannon.h"

int main()
{
    Cannon my_cannon(0, 0, 0);

    my_cannon.main_loop();
    
    /* my_cannon.set_angel(+45.0);
    my_cannon.set_force(0.5);
    my_cannon.shoot(); */

    return 0;
}