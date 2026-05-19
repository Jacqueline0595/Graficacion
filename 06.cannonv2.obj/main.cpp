#include <iostream>
#include <glm/glm.hpp>
#include "include/Cannon.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

Cannon my_cannon(-0.9, 0.1, 0, key_callback);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        my_cannon.shoot();
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        my_cannon.set_angle(+5.0);
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
        my_cannon.set_angle(-5.0);
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        cout << "Disminuir la fuerza" << endl;
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        cout << "Aumentar la fuerza" << endl;

    if (key == GLFW_KEY_1 && action == GLFW_PRESS)
    {
        glm::mat4 view = glm::lookAt(
            glm::vec3(0, 0, 5), // Camera is at (0,0,5), in World Space
            glm::vec3(0, 0, 0), // and looks at the origin
            glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
        );
        my_cannon.set_view(view);
    }

    if (key == GLFW_KEY_2 && action == GLFW_PRESS)
    {
        glm::mat4 view = glm::lookAt(
            glm::vec3(5, 0, 0), // Camera is at (0,0,5), in World Space
            glm::vec3(0, 0, 0), // and looks at the origin
            glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
        );
        my_cannon.set_view(view);
    }

    if (key == GLFW_KEY_3 && action == GLFW_PRESS)
    {
        glm::mat4 view = glm::lookAt(
            glm::vec3(0, 5, 0), // Camera is at (0,0,5), in World Space
            glm::vec3(0, 0, 0), // and looks at the origin
            glm::vec3(1, 0, 0)  // Head is up (set to 0,-1,0 to look upside-down)
        );
        my_cannon.set_view(view);
    }
}

int main()
{
    my_cannon.set_angle(0.0);
    my_cannon.set_force(0.5);
    
    my_cannon.main_loop();
    
    // my_cannon.shoot(); 

    return 0;
}