/*
 * duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Usuario
 */

#include "duenio.h"

int duenio_elegirDuenio(){
	int id;
	int opcion;
	opcion = getInteger("Mostrando lista de duenios: \n"
						"1.Juan\n"
						"2.Lucas\n"
						"3.Rodrigo\n"
						"4.Marcos\n"
						"5.Brian\n"
						"Elija un duenio: ", "Error.Reingresar (Juan = 1 / Lucas = 2 / Rodrigo = 3/ Marcos = 4/ Brian = 5).", 1, 5);
	switch(opcion){
		case 1:
			id = 30000;
			break;
		case 2:
			id = 30001;
			break;
		case 3:
			id = 30002;
			break;
		case 4:
			id = 30003;
			break;
		case 5:
			id = 30004;
			break;
	}
	return id;
}
void duenio_cambiarTelefono(sDuenio* duenio,int telefono){
	(*duenio).telefono = telefono;
}

int duenio_buscarDuenioPorId(sDuenio duenios[],int tam, int id){
	int i;
	int index = -1;
	if(duenios != NULL && tam > -1) {
		for(i=0; i<tam; i++){
			if(duenios[i].id == id){
				index = i;
				break;
			}
		}
	}
	return index;
}
int duenio_copiarNombre(sDuenio duenios[],int tam, int id,char*nombre){
	int retorno =-1;
	int i;
	for(i=0; i<tam;i++)
	{
		if(id == duenios[i].id)
		{
			strcpy(nombre,duenios[i].nombre);
			retorno=0;
			break;
		}
	}
	return retorno;
}
int duenio_copiarTelefono(sDuenio duenios[],int tam, int id,int*telefono){
	int retorno =-1;
	int i;
	for(i=0; i<tam;i++)
	{
		if(id == duenios[i].id)
		{
			*telefono = duenios[i].telefono;
			retorno=0;
			break;
		}
	}
	return retorno;
}
