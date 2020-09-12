#include <stdio.h>
#include <stdlib.h>
#include "Aritmetica.h"

/** \brief esta funcion recibe dos numeros y los suma
 *
 * \param primerNumero float
 * \param segundoNumero float
 * \return float devuelve el resultado en float
 *
 */
float SumarNumeros(float primerNumero, float segundoNumero)
{
    float suma;
    suma = primerNumero + segundoNumero;
    return suma;
}

/** \brief esta funcion recibe dos numeros y los resta
 *
 * \param primerNumero float
 * \param segundoNumero float
 * \return float devuelve el resultado en float
 *
 */
float RestarNumeros(float primerNumero, float segundoNumero)
{
    float resta;
    resta = primerNumero - segundoNumero;
    return resta;
}

/** \brief esta funcion recibe dos numeros y los multiplica
 *
 * \param primerNumero float
 * \param segundoNumero float
 * \return float devuelve el resultado en float
 *
 */
float MultiplicarNumeros(float primerNumero, float segundoNumero)
{
    float producto;
    producto = primerNumero * segundoNumero;
    return producto;
}

/** \brief esta funcion recibe dos numeros y los divide
 *
 * \param primerNumero float
 * \param segundoNumero float
 * \return float devuelve el resultado en float
 *
 */
float DividirNumeros(float primerNumero, float segundoNumero)
{
    float division;
    division = primerNumero / segundoNumero;
    return division;
}

/** \brief esta funcion recibe un numero y calcula el factorial
 *
 * \param numero float
 * \return double devuelve el numero en double por la capacidad de los otros tipos de numeros
 *
 */
double Factorial(float numero)
{
    double resultado;
    if (numero == 0)
    {
        return 1;
    }
    resultado = numero * Factorial(numero - 1);
    return resultado;
}

