#include "Logica.h"

// Funcion para validar operacion de seleccion
bool ValidarOperacion(char palabra[], int min, int max){
    bool result = false;

    if(!(ValidarNumero(palabra))){
        if((atoi(palabra) >= min) && (atoi(palabra) <= max)){
            result = true;
        }
    }

    return result;
}

// Funcion para validar palabra introducida
bool ValidarPalabra(char palabra[]){
    int cant = strlen(palabra), j;
    bool inter = false;

    for(j = 0; j < cant; j++){
        if(isdigit(palabra[j])){
            inter = true;
        }
    }

    return inter;
}

// Funcion para validar Numeros
bool ValidarNumero(char palabra[]){
    int cant = strlen(palabra), j;
    bool inter = false;

    for(j = 0; j < cant; j++){
        if(isalpha(palabra[j])){
            inter = true;
        }
    }

    return inter;
}

// Función para inicializar un departamento
void InitDepartamento(Departamento *depto, int id, const char *jefe, int cantTrabajadores){
    depto->id = id;
    strcpy(depto->jefe, jefe);
    depto->cantTrabajadores = cantTrabajadores;
    depto->cantMediosBasicos = 0;
}

// Función para agregar Medios Básicos a un determinado departamento
void AgregarMedioBasico(Departamento *depto,char tipo[],int estado ,int mes){
    depto->mediosBasicos[depto->cantMediosBasicos].id = (depto->cantMediosBasicos + 1);
    strcpy(depto->mediosBasicos[depto->cantMediosBasicos].tipo, tipo);
    depto->mediosBasicos[depto->cantMediosBasicos].estado = estado;
    depto->mediosBasicos[depto->cantMediosBasicos].mesAsignado = mes;
    depto->cantMediosBasicos++;
}

// Función para mostrar los medios básicos de un departamento por estado
void mostrarMediosPorEstado(Departamento *depto) {
    int optimos = 0, deteriorados = 0, rotos = 0, i = 0;

    for(i = 0; i < depto->cantMediosBasicos; i++){
        switch (depto->mediosBasicos[i].estado){
            case OPTIMO:
                optimos++;
                break;
            case DETERIORADO:
                deteriorados++;
                break;
            case ROTO:
                rotos++;
                break;
        }
    }
    printf("Optimos: %d\nDeteriorados: %d\nRotos: %d\n",optimos,deteriorados,rotos);
}

// Función para encontrar el departamento con más medios básicos rotos
Departamento* deptoConMasRotos(Departamento deptos[], int cantDeptos) {
    int maxRotos = 0, i = 0, j = 0;
    Departamento *deptoMaxRotos = NULL;

    for (i = 0; i < cantDeptos; i++) {
        int rotos = 0;
        for (j = 0; j < deptos[i].cantMediosBasicos; j++) {
            if(deptos[i].mediosBasicos[j].estado == ROTO){
                rotos++;
            }
        }

        if (rotos >= maxRotos) {
            maxRotos = rotos;
            deptoMaxRotos = &deptos[i];
        }
    }

    return deptoMaxRotos;
}

// Función para mostrar un reporte con los datos de todos los departamentos
void mostrarReporteDepartamentos(Departamento *depto) {
    printf("\nDepartamento ID: %d\nJefe: %s\nCantidad de Trabajadores: %d\nCantidad de Medios: %d\n",
            depto->id, depto->jefe, depto->cantTrabajadores, depto->cantMediosBasicos);
    mostrarMediosPorEstado(depto);
    printf("\n\n");
}

// Función para determinar el departamento al que pertenece un MedioBasico específico
Departamento* encontrarDepartamentoPorMedio(Departamento deptos[], int cantDeptos, int idMedio) {
     int i, j;
     for (i= 0; i < cantDeptos; i++) {
         for (j = 0; j < deptos[i].cantMediosBasicos; j++) {
             if (deptos[i].mediosBasicos[j].id == idMedio) {
                 return &deptos[i];
             }
         }
     }
     return NULL;
 }

// Función para determinar si se ha efectuado alguna asignación de algún medio básico a un departamento en un mes específico
int asignacionEnMes(Departamento depto[], int TLDepartamentos, int mes) {
     int i, j, cantidad;

     for(i = 0; i < TLDepartamentos; i++){
         for(j = 0; j < depto[i].cantMediosBasicos; j++){
             if(depto[i].mediosBasicos[j].mesAsignado == (mes-1)){
                cantidad++;
             }
         }
     }

     return cantidad;
 }
