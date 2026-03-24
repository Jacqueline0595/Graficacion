#include "../include/Ejemplo.h"
Ejemplo::Ejemplo()
{
    this->gl.createWindow( 800, 600, "Graficación" );
    this->gl.setKeyCallBack(this->key_callback);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    this->object_1 = this->gl.create_object({-1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, -0.5f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.5f, 0.0f, 0.0f},
                 {0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f});
}

void Ejemplo::main_loop()
{
    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        this->gl.draw_object( this->object_1 );

    } while ( !this->gl.should_close() );
}

void Ejemplo::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        cout << "Barra espaciadora" << endl;
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        cout << "Tecla arriba" << endl;
}