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
#define TAMESTADIAS 100

typedef struct{
	int id;
	int idDuenio;
	int idPerro;
	int isEmpty;
	sFecha fecha;
}sEstadiaDiaria;


/**
 * @fn int estadia_buscarEstadiaPorId(sEstadiaDiaria[], int, int)
 * @brief Busca una estadia por id y regresa el index que corresponde a ese id en el array
 *
 * @param estadias[] sEstadiaDiaria - El array de estadias
 * @param tamEstadias int - La longitud del array
 * @param id int - El id de la estadia buscada.
 * @return index int - -1 si hay un error o no encuentra la estadia en el array.
 */
int estadia_buscarEstadiaPorId(sEstadiaDiaria estadias[], int tamEstadias, int id);
/**
 * @fn int estadia_buscarEspacioLibre(sEstadiaDiaria[], int)
 * @brief Encuentra la primera posicion vacia en el array y la devuelve
 *
 * @param estadias[] sEstadiaDiaria - El array de estadias
 * @param tamEstadias int - La longitud del array
 * @return index int - El primer index vacio encontrado.
 * 					   -1 si hay un error (array vacio, longitud invalida o no encuentra ningun espacio vacio).
 */
int estadia_buscarEspacioLibre(sEstadiaDiaria estadias[], int tamEstadias);
/**
 * @fn void estadia_inicializar(sEstadiaDiaria[], int)
 * @brief Inicializa el array asignando 1 a todas los campos isEmpty del mismo para indicar que estan vacias.
 *
 * @param estadias[] sEstadiaDiaria - El array de estadias
 * @param tamEstadias int - La longitud del array
 */
void estadia_inicializar(sEstadiaDiaria estadias[], int tamEstadias);


#endif /* ESTADIADIARIA_H_ */
