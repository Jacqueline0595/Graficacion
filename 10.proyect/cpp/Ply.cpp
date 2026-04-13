#include "../include/Ply.h"

Ply::Ply():Model()
{
    // vacio
}

void Ply::load(string file_name)
{
    this->file_name = file_name;
    this->vertices = {};
    this->faces = {};

    // Obtener nombre sin ruta
    string fname = file_name;

    // Quitar la ruta del archivo
    size_t pos = fname.find_last_of("/\\");
    if (pos != string::npos)
        fname = fname.substr(pos + 1);

    // Quitar la extensión del archivo
    size_t dot = fname.find_last_of('.');
    if (dot != string::npos)
        fname = fname.substr(0, dot);

    // Guardar el nombre final
    this->name = fname;

    ifstream PLY(file_name);
    if (!PLY.is_open())
    {
        cout << "Error al abrir archivo PLY" << endl;
        return;
    }

    string line;
    int vertex_count = 0;
    int face_count = 0;
    bool header = true;

    while (getline(PLY, line))
    {
        vector<string> elements = split(line, ' ');

        if (elements.empty())
            continue;

        if (elements[0] == "element")
        {
            if (elements[1] == "vertex")
                vertex_count = stoi(elements[2]);
            else if (elements[1] == "face")
                face_count = stoi(elements[2]);
        }

        if (elements[0] == "end_header")
        {
            header = false;
            break;
        }
    }

    for (int i = 0; i < vertex_count; i++)
    {
        getline(PLY, line);
        vector<string> elements = split(line, ' ');

        float x = stof(elements[0]);
        float y = stof(elements[1]);
        float z = stof(elements[2]);

        Vertex v(x, y, z);
        vertices.push_back(v);
    }

    for (int i = 0; i < face_count; i++)
    {
        getline(PLY, line);
        vector<string> elements = split(line, ' ');

        int vertices_in_face = stoi(elements[0]);

        vector<unsigned int> vindex;

        for (int j = 1; j <= vertices_in_face; j++)
        {
            unsigned int index = stoi(elements[j]);
            vindex.push_back(index);
        }

        Face f(vindex);
        faces.push_back(f);
    }

    PLY.close();
}