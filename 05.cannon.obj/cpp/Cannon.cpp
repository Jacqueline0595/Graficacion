#include "../include/Cannon.h"

Cannon::Cannon(float x, float y, float z)
{
    // x, y, z: posicion inicial del cañon
    this->position.set_x(x);
    this->position.set_y(y);
    this->position.set_z(z);

    this->angel = 0.0; 
    this->force = 1.0;

    this->body.load("models/body.obj");
    this->bullet.load("models/bullet.obj");
    this->l_wheel.load("models/l_wheel.ply");
    this->r_wheel.load("models/r_wheel.ply");
}

void Cannon::shoot()
{
    cout << "Disparando" << endl;
}

void Cannon::set_angel(float inc)
{
    this->angel += inc;

    if(this->angel > 85.0)
    {
        this->angel = 85;
    }
     else if(this->angel < 0.0)
    {
        this->angel = 0;
    }
}

void Cannon::set_force(float inc)
{
    this->force += inc;

    if(this->force > 3.0)
    {
        this->force = 3;
    }
     else if(this->force < 0.1)
    {
        this->force = 0.1;
    }
}