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

int duenio_elegirDuenio();
int duenio_copiarNombre(sDuenio duenios[],int tam, int id,char*nombre);
int duenio_copiarTelefono(sDuenio duenios[],int tam, int id,int*telefono);
void duenio_cambiarTelefono(sDuenio* duenio,int telefono);
int duenio_buscarDuenioPorId(sDuenio duenios[],int tam, int id);

#endif /* DUENIO_H_ */
