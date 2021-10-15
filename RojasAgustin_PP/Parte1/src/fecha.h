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

/**
 * @fn int fecha_cargarAnio(void)
 * @brief Permite al usuario cargar el año
 *
 * @return int anio - El año ingresado por el usuario
 */
int fecha_cargarAnio(void);
/**
 * @fn int fecha_cargarMes(void)
 * @brief Permite al usuario cargar el mes
 *
 * @return int mes - El mes ingresado por el usuario
 */
int fecha_cargarMes(void);
/**
 * @fn int fecha_cargarDia(void)
 * @brief Permite al usuario cargar el dia
 *
 * @return int dia - El dia ingresado por el usuario
 */
int fecha_cargarDia(void);

#endif /* FECHA_H_ */
