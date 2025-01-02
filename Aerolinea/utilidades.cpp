#include "utilidades.h"

void ImprimirPase(const int asiento,const SECCION seccion) {
    cout << "Su asiento es el num. " << asiento << "\n";
    switch (seccion) {
        case SMOKING:
            cout << "En la seccion para fumadores \n";
            break;
        case NONSMOKING:
            cout << "En la seccion para no fumadores \n";
            break;
        default:
            cout << "INTERNAL ERROR \n";
    }
}

int AsignarAsiento(int asientos[], const SECCION seccion, int &asiento) {
    int init = 0, limit = 0;

    if(seccion == SMOKING) {
        limit = 4;
    } else {
        init = 5;
        limit = 9;
    }

    while(init <= limit) {
        if(asientos[init] == 0) {
            asientos[init] = 1;
            asiento = init;
            return SUCCESS;
        }
        init++;
    }
    return ERROR;
}

void MostrarAsientosOcupados(int asientos[]) {
    int col = 0;
    for(int i = 0; i <= 9; i++) {
        if(col == 5) {
            col = 0;
            cout << "\n";
        }
        cout << asientos[i] << " ";
        col++;
    }
}

bool AsientosLlenos(const int asientos[]) {
    for (int i = 0; i <= 9; i++) {
        if(asientos[i] == 0) return false;
    }
    return true;
}