#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Logica.h"

void StartMenu(Departamento AllDepartementos[], int TLDepartamentos);

Departamento* SelectDepartamento(Departamento dp[], int cantidad);

void InicializarMedios(Departamento dp[],int cantidad);

void InicializarDepartamentos(Departamento dp[], int cantidad);

void AutomaticInitDepartamentos(Departamento dp[]);

void ManualInitDepartamentos(Departamento dp[], int cantidad);

void AutomaticInitMedios(Departamento dp[]);

void ManualInitMedios(Departamento dp[], int cantidad);

void AsignarMedio(Departamento *dp[], int cantidad);

void BuscarDepartamentoConID(Departamento AllDepartementos[], int TLDepartamentos);

void MostrarListaMedios(Departamento AllDepartamentos[], int TLDepartamentos);

void AsignacionEnMesMenu(Departamento AllDepartementos[], int TLDepartamentos);

#endif // INTERFAZ_H
