#include "utils.cpp"
using namespace std;

int main() {
    vector<tarea> list_tareas = vector<tarea>();

    do {
        int op = 0;

        cout << "\n<-- Administrador de Tareas --> \n";
        cout << "-1- Crear Tarea \t-2- Eliminar Tarea \n";
        cout << "-3- Listar Tareas \t-4- Salir \n";

        if(validate(op, 1, 4) == ERROR) {
            cout << "Valor Invalido \n" << endl;
            continue;
        }

        if(op == 1) add_task(list_tareas);
        if(op == 2) delete_task(list_tareas, op);
        if(op == 3) view_all(list_tareas);
        else if(op == 4) break;

    }while(true);

    return 0;
}