#ifndef LOGICA_H
#define LOGICA_H

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Definición de la estructura Estado
typedef enum {
    OPTIMO,
    DETERIORADO,
    ROTO
} Estado;

// Definicion de la estructura de meses del año
typedef enum {
    ENERO,
    FEBRERO,
    MARZO,
    ABRIL,
    MAYO,
    JUNIO,
    JULIO,
    AGOSTO,
    SEPTIEMPRE,
    OCTUBRE,
    NOVIEMBRE,
    DICIEMBRE
} Mes;

// Definición de la estructura MedioBasico
typedef struct{
    int id;
    char tipo[50];
    Estado estado;
    Mes mesAsignado;
} MedioBasico;

// Definición de la estructura Departamento
typedef struct {
    int id;
    char jefe[50];
    int cantTrabajadores;
    int cantMediosBasicos;
    MedioBasico mediosBasicos[40];
} Departamento;

void InitDepartamento(Departamento *depto, int id, const char *jefe, int cantTrabajadores);

void AgregarMedioBasico(Departamento *depto,char tipo[] ,int estado ,int mes);

void mostrarMediosPorEstado(Departamento *depto);

Departamento* deptoConMasRotos(Departamento deptos[], int cantDeptos);

void mostrarReporteDepartamentos(Departamento *depto);

bool ValidarOperacion(char input[], int min, int max);

bool ValidarPalabra(char palabra[]);

bool ValidarNumero(char palabra[]);

int asignacionEnMes(Departamento depto[], int TLDepartamentos, int mes);

Departamento* encontrarDepartamentoPorMedio(Departamento deptos[], int cantDeptos, int idMedio);

#endif // LOGICA_H
