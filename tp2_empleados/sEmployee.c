#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "sEmployee.h"

void initEmployees(sEmployee arrayEmployees[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        arrayEmployees[i].isEmpty = 1;
    }
}

int findIndex(sEmployee arrayEmployees[], int len)
{
    int i;
    int index = -1;
    for (i = 0; i < len; i++)
    {
        if(arrayEmployees[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int addEmployees(sEmployee arrayEmployees[], int len, int id)
{
    int retorno = -1;
    int index;
    index = findIndex(arrayEmployees, len);
    if(index >= 0)
    {
        arrayEmployees[index].id = id + 1;
        while(utn_getString("Ingrese el nombre: \n", "Error\n", arrayEmployees[index].name) == -1)
        {
            utn_getString("Ingrese el nombre: \n", "Error\n", arrayEmployees[index].name);
        }
        UpperLower(arrayEmployees[index].name);
        while(utn_getString("Ingrese el apellido: \n", "Intente nuevamente\n", arrayEmployees[index].lastName) == -1)
        {
            utn_getString("Ingrese el apellido: \n", "Intente nuevamente\n", arrayEmployees[index].lastName);
        }
        UpperLower(arrayEmployees[index].lastName);
        utn_getFloat(&arrayEmployees[index].salary, 1000000, 0, 5, "Ingrese el salario: \n", "Error. Ingrese nuevamente: \n");
        utn_getNumber(&arrayEmployees[index].sector, 5, 1, 5, "Ingrese el sector: (del 1 al 5)\n", "Error.\n");
        arrayEmployees[index].isEmpty = 0;
        retorno = 0;
    } else
    {
        printf("Lo siento, no hay lugar.\n");
    }

    return retorno;
}

void modifyEmployees(sEmployee arrayEmployees[], int len, int id, int propToChange)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(arrayEmployees[i].id == id && arrayEmployees[i].isEmpty == 0)
        {
            switch(propToChange)
            {
                case 1:
                    while(utn_getString("Ingrese el nombre: \n", "Intente nuevamente\n", arrayEmployees[i].name) == -1)
                    {
                        utn_getString("Ingrese el nombre: \n", "Intente nuevamente\n", arrayEmployees[i].name);
                    }
                    UpperLower(arrayEmployees[i].name);
                    break;
                case 2:
                    while(utn_getString("Ingrese el apellido: \n", "Intente nuevamente\n", arrayEmployees[i].lastName) == -1)
                    {
                        utn_getString("Ingrese el apellido: \n", "Intente nuevamente\n", arrayEmployees[i].lastName);
                    }
                    UpperLower(arrayEmployees[i].lastName);
                    break;
                case 3:
                    utn_getFloat(&arrayEmployees[i].salary, 150000, 0, 5, "Ingrese el salario: \n", "Error. Ingrese nuevamente: \n");
                    break;
                case 4:
                    utn_getNumber(&arrayEmployees[i].sector, 5, 1, 5, "Ingrese el sector: (del 1 al 5)\n", "Error. Ingrese nuevamente: ");
                    break;
            }
        }
    }
}

int findEmployeeById(sEmployee arrayEmployees[], int len, int id)
{
    int retorno = -1;
    int i;
    for(i = 0; i < len; i++)
    {
        if(arrayEmployees[i].id == id && arrayEmployees[i].isEmpty == 0)
        {
            retorno = i;
        }
    }
    return retorno;
}

void deleteEmployee(sEmployee arrayEmployees[], int len, int id)
{
    int index;

    index = findEmployeeById(arrayEmployees, len, id);
    if(index >= 0)
    {
        arrayEmployees[index].isEmpty = 1;
    } else
    {
    printf("Ha habido un error. Intente nuevamente\n");
    }
}

void sortEmployees(sEmployee arrayEmployees[], int len)
{
    sEmployee auxiliar = {};
    int i;
    int j;
    if(len > 0 && arrayEmployees != NULL)
        {
            for(i=0; i<len - 1; i++)
            {
                for(j=i+1; j<len; j++)
                {
                    if(strcmp(arrayEmployees[j].lastName, arrayEmployees[i].lastName) < 0)
                    {
                        auxiliar = arrayEmployees[i];
                        arrayEmployees[i] = arrayEmployees[j];
                        arrayEmployees[j] = auxiliar;
                    } else if(strcmp(arrayEmployees[j].lastName, arrayEmployees[i].lastName) == 0 && arrayEmployees[j].sector < arrayEmployees[i].sector)
                    {
                        auxiliar = arrayEmployees[i];
                        arrayEmployees[i] = arrayEmployees[j];
                        arrayEmployees[j] = auxiliar;
                    }
                }
            }
        }
}

void mostrarPromedio(sEmployee arrayEmployees[], int len)
{
    float totalSalario;
    float promedioSalario;
    int ocurrencias;
    int ocurrenciasArribaPromedio;
    int i;

    totalSalario = 0;
    ocurrencias = 0;
    ocurrenciasArribaPromedio = 0;

    for(i = 0; i < len; i++)
    {
        if(arrayEmployees[i].isEmpty == 0)
        {
            totalSalario += arrayEmployees[i].salary;
            ocurrencias ++;
        }
    }

    promedioSalario = totalSalario / ocurrencias;

    for(i = 0; i < len; i++)
    {
        if(arrayEmployees[i].salary >= promedioSalario && arrayEmployees[i].isEmpty == 0)
        {
            ocurrenciasArribaPromedio++;
        }
    }


    printf("\nEl salario total es: %f", totalSalario);
    printf("\nEl promedio es: %f", promedioSalario);
    printf("\nHay %d personas con el sueldo arriba o igual que promedio\n\n", ocurrenciasArribaPromedio);
}

float buscarSueldoAlto(sEmployee arrayEmployees[], int len)
{
    float sueldoMasAlto;
    int i;

    for(i = 0; i < len; i++)
    {
        if(i == 0 || arrayEmployees[i].salary > sueldoMasAlto)
        {
            sueldoMasAlto = arrayEmployees[i].salary;
        }
    }

    return sueldoMasAlto;
}

void mostrarEmpleadosTabla(sEmployee arrayEmployees[], int len)
{
    int i;
    printf("-----------------------------------------------------------\n");
    printf("ID --- APELLIDO ------ NOMBRE ------ SALARIO ------- SECTOR\n");
    for(i = 0; i < len; i++)
    {
        if(arrayEmployees[i].isEmpty == 0)
        {
            printf("%d    %10s %12s %15.2f %10i\n", arrayEmployees[i].id, arrayEmployees[i].lastName, arrayEmployees[i].name, arrayEmployees[i].salary, arrayEmployees[i].sector);
        }
    }
}
