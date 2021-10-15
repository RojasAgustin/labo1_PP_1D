/*
 * duenio.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Usuario
 */

#ifndef DUENIO_H_
#define DUENIO_H_
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct{
int id;
char nombre[41];
int telefono;
}sDuenio;

/**
 * @fn int duenio_elegirDuenio()
 * @brief Muestra la lista de dueños y se pide elegir uno
 *
 * @return
 */
int duenio_elegirDuenio();
/**
 * @fn int duenio_copiarNombre(sDuenio[], int, int, char*)
 * @brief Copia el nombre del nueño en la variable nombre para mostrarlo en la funcion de mostrar estadias y que no aparezca el ID
 *
 * @param duenios
 * @param tam
 * @param id
 * @param nombre
 * @return
 */
int duenio_copiarNombre(sDuenio duenios[],int tam, int id,char*nombre);
/**
 * @fn int duenio_copiarTelefono(sDuenio[], int, int, int*)
 * @brief Copia el telefono del nueño en la variable nombre para mostrarlo en la funcion de mostrar estadias.
 *
 * @param duenios
 * @param tam
 * @param id
 * @param telefono
 * @return
 */
int duenio_copiarTelefono(sDuenio duenios[],int tam, int id,int*telefono);
/**
 * @fn void duenio_cambiarTelefono(sDuenio*, int)
 * @brief Cambia el telefono hardcodeado por el que recibe como parametro
 *
 * @param duenio
 * @param telefono
 */
void duenio_cambiarTelefono(sDuenio* duenio,int telefono);
/**
 * @fn int duenio_buscarDuenioPorId(sDuenio[], int, int)
 * @brief Busca el dueño por el ID ingresado y devuelve su posicion en el array
 *
 * @param duenios
 * @param tam
 * @param id
 * @return
 */
int duenio_buscarDuenioPorId(sDuenio duenios[],int tam, int id);

#endif /* DUENIO_H_ */
