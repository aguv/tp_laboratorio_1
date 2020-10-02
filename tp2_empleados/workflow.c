#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "sEmployee.h"
#define L 1000

void abmWorkflow()
{
    int id;
    sEmployee arrayEmployees[L];
    int opcionIngresada;
    int opcionModificacion;
    int idModificacion;
    char confirmacionBorrado;
    int idBorrado;
    int banderaEntradaDatos;

    id = 0;
    opcionIngresada = 0;
    banderaEntradaDatos = 0;

    initEmployees(arrayEmployees, L);

    while(opcionIngresada != 5)
    {
        printf("\n///////////////////////////////////////////\n");
        printf("////////////  ABM DE EMPLEADOS ////////////\n");
        printf("///////////////////////////////////////////\n");
        utn_getNumber(&opcionIngresada, 5, 1, 5, "1. Ingresar un empleado\n2. Modificar un empleado por ID\n3. Baja de empleado por ID\n4. Informar:\n   -Por apellido y sector\n   -Total de salarios, el promedio y cuantos son los empleados que lo igualan o superan\n5. Salir\n-La opcion elegida: ", "Error. Ingrese nuevamente\n");
        switch(opcionIngresada)
        {
            case 1:
                if(addEmployees(arrayEmployees, L, id) == 0)
                {
                banderaEntradaDatos = 1;
                id ++;
                } else
                {
                 printf("Lo siento, ha habido un error");
                }
                system("cls");
                break;
            case 2:
                if(banderaEntradaDatos == 1)
                {
                    utn_getNumber(&idModificacion, 10000, 1, 5, "Ingrese el ID del empleado que desea modificar: \nID: ", "Error. Ingrese nuevamente");
                    utn_getNumber(&opcionModificacion, 5, 1, 5, "Ingrese la opcion que desea modificar... \n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\n5. Salir\nLa opcion ingresada es: ", "Error. Ingrese nuevamente\n");
                    modifyEmployees(arrayEmployees, L, idModificacion, opcionModificacion);
                } else
                {
                    printf("Primero tiene que cargar datos. Presione enter para continuar\n");
                    pause();
                }
                system("cls");
                break;
            case 3:
                if(banderaEntradaDatos == 1)
                {
                    utn_getNumber(&idBorrado, 10000, 1, 5, "Ingrese el ID del empleado que desea borrar\nID: ", "Ingrese nuevamente\n");
                    utn_getChar("Esta seguro que desea borrarlo (S para continuar - cualquier otra tecla anulara la operacion): ", "Error, intente nuevamente\n", &confirmacionBorrado);
                    if(confirmacionBorrado == 's' || confirmacionBorrado == 'S')
                    {
                        deleteEmployee(arrayEmployees, L, idBorrado);
                    }
                } else
                {
                   printf("Primero tiene que cargar datos. Presione enter para continuar\n");
                   pause();
                }
                system("cls");
                break;
            case 4:
                if(banderaEntradaDatos == 1)
                {
                    system("cls");
                    sortEmployees(arrayEmployees, L);
                    mostrarEmpleadosTabla(arrayEmployees, L);
                    mostrarPromedio(arrayEmployees, L);
                    printf("Presione enter para continuar");
                    pause();
                } else
                {
                    printf("Primero tiene que cargar datos. Presione enter para continuar\n");
                    pause();
                }
                system("cls");
                break;
        }
    }

}
