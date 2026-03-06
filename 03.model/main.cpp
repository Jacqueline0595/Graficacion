#include "include/Obj.h"
#include "include/Ply.h"

using namespace std;

int main()
{
    cout << "Cargando..." << endl;
    
    Obj cubeO("models/cube.obj");
    cubeO.info();

    Ply cube("models/cube.ply");
    cube.info();

    cout << "Modelos cargados en memoria" << endl;
    return 0;
}