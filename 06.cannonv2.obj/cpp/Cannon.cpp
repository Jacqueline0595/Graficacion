#include "../include/Cannon.h"

Cannon::Cannon(float x, float y, float z, GLFWkeyfun callback)
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
    this->shooted = false;

    this->body.load("models/body.obj");
    this->body.set_color(1.0f, 0.0f, 0.0f);
    this->bullet.load("models/bullet.obj");
    this->bullet.set_color(0.0f, 0.0f, 1.0f);
    this->l_wheel.load("models/l_wheel.ply");
    this->l_wheel.set_color(0.0f, 1.0f, 0.0f);
    this->r_wheel.load("models/r_wheel.ply");
    this->r_wheel.set_color(1.0f, 1.0f, 0.0f);
    
    this->b_trayectory = {};
    this->b_index = 0;

    // crear la ventana
    this->gl.createWindow( 800, 600, "Cannon" );
    this->gl.setKeyCallBack(callback);

    // color del fondo
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    unsigned int object_b = this->gl.create_object(this->body.get_vertex_buffer_data(),
                this->body.get_color_buffer_data(),
                this->body.get_normal_buffer_data() );

    this->body.set_object(object_b);

    unsigned int object_bl = this->gl.create_object(this->bullet.get_vertex_buffer_data(),
                this->bullet.get_color_buffer_data(),
                this->bullet.get_normal_buffer_data() );

    this->bullet.set_object(object_bl);

    unsigned int object_l_wheel = this->gl.create_object(this->l_wheel.get_vertex_buffer_data(),
                this->l_wheel.get_color_buffer_data(),
                this->l_wheel.get_normal_buffer_data() );

    this->l_wheel.set_object(object_l_wheel);

    unsigned int object_r_wheel = this->gl.create_object(this->r_wheel.get_vertex_buffer_data(),
                this->r_wheel.get_color_buffer_data(),
                this->r_wheel.get_normal_buffer_data() );

    this->r_wheel.set_object(object_r_wheel);

    this->View = glm::lookAt(
        glm::vec3(0, 0, 5), // Camera is at (0,0,5), in World Space
        glm::vec3(0, 0, 0), // and looks at the origin
        glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    //this->Projection = glm::perspective(glm::radians(45.0f), 1024.0f/768.0f, 0.1f, 100.0f);
    this->Projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f , 0.1f, 100.0f);
}

void Cannon::main_loop()
{
    Animation an;

    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        if(this->shooted)
        {
            // Ciclo para mover la bala a traves de la trayectoria curva
            Vertex bt = this->b_trayectory[this->b_index];
            if (this->b_index < this->b_trayectory.size())
                this->b_index++;
            else
                this->shooted = false; // Detener el movimiento de la bala cuando alcance el final de la trayectoria

            this->b_index++;

            arma::Mat<float> T1 = an.T(bt.get_x(), bt.get_y(), bt.get_z());
            this->bullet.set_mmodel(T1);
        }

        this->gl.draw_object( this->body.get_object(), this->Projection * this->View * this->body.get_mmodel_matrix() );
        this->gl.draw_object( this->bullet.get_object(), this->Projection * this->View * this->bullet.get_mmodel_matrix() );
        this->gl.draw_object( this->l_wheel.get_object(), this->Projection * this->View * this->l_wheel.get_mmodel_matrix() );
        this->gl.draw_object( this->r_wheel.get_object(), this->Projection * this->View * this->r_wheel.get_mmodel_matrix() );

    } while ( !this->gl.should_close() );
}

void Cannon::shoot()
{
    Animation an;

    Vertex P1 = bullet_pos;
    float rangle = this->angel + M_PI / 180.0; // Convertir a radianes
    Vertex P2( bullet_pos.get_x() + this->force, 
                bullet_pos.get_y() +(1 - cos(rangle)), 
                bullet_pos.get_z() );
    Vertex P3( bullet_pos.get_x() + (this->force * 2), 
                P2.get_y(),
                bullet_pos.get_z() );
    Vertex P4( bullet_pos.get_x() + (this->force * 3), 
                0,
                bullet_pos.get_z() );

    this->b_trayectory = an.bezier(P1, P2, P3, P4, 0.1);
    this->shooted = true;
    this->b_index = 0;
}

void Cannon::set_angel(float inc)
{
    Animation an;
    
    this->angel += inc;

    if(this->angel > 85.0)
        this->angel = 85;
     else if(this->angel < 0.0)
        this->angel = 0;

    Vertex P1(this->bullet_pos.get_x(), this->bullet_pos.get_y(), this->bullet_pos.get_z() + 0.2);
    Vertex P2(this->bullet_pos.get_x(), this->bullet_pos.get_y(), this->bullet_pos.get_z() - 0.2);
    this->body.set_mmodel(an.Rp1p2(P1, P2, this->angel));
}

void Cannon::set_force(float inc)
{
    this->force += inc;

    if(this->force > 3.0)
        this->force = 3;
     else if(this->force < 0.1)
        this->force = 0.1;
}

void Cannon::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        cout << "Disparar el cañon" << endl;
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        cout << "Aumentar el ángulo" << endl;
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
        cout << "Disminuir el ángulo" << endl;
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        cout << "Disminuir la fuerza" << endl;
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        cout << "Aumentar la fuerza" << endl;
}

void Cannon::set_view(glm::mat4 view)
{
    this->View = view;
}