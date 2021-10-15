/*
 * estadiaPerro.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Usuario
 */

#ifndef ESTADIA_PERRO_H_
#define ESTADIA_PERRO_H_
#include <stdio.h>
#include <stdlib.h>
#include "perros.h"
#include "estadiaDiaria.h"

/**
 * @fn int estadiaPerro_sacarPerroConMasEstadias(sEstadiaDiaria[], int, sPerro[], int)
 * @brief Cuenta cuantas estadias tiene cada perro y muestra cual tiene mas.
 *
 * @param estadias
 * @param tamEstadias
 * @param perros
 * @param tamPerros
 * @return
 */
int estadiaPerro_sacarPerroConMasEstadias(sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[],int tamPerros);

#endif /* ESTADIA_PERRO_H_ */
