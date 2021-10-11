/*
 * perros.h
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */

#ifndef PERROS_H_
#define PERROS_H_
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "string.h"
#define TAMPERRROS 3
#define TAMNOMBRE 21
#define TAMRAZA 21

typedef struct{
	int id;
	char nombre[TAMNOMBRE];
	char raza[TAMRAZA];
	int edad;
}sPerro;

//void hardCodearPerros(sPerro perros[], int tamPerros);
int perro_mostrarPerros(sPerro perros[], int tamPerros);
void perro_mostrarPerro(sPerro perro);
int perro_calcularPromedioDeEdadDeLosPerros(sPerro perros[],int tamPerros);
int perro_elegirPerro();
int perro_copiarNombre(sPerro perros[],int tam, int id,char*nombre);

#endif /* PERROS_H_ */
