#ifndef OPENGL_H
#define OPENGL_H

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

using namespace std;

class OpenGL
{
public:
    OpenGL();
    void createWindow(long width, long height, std::string title);
    void setKeyCallBack(GLFWkeyfun callback);
    GLuint loadShaders(const char * vertex_file_path,const char * fragment_file_path);
    unsigned int create_object(vector <GLfloat> vertex_buffer_data, vector <GLfloat> color_buffer_data);
    void draw_object(unsigned int object_id);
    bool should_close();

private:
    GLFWwindow* window;
    GLuint programID;
    vector <GLuint> vertexbuffer;
	vector <GLuint> colorbuffer;
    vector <GLuint> datasize;
};

#endif