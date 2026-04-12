#include "../include/Archer.h"

Archer::Archer(float x, float y, float z)
{
    this->position.set_x(x);
    this->position.set_y(y);
    this->position.set_z(z);

    this->arrow_pos.set_x(x);
    this->arrow_pos.set_y(y + 0.1);
    this->arrow_pos.set_z(z);

    this->angel = 0.0; 
    this->force = 1.0;

    this->upperBody.load("models/upperBody.obj"); 
    this->lowerBody.load("models/lowerBody.obj"); 
    this->target.load("models/target.obj");
    this->bow.load("models/bow.ply");
    this->arrow.load("models/arrow.ply");

    // Asignarles colores
    this->upperBody.set_color(1.0f, 0.0f, 0.0f);
    this->lowerBody.set_color(1.0f, 0.0f, 0.0f);
    this->target.set_color(0.0f, 1.0f, 0.0f);
    this->bow.set_color(1.0f, 1.0f, 0.0f);
    this->arrow.set_color(1.0f, 0.0f, 1.0f);

    this->arrow_trayectory = {};

    // crear la ventana
    this->gl.createWindow( 800, 600, "Archer simulation" );
    this->gl.setKeyCallBack(this->key_callback);

    // color del fondo
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    unsigned int object_uppB = this->gl.create_object(this->upperBody.get_vertex_buffer_data(),
                this->upperBody.get_color_buffer_data());

    unsigned int object_lowB = this->gl.create_object(this->lowerBody.get_vertex_buffer_data(),
                this->lowerBody.get_color_buffer_data());

    unsigned int object_t = this->gl.create_object(this->target.get_vertex_buffer_data(),
                this->target.get_color_buffer_data());

    unsigned int object_a = this->gl.create_object(this->arrow.get_vertex_buffer_data(),
                this->arrow.get_color_buffer_data());

    unsigned int object_b = this->gl.create_object(this->bow.get_vertex_buffer_data(),
                this->bow.get_color_buffer_data());


    this->upperBody.set_object(object_uppB); 
    this->lowerBody.set_object(object_lowB);  
    this->target.set_object(object_t);
    this->arrow.set_object(object_a);         
    this->bow.set_object(object_b);
}

void Archer::main_loop()
{
    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        this->gl.draw_object( this->upperBody.get_object() );
        this->gl.draw_object( this->lowerBody.get_object() );
        this->gl.draw_object( this->target.get_object() );
        this->gl.draw_object( this->arrow.get_object() );
        this->gl.draw_object( this->bow.get_object() );

    } while ( !this->gl.should_close() );
}

void Archer::shootBow()
{
    // Disparar la flecha a traves de una trayectoria curva (bezier)
}

void Archer::set_angel(float inc)
{
    // Aumentar o disminuir el ángulo de disparo
}

void Archer::set_force(float inc)
{
    // Aumentar o disminuir la fuerza de disparo
}

void Archer::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        cout << "Disparar el arco" << endl;
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        cout << "Aumentar el ángulo" << endl;
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
        cout << "Disminuir el ángulo" << endl;
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        cout << "Disminuir la fuerza" << endl;
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        cout << "Aumentar la fuerza" << endl;
}