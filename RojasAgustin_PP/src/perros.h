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

/**
 * @fn int perro_mostrarPerros(sPerro[], int)
 * @brief Muestra el listado de los perros.
 *
 * @param perros[] sPerro - El array de perros
 * @param tamPerros int - La longitud del array
 * @return retorno int - -1 si hay un error (array vacio o longitud invalida). 0 Si puede ingresar al primer if.
 */
int perro_mostrarPerros(sPerro perros[], int tamPerros);
/**
 * @fn void perro_mostrarPerro(sPerro)
 * @brief Muestra un solo perro.
 *
 * @param perro sPerro - El perro a mostrar.
 */
void perro_mostrarPerro(sPerro perro);
/**
 * @fn int perro_calcularPromedioDeEdadDeLosPerros(sPerro[], int)
 * @brief Calcula el promedio de edad de los perros y lo muestra.
 *
 * @param perros[] sPerro - El array de perros
 * @param tamPerros int - La longitud del array
 * @return retorno int - -1 si hay un error (array vacio/longitud invalida). 0 Si puede calcular el promedio.
 */
int perro_calcularPromedioDeEdadDeLosPerros(sPerro perros[],int tamPerros);
/**
 * @fn int perro_elegirPerro()
 * @brief Le permite al usuario elegir uno de los perros.
 *
 * @return id int - El id del perro. Lobo = 7000. Sheila = 7001. Reina = 7002.
 */
int perro_elegirPerro();
/**
 * @fn int perro_copiarNombre(sPerro[], int, int, char*)
 * @brief Permite mostrar el nombre del perro en lugar del ID en los listados de las estadias.
 *
 * @param perros[] sPerro - El array de perros
 * @param tam int - El tamaño del array
 * @param id int - El idPerro de la estadia
 * @param nombre char* - Donde se pega el nombre del perro al cual corresponde el ID.
 * @return retorno int - -1 si el id de la estadia no coincide con ninguno de los ids de los perros.
 * 		  				  0 si puede copiar el nombre exitosamente.
 */
int perro_copiarNombre(sPerro perros[],int tam, int id,char*nombre);

#endif /* PERROS_H_ */
