#ifndef MAIN_H
#define MAIN_H

#include <iostream>
using namespace std;

enum SECCION {NONE = -1, SMOKING = 0, NONSMOKING = 1};
enum RETURNS {ERROR = -1, SUCCESS = 1};

void ImprimirPase(int asiento, SECCION seccion);
int AsignarAsiento(int asientos[], SECCION seccion, int &asiento);
void MostrarAsientosOcupados(int asientos[]);
bool AsientosLlenos(const int asientos[]);

#endif //MAIN_H
