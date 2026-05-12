#include "../include/Obj.h"

Obj::Obj():Model()
{
    // vacio (?)
}

void Obj::load(string file_name)
{
    this->file_name = file_name;
    this->vertices = {};
    this->faces = {};
    vector<Vertex> normals = {};

    // Obtener el nombre del archivo sin la ruta
    string fname = file_name;

    // Quitar la ruta del archivo
    size_t pos = fname.find_last_of("/\\");
    if (pos != string::npos) {
        fname = fname.substr(pos + 1);
    }

    // Quitar la extensión del archivo
    size_t dot = fname.find_last_of('.');
    if (dot != string::npos) {
        fname = fname.substr(0, dot);
    }

    // Guardar el nombre final
    this->name = fname;


    string line;

    ifstream OBJ(file_name);
    while ( getline(OBJ, line) )
    {
        vector<string> elements = this->split(line, ' ');

        if(!elements.empty())
        {
            if (elements[0] == "o")
            {
                float x = stof(elements[1]);
                float y = stof(elements[2]);
                float z = stof(elements[3]);

                Vertex v(x, y, z);
                this->vertices.push_back(v);
            }
            else if(elements[0] == "v")
            {
                float x = stof(elements[1]);
                float y = stof(elements[2]);
                float z = stof(elements[3]);

                Vertex v(x, y, z);
                vertices.push_back(v);
            }
            else if(elements[0] == "vn")
            {
                float nx = stof(elements[1]);
                float ny = stof(elements[2]);
                float nz = stof(elements[3]);

                Vertex n(nx, ny, nz);
                vertices.push_back(n);
            }
            else if(elements[0] == "f")
            {
                vector<unsigned int> vindex = {};
                for(int i=1; i < elements.size(); i++)
                {
                    unsigned int index = stoi(this->split(elements[i], '/')[0]) - 1;
                    unsigned int nindex = stoi(this->split(elements[i], '/')[1]) - 1;
                    this->vertices[index].set_nx( normals[nindex].get_x() );
                    this->vertices[index].set_ny( normals[nindex].get_y() );
                    this->vertices[index].set_nz( normals[nindex].get_z() );
                    vindex.push_back(index);
                }
                Face f(vindex);
                this->faces.push_back(f);
            }
        }
    }
    OBJ.close();

    for (Vertex v: this->vertices)
    {
        v.normal_average();
    }
}