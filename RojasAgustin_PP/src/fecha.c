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
	char diaCarga[2];
	int dia;
	getString(diaCarga, "Dia: ", "Error. Reingrese el dia: ", 2);
	while(!esNumerico(diaCarga, 2)){
		getString(diaCarga, "Dia: ", "Error. Reingrese el dia: ", 2);
	}
	dia = atoi(diaCarga);
	while(dia < 1 || dia > 31){
		getString(diaCarga, "Error. Reingrese el dia: ", "Error. Reingrese el dia: ", 2);
		while(!esNumerico(diaCarga, 2)){
			printf("Error. Reingrese el dia.\n");
			getString(diaCarga, "Error. Reingrese el dia: ", "Error. Reingrese el dia: ", 2);
		}
		dia = atoi(diaCarga);
	}
	return dia;
}
