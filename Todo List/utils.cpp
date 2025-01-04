#include "utils.h"

void input(int &value) {
    fflush(stdin);
    cout << "\n>> ";
    cin >> value;
    cout << "\n";
}

RETURNS validate(int &value, int start, int end) {
    input(value);
    if(value < start || value > end) return ERROR;
    return SUCCESS;
}

void add_task(vector<tarea> &tareas) {
    char title[MAX_LONG_TITLE], description[MAX_LONG_DESCRIPTION];

    cout << "<-- Creando Tarea -->\n";

    cout << "Diga el titulo: ";
    fflush(stdin);
    fgets(title, MAX_LONG_TITLE, stdin);

    cout << "Diga la descripcion: ";
    fflush(stdin);
    fgets(description, MAX_LONG_DESCRIPTION, stdin);

    tareas.push_back({title, description});

    cout << "\n Tarea agregada \n";
}

void delete_task(vector<tarea> &tareas, int &id) {
    do {
        cout << "<-- Escoja una tarea para eliminar --> \n";
        view_all(tareas);
        if(validate(id, 0, (int)tareas.size()) == ERROR) {
            cout << "Valor Invalido" << endl;
            continue;
        }

        tareas.erase(tareas.begin() + id-1);

        cout << "\nTarea: "<<id<<" eliminada... \n";

        break;
    }while (true);
}


void view_all(vector<tarea> &tareas) {
    cout << "\n<-- Todas las Tareas -->\n\n";
    int i = 1;
    for(tarea t : tareas) {
        cout << "<- Tarea #"<<i<<" ->\n";
        cout << "Titulo: "<<t.title;
        cout << "Descripcion: "<<t.description<<"\n";
        i++;
    }
}
