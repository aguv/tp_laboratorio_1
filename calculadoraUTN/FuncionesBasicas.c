#include <stdio.h>
#include <stdlib.h>
#include "Aritmetica.h"
#include <conio.h>
#include <unistd.h>
#include "Validaciones.h"
#include "FuncionesBasicas.h"

void MostrarMenu()
{
    // declaro e inicializo las variables necesarias
    int opcionElegida;
    float numeroUno;
    float numeroDos;
    int banderaNumeroUno;
    int banderaDos;
    int banderaResultado;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    double resultadoFactorialA;
    double resultadoFactorialB;
    int esEnteroUno;
    int esEnteroDos;

    banderaNumeroUno = 0;
    banderaDos = 0;
    banderaResultado = 0;


    // comienza el menu, con los condicionales para saber si los operandos fueron ingresados
    do
    {
        if(banderaNumeroUno == 0 && banderaDos == 0)
        {
            system("cls");
            printf("-Bienvenido al trabajo practico numero 1 - CALCULADORA -\n-------------------------------------------------------\nSELECCIONE UNA OPCION: DEL 1 AL 4\n-------------------------------------------------------\n1. Ingresar primer operando --- A = x\n2. Ingresar segundo operando --- B = y\n3. Calcular todas las operaciones\n  A) Calcular la suma: A+B\n  B) Calcular la resta: A-B\n  C) Calcular la multiplicacion: A*B\n  D) Calcular la division: A/B\n  E) Calcular los factoriales: A! y B!\n4. Informar todas las operaciones\n5. Salir\n-------------------------------------------------------\nLA OPCION ELEGIDA ES: ");
            scanf("%d", &opcionElegida);
        } else if (banderaNumeroUno == 1 && banderaDos == 0)
        {
            system("cls");
            printf("-------------------------------------------------------\nSELECCIONE UNA OPCION: DEL 1 AL 4\n-------------------------------------------------------\n");
            printf("1. Ingresar primer operando --- A = %f\n", numeroUno);
            printf("2. Ingresar segundo operando --- B = y\n3. Calcular todas las operaciones\n  A) Calcular la suma: A+B\n  B) Calcular la resta: A-B\n  C) Calcular la multiplicacion: A*B\n  D) Calcular la division: A/B\n  E) Calcular los factoriales: A! y B!\n4. Informar todas las operaciones\n5. Salir\n-------------------------------------------------------\nLA OPCION ELEGIDA ES: ");
            scanf("%d", &opcionElegida);
        } else if (banderaDos == 1 && banderaNumeroUno == 0)
        {
            system("cls");
            printf("-------------------------------------------------------\nSELECCIONE UNA OPCION: DEL 1 AL 4\n-------------------------------------------------------\n1. Ingresar primer operando --- A = x\n");
            printf("2. Ingresar segundo operando --- B = %f\n", numeroDos);
            printf("3. Calcular todas las operaciones\n  A) Calcular la suma: A+B\n  B) Calcular la resta: A-B\n  C) Calcular la multiplicacion: A*B\n  D) Calcular la division: A/B\n  E) Calcular los factoriales: A! y B!\n4. Informar todas las operaciones\n5. Salir\n-------------------------------------------------------\nLA OPCION ELEGIDA ES: ");
            scanf("%d", &opcionElegida);
        } else if (banderaNumeroUno == 1 && banderaDos == 1)
        {
            system("cls");
            printf("-------------------------------------------------------\nSELECCIONE UNA OPCION: DEL 1 AL 4\n-------------------------------------------------------\n");
            printf("1. Ingresar primer operando --- A = %f\n", numeroUno);
            printf("2. Ingresar segundo operando --- B = %f\n", numeroDos);
            printf("3. Calcular todas las operaciones\n  A) Calcular la suma: A+B\n  B) Calcular la resta: A-B\n  C) Calcular la multiplicacion: A*B\n  D) Calcular la division: A/B\n  E) Calcular los factoriales: A! y B!\n4. Informar todas las operaciones\n5. Salir\n-------------------------------------------------------\nLA OPCION ELEGIDA ES: ");
            scanf("%d", &opcionElegida);
        }

        switch(opcionElegida)
        {
        case 1:
            printf("-------------------------------------------------------\n");
            printf("Ingrese el primer operando: ");
            fflush(stdin);
            scanf("%f", &numeroUno);
            esEnteroUno = ValidarEntero(numeroUno);
            banderaNumeroUno = 1;
            break;
        case 2:
            banderaDos = 1;
            printf("-------------------------------------------------------\n");
            printf("Ingrese el segundo operando: ");
            fflush(stdin);
            scanf("%f", &numeroDos);
            esEnteroDos = ValidarEntero(numeroDos);
            break;
        case 3:
            if(banderaNumeroUno != 1 || banderaDos != 1)
            {
                printf("ERROR. Hemos detectado que no ingreso los numeros correctamente. Intente nuevamente.\n");
                printf("Espere un instante para continuar...");
                sleep(3);
                break;
            }
            else
            {
                resultadoSuma = SumarNumeros(numeroUno, numeroDos);
                resultadoResta = RestarNumeros(numeroUno, numeroDos);
                resultadoMultiplicacion = MultiplicarNumeros(numeroUno, numeroDos);
                if(numeroUno != 0 && numeroDos != 0)
                {
                    resultadoDivision = DividirNumeros(numeroUno, numeroDos);
                }
                if(esEnteroUno == 1 || numeroUno >= 0)
                {
                    resultadoFactorialA = Factorial(numeroUno);
                }
                if(esEnteroDos == 1 || numeroDos >= 0)
                {
                    resultadoFactorialB = Factorial(numeroDos);
                }
                banderaResultado = 1;
                break;
            }
        case 4:
            if(banderaNumeroUno == 0 || banderaDos == 0)
            {
                printf("ERROR. Hemos detectado que no ingreso los numeros correctamente. Intente nuevamente.\n");
                printf("Espere un instante para continuar...");
                sleep(3);
                break;
            } else if (banderaResultado == 0)
            {
                printf("ERROR. Hemos detectado que todavia no ha decidido hacer los calculos. Intente nuevamente.\n");
                printf("Espere un instante para continuar...");
                sleep(3);
            }
            else
            {
                if(numeroUno == 0 || numeroDos == 0)
                {
                    printf("-------------------------------------------------------\n");
                    printf("A) La suma es: %.2f\nB) La resta es: %.2f\nC) La multiplicacion es: %.2f\nD) La division es: ERROR - No se puede hacer divisiones con 0\nE) El factorial de A es: %.0lf\n   El de B es: %.0lf", resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoFactorialA, resultadoFactorialB);
                    printf("\nAprete una tecla para continuar...");
                    getch();
                    break;
                }
                else if((esEnteroUno == 0 || numeroUno < 0) && (esEnteroDos == 0 || numeroDos < 0))
                {
                    printf("-------------------------------------------------------\n");
                    printf("A) La suma es: %.2f\nB) La resta es: %.2f\nC) La multiplicacion es: %.2f\nD) La division es: %.2f\nE) El factorial de A es: ERROR. Calculo de factorial con numeros flotantes o negativos\n   El de B es: ERROR. Calculo de factorial con numeros flotantes o negativos", resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision);
                    printf("\nAprete una tecla para continuar...");
                    getch();
                    break;
                }
                else if(esEnteroUno == 0 || numeroUno < 0)
                {
                    printf("-------------------------------------------------------\n");
                    printf("A) La suma es: %.2f\nB) La resta es: %.2f\nC) La multiplicacion es: %.2f\nD) La division es: %.2f\nE) El factorial de A es: ERROR. Calculo de factorial con numeros flotantes o negativos\n   El de B es: %.0lf", resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, resultadoFactorialB);
                    printf("\nAprete una tecla para continuar...");
                    getch();
                    break;
                }
                else if(esEnteroDos == 0 || numeroDos < 0)
                {
                    printf("-------------------------------------------------------\n");
                    printf("A) La suma es: %.2f\nB) La resta es: %.2f\nC) La multiplicacion es: %.2f\nD) La division es: %.2f\nE) El factorial de A es: %.0lf\n   El de B es: ERROR. Calculo de factorial con numeros flotantes o negativos", resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, resultadoFactorialA);
                    printf("\nAprete una tecla para continuar...");
                    getch();
                    break;
                }
                else
                {
                    printf("-------------------------------------------------------\n");
                    printf("A) La suma es: %.2f\nB) La resta es: %.2f\nC) La multiplicacion es: %.2f\nD) La division es: %.2f\nE) El factorial de A es: %.0lf\n   El de B es: %.0lf", resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, resultadoFactorialA, resultadoFactorialB);
                    printf("\nAprete una tecla para continuar...");
                    getch();
                    break;
                }

            }
        }
    } while (opcionElegida != 5);
}
