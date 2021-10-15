/*
 * estadia-duenio.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Usuario
 */

#ifndef ESTADIA_DUENIO_H_
#define ESTADIA_DUENIO_H_
#include <stdio.h>
#include <stdlib.h>
#include "duenio.h"
#include "estadiaDiaria.h"

/**
 * @fn int estadiaDuenio_ordenarListadoEstadias(sEstadiaDiaria[], int, sDuenio[], int)
 * @brief Ordena las estadias segun la fecha y el nombre si las fechas son iguales
 *
 * @param estadias
 * @param tamEstadias
 * @param duenios
 * @param tamDuenios
 * @return
 */
int estadiaDuenio_ordenarListadoEstadias(sEstadiaDiaria estadias[],int tamEstadias,sDuenio duenios[], int tamDuenios);

#endif /* ESTADIA_DUENIO_H_ */
