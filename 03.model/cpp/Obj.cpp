#include "../include/Obj.h"

Obj::Obj(string file_name):Model(file_name)
{
    this->load();
}

void Obj::load()
{
    this->vertices = {};
    this->faces = {};

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
                string oname;

                // Concatenar los elementos restantes para formar el nombre del objeto
                for (size_t i = 1; i < elements.size(); i++)
                {
                    oname += elements[i];
                }

                // Si se obtuvo un nombre válido, actualizar el nombre del objeto
                if (oname != "")
                {
                    this->name = oname;
                }
            }
            else if(elements[0] == "v")
            {
                float x = stof(elements[1]);
                float y = stof(elements[2]);
                float z = stof(elements[3]);

                Vertex v(x, y, z);
                vertices.push_back(v);
            }
            else if(elements[0] == "f")
            {
                vector<unsigned int> vindex = {};
                for(int i=1; i < elements.size(); i++)
                {
                    unsigned int index = stoi(this->split(elements[i], '/')[0]) - 1;
                    vindex.push_back(index);
                }
                Face f(vindex);
                this->faces.push_back(f);
            }
        }
    }
    OBJ.close();
}