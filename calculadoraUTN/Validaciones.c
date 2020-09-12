#include "Validaciones.h"

/** \brief esta funcion recibe unnumero y chequea si es entero
 *
 * \param numero float
 * \return int devuelve 1 si es entero, 0 si es flotante
 *
 */
int ValidarEntero(float numero)
{
    int retorno = 0;
    int numeroEnteroTest;
    numeroEnteroTest = (int)numero;
    if( numero - numeroEnteroTest == 0)
    {
        return retorno = 1;
    }
    return retorno;
}


