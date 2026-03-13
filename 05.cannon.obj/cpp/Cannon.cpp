#include "../include/Cannon.h"

Cannon::Cannon(float x, float y, float z)
{
    // x, y, z: posicion inicial del cañon
    this->position.set_x(x);
    this->position.set_y(y);
    this->position.set_z(z);
}

void Cannon::shoot()
{
    cout << "Disparando" << endl;
}