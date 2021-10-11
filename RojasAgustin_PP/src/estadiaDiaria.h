/*
 * estadiaDiaria.h
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */

#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funciones.h"
#include "fecha.h"
#define TAMDUENIO 35
#define TAMTELEFONO 10
#define TAMESTADIAS 5

typedef struct{
	int id;
	char nombreDuenio[TAMDUENIO];
	char telefonoContacto[TAMTELEFONO];
	int idPerro;
	int isEmpty;
	sFecha fecha;
}sEstadiaDiaria;


int estadia_ordenarListadoEstadias(sEstadiaDiaria estadias[],int tamEstadias);
int estadia_buscarEstadiaPorId(sEstadiaDiaria estadias[], int tamEstadias, int id);
int estadia_buscarEspacioLibre(sEstadiaDiaria estadias[], int tamEstadias);
void estadia_inicializar(sEstadiaDiaria estadias[], int tamEstadias);
void hardCode(sEstadiaDiaria estadias[], int tamEstadias);


#endif /* ESTADIADIARIA_H_ */
