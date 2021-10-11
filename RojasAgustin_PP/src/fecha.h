/*
 * fecha.h
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

typedef struct{
	int dia;
	int mes;
	int anio;
}sFecha;

int fecha_cargarAnio(void);
int fecha_cargarMes(void);
int fecha_cargarDia(void);

#endif /* FECHA_H_ */
