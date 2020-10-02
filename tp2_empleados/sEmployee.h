#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct {
    int id;
    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

void initEmployees(sEmployee arrayEmployees[], int len);
int findIndex(sEmployee arrayEmployees[], int len);
int addEmployees(sEmployee arrayEmployees[], int len, int id);
void modifyEmployees(sEmployee arrayEmployees[], int len, int id, int propToChange);
int findEmployeeById(sEmployee arrayEmployees[], int len, int id);
void deleteEmployee(sEmployee arrayEmployees[], int len, int id);
void sortEmployees(sEmployee arrayEmployees[], int len);
void mostrarPromedio(sEmployee arrayEmployees[], int len);
float buscarSueldoAlto(sEmployee arrayEmployees[], int len);
void mostrarEmpleadosTabla(sEmployee arrayEmployees[], int len);
