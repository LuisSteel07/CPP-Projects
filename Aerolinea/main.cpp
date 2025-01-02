#include "utilidades.h"

int main() {

    int asientos[10] = {0};

    while(!AsientosLlenos(asientos)){
        int option = 0;
        int asiento = 0;
        SECCION seccion = NONE;
        cout << "Diga 1 para 'smoking' o 2 para 'nonsmoking' \n";
        cin >> option;

        if(option < 0 || option > 2) {
            cout << "Error, ingrese un valor valido... \n";
            continue;
        }
        else {
            if(option == 1) seccion = SMOKING;
            if(option == 2) seccion = NONSMOKING;
        }

        if(AsignarAsiento(asientos, seccion, asiento) == ERROR) {
            cout << "No se encontraron asientos para su seccion, seleccion otra seccion si lo desea ... \n";
            system("pause");
            continue;
        } else {
            ImprimirPase(asiento, seccion);
        }

        cout << endl;
        MostrarAsientosOcupados(asientos);
        cout << endl;
        cout << endl;
    };

    cout << "El avion esta completamente lleno de pasajeros \n";

    return 0;
}
