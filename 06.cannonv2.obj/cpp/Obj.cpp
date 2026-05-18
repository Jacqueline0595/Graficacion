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
    if(!OBJ.is_open())
    {
        cout << "Error opening OBJ file: " << file_name << endl;
        return;
    }
    while ( getline(OBJ, line) )
    {
        vector<string> elements = this->split(line, ' ');

        if(!elements.empty())
        {
            if(elements[0] == "v")
            {
                if(elements.size() >= 4)
                {
                    float x = stof(elements[1]);
                    float y = stof(elements[2]);
                    float z = stof(elements[3]);

                    Vertex v(x, y, z);
                    this->vertices.push_back(v);
                }
            }
            else if(elements[0] == "vn")
            {
                if(elements.size() >= 4)
                {
                    float nx = stof(elements[1]);
                    float ny = stof(elements[2]);
                    float nz = stof(elements[3]);

                    Vertex n(nx, ny, nz);
                    normals.push_back(n);
                }
            }
            else if(elements[0] == "f")
            {
                vector<unsigned int> vindex = {};
                for(size_t i=1; i < elements.size(); i++)
                {
                    vector<string> parts = this->split(elements[i], '/');

                    if(parts.empty())
                        continue;

                    if(parts[0] == "")
                        continue;

                    unsigned int index = stoi(parts[0]) - 1;

                    if(index >= this->vertices.size())
                        continue;

                    if(parts.size() >= 3 && parts[2] != "")
                    {
                        unsigned int nindex = stoi(parts[2]) - 1;

                        if(nindex < normals.size())
                        {
                            this->vertices[index].set_nx(normals[nindex].get_x());
                            this->vertices[index].set_ny(normals[nindex].get_y());
                            this->vertices[index].set_nz(normals[nindex].get_z());
                        }
                    }

                    vindex.push_back(index);
                }
                if(vindex.size() >= 3)
                {
                    Face f(vindex);
                    this->faces.push_back(f);
                }
            }
        }
    }
    OBJ.close();

    for (Vertex& v: this->vertices)
    {
        v.normal_average();
    }
}