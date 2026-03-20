#include "../include/Cannon.h"

Cannon::Cannon(float x, float y, float z)
{
    // x, y, z: posicion inicial del cañon
    this->position.set_x(x);
    this->position.set_y(y);
    this->position.set_z(z);

    this->bullet_pos.set_x(x);
    this->bullet_pos.set_y(y + 0.1);
    this->bullet_pos.set_z(z);

    this->angel = 0.0; 
    this->force = 1.0;

    this->body.load("models/body.obj");
    this->bullet.load("models/bullet.obj");
    this->l_wheel.load("models/l_wheel.ply");
    this->r_wheel.load("models/r_wheel.ply");

    this->b_trayectory = {};
}

void Cannon::shoot()
{
    Animation an;
    Vertex P1 = bullet_pos;
    float rangle = this->angel * M_PI / 180.0; // Convertir a radianes
    Vertex P2( bullet_pos.get_x() + this->force, 
                bullet_pos.get_y() +(1 - cos(rangle)), 
                bullet_pos.get_z());
    Vertex P3( bullet_pos.get_x() + (this->force * 2), 
                P2.get_y(),
                bullet_pos.get_z() );
    Vertex P4( bullet_pos.get_x() + (this->force * 3), 
                0,
                bullet_pos.get_z() );

    this->b_trayectory = an.bezier(P1, P2, P3, P4, 0.1);

    // Ciclo para mover la bala a traves de la trayectoria curva
    for(Vertex bt : this->b_trayectory)
    {
        vector<Vertex> tb_vertices = {};
        arma::Mat<float> T1 = an.T(bt.get_x(), bt.get_y(), bt.get_z());
        // recorrer los vertices de la bala
        for(Vertex v : this->bullet.get_vertices())
        {
            arma::Col<float> vt = T1 * v.h();
            Vertex vtp( vt.at(0,0)/vt.at(3,0), vt.at(1,0)/vt.at(3,0), vt.at(2,0)/vt.at(3,0) );
            tb_vertices.push_back(vtp);
        }
        cout << endl;
        // Dibujar la bala
        // Recorrer cada cara de la bala y dibujarla
    }

}

void Cannon::set_angel(float inc)
{
    this->angel += inc;

    if(this->angel > 85.0)
        this->angel = 85;
     else if(this->angel < 0.0)
        this->angel = 0;
}

void Cannon::set_force(float inc)
{
    this->force += inc;

    if(this->force > 3.0)
        this->force = 3;
     else if(this->force < 0.1)
        this->force = 0.1;
}