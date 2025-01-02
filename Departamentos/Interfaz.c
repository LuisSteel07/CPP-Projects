#include "Interfaz.h"

void StartMenu(Departamento AllDepartementos[], int TLDepartamentos){
    char select[2];
    int i = 0;

    while(i == 0){
        system("cls");
        printf("<- Menu de administracion de Departamentos de DATYS ->\n");
        printf("1- Asignar Medio Basico\n");
        printf("2- Mostrar Medios Basicos de Departamento por Estado\n");
        printf("3- Departamento con mas Medios Basicos en Deterioro\n");
        printf("4- Mostrar Reporte de un Departamento\n");
        printf("5- Encontrar Departamento por un Medio Basico\n");
        printf("6- Mostrar Asignaciones por Mes especifico\n");
        printf("7- Mostrar Lista de Medios Basicos por Departamento\n");
        printf("8- Salir\n\n");
        printf("-> ");
        fflush(stdin);
        gets(select);

        if(!(ValidarOperacion(select, 1, 8))){
            printf("\nValor Invalido\n");
            system("pause");
            continue;
        }

        switch(atoi(&select)){
            case 1:
                InicializarMedios(AllDepartementos,TLDepartamentos);
                break;
            case 2:
                {
                    Departamento *dp = SelectDepartamento(AllDepartementos,TLDepartamentos);
                    mostrarMediosPorEstado(dp);
                }
                system("pause");
                break;
            case 3:
                {
                    Departamento *dp = deptoConMasRotos(AllDepartementos,TLDepartamentos);
                    printf("\nDepartamento con mas Medios Rotos\n");
                    printf("Departamento No. %d\n", dp->id);
                    printf("Jefe: %s\n", dp->jefe);
                    printf("Cant. Trabajadores: No. %d\n", dp->cantTrabajadores);
                    printf("Cant. Medios Basicos: No. %d\n", dp->cantMediosBasicos);
                    mostrarMediosPorEstado(dp);
                }
                system("pause");
                break;
            case 4:
                {
                    Departamento *dp = SelectDepartamento(AllDepartementos,TLDepartamentos);
                    mostrarReporteDepartamentos(dp);
                }
                system("pause");
                break;
            case 5:
                BuscarDepartamentoConID(AllDepartementos, TLDepartamentos);
                system("pause");
                break;
            case 6:
                AsignacionEnMesMenu(AllDepartementos, TLDepartamentos);
                break;
            case 7:
                MostrarListaMedios(AllDepartementos, TLDepartamentos);
                break;
            case 8:
                i++;
                break;
        }
    }
}

Departamento* SelectDepartamento(Departamento dp[], int cantidad){
    int i;
    char select[2];

    printf("<-- Seleccione un Departamento por su No. -->");
    for(i = 0; i < cantidad; i++){
        printf("\nDepartamento No: %d\nJefe: %s\nCant. Medios: %d\n", dp[i].id, dp[i].jefe, dp[i].cantMediosBasicos);
    }

    i = 0;
    do{
        fflush(stdin);
        gets(select);
        if(!(ValidarOperacion(select, 1, cantidad))){
            printf("\nValor Invalido\n");
            continue;
        }

        i++;
    }while (i == 0);

    return &dp[atoi(&select)-1];
}

void InicializarMedios(Departamento dp[],int cantidad){
    int i = 0;
    char op[2];

    printf("\n<- Inicializando Medios Basicos ->\n");
    printf("Como inicializar los Medios Basicos\n");
    printf("-1- Automatico\t\t-2- Manual\n\n");
    do{
        fflush(stdin);
        gets(op);
        if(!(ValidarOperacion(op,1,2))){
            printf("\nValor Invalido\n");
            continue;
        }
        switch (atoi(&op)) {
            case 1:
               AutomaticInitMedios(dp);
               i++;
               break;
            case 2:
               ManualInitMedios(dp, cantidad);
               i++;
               break;
        }
    }while(i == 0);
}

void InicializarDepartamentos(Departamento dp[],int cantidad){
     int i = 0;
     char op[2];

     printf("<- Inicializando Departamentos ->\n");
     printf("Como inicializar los Departamentos\n");
     printf("-1- Automatico\t\t-2- Manual\n\n");
     do{
         fflush(stdin);
         gets(op);

         if(!(ValidarOperacion(op,1,2))){
             printf("\nValor Invalido o Fuera de Rango\n");
             continue;
         }

         switch (atoi(&op)) {
             case 1:
                AutomaticInitDepartamentos(dp);
                i++;
                break;
             case 2:
                ManualInitDepartamentos(dp, cantidad);
                i++;
                break;
         }
     }while(i == 0);
}

void AutomaticInitDepartamentos(Departamento dp[]){
    InitDepartamento(&dp[0],1,"Pedro",12);
    InitDepartamento(&dp[1],2,"Alfredo",16);
    InitDepartamento(&dp[2],3,"Maria",23);
    InitDepartamento(&dp[3],4,"Yailet",19);
    InitDepartamento(&dp[4],5,"Jenifer",11);
}

void ManualInitDepartamentos(Departamento dp[], int cantidad){
    char jefe[50], *CantidadTrabajadores;
    int j = 0;

    do{
        printf("Para Departamento No: %d\t\tFaltan: %d\n",(j+1), cantidad-j);
        printf("Jefe: ");
        fflush(stdin);
        gets(jefe);

        if(ValidarPalabra(jefe)){
            printf("\nValor Invalido \"No puede colocar numeros en su nombre\"\n");
            continue;
        }

        printf("Cant. de Trabajadores: ");
        gets(CantidadTrabajadores);

        if(ValidarNumero(CantidadTrabajadores)){
            printf("\nValor Invalido, \"No puede colocar letras en este valor\"\n");
            continue;
        }

        InitDepartamento(&dp[j],(j+1),jefe,atoi(CantidadTrabajadores));
        printf("\n");
        j++;
    }while(j < cantidad);
}

void AutomaticInitMedios(Departamento dp[]){
    AgregarMedioBasico(&dp[0],"Televisor",0,1);
    AgregarMedioBasico(&dp[0],"Mesa",1,4);
    AgregarMedioBasico(&dp[0],"Ordenador",2,5);
    AgregarMedioBasico(&dp[0],"Laptop",1,7);
    AgregarMedioBasico(&dp[0],"Ventilador",0,8);
    AgregarMedioBasico(&dp[0],"Ordenador",0,2);

    AgregarMedioBasico(&dp[1],"Mesa",1,7);
    AgregarMedioBasico(&dp[1],"Mesa",1,3);
    AgregarMedioBasico(&dp[1],"Mesa",1,5);
    AgregarMedioBasico(&dp[1],"Mesa",0,3);
    AgregarMedioBasico(&dp[1],"Mesa",0,5);
    AgregarMedioBasico(&dp[1],"Mesa",0,2);
    AgregarMedioBasico(&dp[1],"Mesa",0,2);
    AgregarMedioBasico(&dp[1],"Mesa",2,1);
    AgregarMedioBasico(&dp[1],"Mesa",1,2);
    AgregarMedioBasico(&dp[1],"Mesa",2,4);

    AgregarMedioBasico(&dp[2],"Mesa",1,4);
    AgregarMedioBasico(&dp[2],"Mesa",2,5);
    AgregarMedioBasico(&dp[2],"Mesa",2,2);
    AgregarMedioBasico(&dp[2],"Mesa",2,3);
    AgregarMedioBasico(&dp[2],"Mesa",0,1);
    AgregarMedioBasico(&dp[2],"Mesa",0,10);
    AgregarMedioBasico(&dp[2],"Mesa",1,9);

    AgregarMedioBasico(&dp[3],"Mesa",2,11);
    AgregarMedioBasico(&dp[3],"Mesa",2,10);
    AgregarMedioBasico(&dp[3],"Mesa",0,2);
    AgregarMedioBasico(&dp[3],"Mesa",0,2);
    AgregarMedioBasico(&dp[3],"Mesa",0,2);
    AgregarMedioBasico(&dp[3],"Mesa",1,3);
    AgregarMedioBasico(&dp[3],"Mesa",0,4);
    AgregarMedioBasico(&dp[3],"Mesa",1,5);
    AgregarMedioBasico(&dp[3],"Mesa",1,1);

    AgregarMedioBasico(&dp[4],"Mesa",1,3);
    AgregarMedioBasico(&dp[4],"Mesa",2,3);
    AgregarMedioBasico(&dp[4],"Mesa",2,2);
    AgregarMedioBasico(&dp[4],"Mesa",2,5);
    AgregarMedioBasico(&dp[4],"Mesa",2,6);
    AgregarMedioBasico(&dp[4],"Mesa",0,10);
    AgregarMedioBasico(&dp[4],"Mesa",0,10);
    AgregarMedioBasico(&dp[4],"Mesa",0,0);
}

void ManualInitMedios(Departamento dp[], int cantidad){
    int i = 0;
    char tipo[40], mes[3], estado[3];
    Departamento *deptos = SelectDepartamento(dp,cantidad);
    do{
        fflush(stdin);
        printf("Diga Tipo: ");
        gets(tipo);

        printf("\nDiga Estado del Medio Basico\n");
        printf("0- OPTIMO\n");
        printf("1- DETERIORADO\n");
        printf("2- ROTO\n");
        printf("-> ");
        fflush(stdin);
        gets(estado);
        if(!(ValidarOperacion(estado,0,2))){
            printf("\nValor Invalido\n");
            system("pause");
            continue;
        }

        printf("Diga Mes de Asignacion: \n");
        printf("1- Enero\t\t2-Febrero\n");
        printf("3- Marzo\t\t4-Abril\n");
        printf("5- Mayo\t\t\t6-Junio\n");
        printf("7- Julio\t\t8-Agosto\n");
        printf("9- Septiembre\t\t10-Octubre\n");
        printf("11- Noviembre\t\t12-Diciembre\n");
        fflush(stdin);
        gets(mes);
        if(!(ValidarOperacion(mes,1,12))){
            printf("\nValor Invalido\n");
            system("pause");
            continue;
        }

        AgregarMedioBasico(deptos,tipo,atoi(estado),atoi(mes));
        i++;
    }while (i == 0);
}

void AsignacionEnMesMenu(Departamento AllDepartementos[], int TLDepartamentos){
    char mes[2];
    int i = 0;
    printf("\nDiga el mes a buscar:\n");
    printf("1- Enero\t\t2-Febrero\n");
    printf("3- Marzo\t\t4-Abril\n");
    printf("5- Mayo\t\t\t6-Junio\n");
    printf("7- Julio\t\t8-Agosto\n");
    printf("9- Septiembre\t\t10-Octubre\n");
    printf("11- Noviembre\t\t12-Diciembre\n\n");
    do{
        printf("-> ");
        fflush(stdin);
        gets(mes);
        if(!(ValidarOperacion(mes,1,12))){
            printf("\nValor invalido\n");
            continue;
        }
        i++;
    }while(i == 0);

    printf("La cantidad de Asignaciones fue de: %d\n", asignacionEnMes(AllDepartementos,TLDepartamentos,atoi(mes)));
    system("pause");
}

void BuscarDepartamentoConID(Departamento AllDepartementos[], int TLDepartamentos){
    char IDSearch[5];
    int i = 0;

    do{
        printf("\nDiga el ID del Medio a Buscar: ");
        fflush(stdin);
        gets(IDSearch);

        if(ValidarNumero(IDSearch)){
            printf("\nValor Invalido \"No puede colocar letras en este valor\"\n");
            continue;
        }

        Departamento *SearchDP = encontrarDepartamentoPorMedio(AllDepartementos, TLDepartamentos, atoi(IDSearch));

        if(SearchDP == NULL){
            printf("\nMedio no Encontrado\n");
            system("pause");
            continue;
        }

        printf("\nEl medio con ID: %d pertenece al Departamento No. %d Jefe: %s\n",atoi(IDSearch),SearchDP->id,SearchDP->jefe);
        i++;
    }while(i == 0);
}

void MostrarListaMedios(Departamento AllDepartamentos[], int TLDepartamentos){
    Departamento *dp = SelectDepartamento(AllDepartamentos, TLDepartamentos);

    system("cls");
    int i;

    printf("<-- Departamento No. %d -->\n", dp->id);
    if(dp->cantMediosBasicos == 0){
        printf("\nDepartamento sin Medios Basicos\n");
    } else {
        for(i = 0; i < dp->cantMediosBasicos; i++){
            printf("\nMedio Basico ID: %d\n",dp->mediosBasicos[i].id);
            printf("Tipo: %s\n",dp->mediosBasicos[i].tipo);

            switch (dp->mediosBasicos[i].estado) {
                case OPTIMO:
                    printf("Estado: OPTIMO\n");
                    break;
                case DETERIORADO:
                    printf("Estado: DETERIORADO\n");
                    break;
                case ROTO:
                    printf("Estado: ROTO\n");
                    break;
            }

            printf("Mes: %d\n",dp->mediosBasicos[i].mesAsignado);
        }
    }

    system("pause");
}
