/*
 * estadia-perro.h
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */

#ifndef ESTADIA_PERRO_H_
#define ESTADIA_PERRO_H_
#include "perros.h"
#include "estadiaDiaria.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int estadiaPerro_subMenuModificar(sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[], int tamPerros);
int estadiaPerro_mostrarEstadias (sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[],int tamPerros);
void estadiaPerro_mostrarEstadia (sEstadiaDiaria estadia,sPerro perros[],int tam);
int estadiaPerro_cancelarEstadia(sEstadiaDiaria estadias[], int tamEstadias, int id,sPerro perros[],int tamPerros);
int estadiaPerro_reservarEstadia(sEstadiaDiaria estadias[],int tamEstadias, int ultimoID,sPerro perros[],int tamPerros);
int estadiaPerro_cargarEstadia(sEstadiaDiaria estadias[],int index, int id,sPerro perros[],int tamPerros);


#endif /* ESTADIA_PERRO_H_ */
