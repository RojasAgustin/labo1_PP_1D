/*
 * perros.c
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */

#include "perros.h"
/*
void hardCodearPerros(sPerro perros[], int tamPerros){
	int i;
	int ids[3] = {7000,7001,7002};
	char nombres[3][TAMNOMBRE] = {"Lobo","Sheila","Reina"};
	char razas[3][TAMRAZA] = {"Sharpei","Golden","Galgo"};
	int edades[3] = {2,12,13};
	for(i =0;i < tamPerros;i++){
		perros[i].id = ids[i];
		strcpy(perros[i].nombre,nombres[i]);
		strcpy(perros[i].raza,razas[i]);
		perros[i].edad = edades[i];
	}
}*/
int perro_mostrarPerros(sPerro perros[], int tamPerros){
	int retorno =-1;
	int i;
	if(perros != NULL && tamPerros > -1){
		printf("Mostrando lista de perros: \n"
				"%-5s %-20s %-20s %-10s\n", "ID", "Nombre","Raza","Edad");
		for(i=0;i<tamPerros;i++){
			perro_mostrarPerro(perros[i]);
		}
		retorno =0;
	}
	return retorno;
}
void perro_mostrarPerro(sPerro perro){
	printf("%-5d %-20s %-20s %-10d\n", perro.id, perro.nombre, perro.raza, perro.edad);
}
int perro_calcularPromedioDeEdadDeLosPerros(sPerro perros[],int tamPerros){
	int retorno =-1;
	float promedio;
	int contadorPerros=0;
	int sumaEdades =0;
	int i;
	if(perros != NULL && tamPerros > -1){
		for(i=0;i<tamPerros;i++){
			contadorPerros++;
			sumaEdades += perros[i].edad;
		}
		promedio = sumaEdades / (float)contadorPerros;
		printf("Promedio de edad de los perros: %.2f\n",promedio);
	}
	return retorno;
}
int perro_elegirPerro(){
	int id;
	int opcion;
	opcion = getInteger("Elija un perro: \n"
						"1.Lobo\n"
						"2.Sheila\n"
						"3.Reina\n", "Error.Reingresar.\n", 1, 3);
	switch(opcion){
		case 1:
			id = 7000;
			break;
		case 2:
			id = 7001;
			break;
		case 3:
			id = 7002;
			break;
	}
	return id;
}
int perro_copiarNombre(sPerro perros[],int tam, int id,char*nombre){
	int retorno =-1;
	int i;
	for(i=0; i<tam;i++)
	{
		if(id == perros[i].id)
		{
			strcpy(nombre,perros[i].nombre);
			retorno=0;
			break;
		}
	}
	return retorno;
}
