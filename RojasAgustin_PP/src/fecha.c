/*
 * fecha.c
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */


#include "fecha.h"

int fecha_cargarAnio(void){
	int anio;
	anio = getInteger("Año: ", "Error. Reingrese el año (de 2021 a 2023)", 2021, 2023);
	return anio;
}
int fecha_cargarMes(void){
	int mes;
	mes = getInteger("Mes: ", "Error. Reingrese el mes", 1, 12);;
	return mes;
}
int fecha_cargarDia(void){
	int dia;
	dia = getInteger("Dia: ", "Error. Reingrese el año", 1, 31);
	return dia;
}
