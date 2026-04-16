#include "../include/Model.h"
    
Model::Model()
{
    this->file_name = "";
    this->r = 1.0f;
    this->g = 1.0f;
    this->b = 1.0f;
}

vector<string> Model::split(string org_str, char delim)
{
    vector<string> str_array = {};
    string str = org_str;
    // Create a stringstream object to str
    stringstream ss(str);
  	// Temporary object to store the splitted
  	// string
    string t;
  	// Delimiter
    char del = delim;
 
   	// Splitting the str string by delimiter
    while (getline(ss, t, del))
    {
        if (t != "" && t != "\r")
            str_array.push_back(t);
    }
 
    return str_array;
}

void Model::info()
{
    cout << "Nombre del modelo: " << this->name << endl;
    cout << "Numero de vertices: " << this->vertices.size() << endl;
    cout << "Numero de caras: " << this->faces.size() << endl;
}

vector<Vertex> Model::get_vertices()
{
    return(this->vertices);
}

unsigned int Model::get_object()
{
    return(this->gl_object);
}

void Model::set_object(unsigned int object)
{
    this->gl_object = object;
}

void Model::set_color(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}