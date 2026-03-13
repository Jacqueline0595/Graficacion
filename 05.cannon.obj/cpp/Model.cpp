#include "../include/Model.h"
    
Model::Model(string file_name)
{
    this->file_name = file_name;
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