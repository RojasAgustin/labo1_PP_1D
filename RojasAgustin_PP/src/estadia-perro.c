/*
 * estadia-perro.c
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */

#include "estadia-perro.h"

int estadiaPerro_subMenuModificar(sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[], int tamPerros){
	int retorno = -1;
	int index;
	int idIngresado;
	int opcion;
	sEstadiaDiaria auxEstadia;
	if(estadias != NULL && tamEstadias > -1){
		estadiaPerro_mostrarEstadias(estadias, tamEstadias,perros,tamPerros);
		idIngresado = getInteger("Ingrese el ID de la estadia a modificar (100000-100100): ", "Reingrese el ID de la estadia a modificar (100000-100100): ", 100000, 100100);
		index = estadia_buscarEstadiaPorId(estadias, tamEstadias, idIngresado);
		if(index != -1) //Existe el producto?
		{
			printf("\nEstadia a modificar:\n"
					"%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
			estadiaPerro_mostrarEstadia(estadias[index],perros,tamPerros);
			do
			{
				auxEstadia = estadias[index];
				opcion = getInteger("-------------------------------------\n"
									 "1. Modificar telefono\n"
									 "2. Modificar perro\n"
									 "3. Volver\n"
									 "-------------------------------------\n"
									 "Ingrese una opcion: ",
									 "-------------------------------------\n"
									 "1. Modificar telefono\n"
									 "2. Modificar perro\n"
									 "3. Volver\n"
									 "-------------------------------------\n"
									 "Opcion invalida, reingrese: ", 1, 3);
				switch(opcion){
					case 1:
						printf("Estadia a modificar: \n"
								"%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
						estadiaPerro_mostrarEstadia(estadias[index],perros,tamPerros);
						getString(auxEstadia.telefonoContacto, "Ingrese el telefono del dueño: ", "Error. Reingresar telefono (max 10 digitos): ",10);
						while(!esNumerico(auxEstadia.telefonoContacto, TAMTELEFONO) || strlen(auxEstadia.telefonoContacto) < 8){
							printf("Error. Ingresar solo digitos. El telefono debe tener entre 8 y 10 digitos \n");
							getString(auxEstadia.telefonoContacto, "Reingrese el telefono del dueño: ", "Error. Reingresar telefono (max 10 digitos): ",10);
						}
						printf("Estadia luego de la modificacion: \n"
								"%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
						estadiaPerro_mostrarEstadia(auxEstadia,perros,tamPerros);
						if(!verificarConfirmacion("Modificar Telefono? S para confirmar, N para cancelar: ")){
							strcpy(estadias[index].telefonoContacto,auxEstadia.telefonoContacto);
							printf("Telefono de %s modificado correctamente\n",estadias[index].nombreDuenio);
						}
						else{
							printf("Se cancelo la modificacion del telefono\n");
						}
						system("pause");
						break;
					case 2:
						printf("Estadia a modificar: \n"
							   "%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
						estadiaPerro_mostrarEstadia(estadias[index],perros,tamPerros);
						auxEstadia.idPerro = perro_elegirPerro();
						printf("Estadia luego de la modificacion: \n"
							   "%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
						estadiaPerro_mostrarEstadia(auxEstadia,perros,tamPerros);
						if(!verificarConfirmacion("Modificar Perro? S para confirmar, N para cancelar: ")){
							estadias[index].idPerro = auxEstadia.idPerro;
							printf("Estadia reservada con exito para %s.\n",estadias[index].nombreDuenio);
						}
						else{
							printf("Se cancelo la modificacion del perro.\n");
						}
						system("pause");
						break;
					case 3:
						break;
					default:
						printf("Error en el ingreso de la opcion. Reingresar.\n");
						break;
				}
			}while(opcion!=3);
		}
		else {
			printf("Error, estadia no encontrada\n");
		}
		retorno =0;
	}
	return retorno;
}
int estadiaPerro_mostrarEstadias (sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[],int tamPerros){
	int retorno =-1;
	int i;
	if(estadias != NULL && tamEstadias > -1){
		printf("%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
		for(i=0;i<tamEstadias;i++){
			if(estadias[i].isEmpty == 0){
				estadiaPerro_mostrarEstadia(estadias[i],perros,tamPerros);
			}
		}
		retorno =0;
	}
	return retorno;
}

void estadiaPerro_mostrarEstadia (sEstadiaDiaria estadia,sPerro perros[],int tam){
	char auxNombre[TAMDUENIO];
	perro_copiarNombre(perros, tam, estadia.idPerro, auxNombre);
	printf("%-10d %-20s %-20s %-15s %-1d/%-1d/%-1d\n",estadia.id,estadia.nombreDuenio,
										 estadia.telefonoContacto,auxNombre,
										 estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio);
}
int estadiaPerro_cancelarEstadia(sEstadiaDiaria estadias[], int tamEstadias, int id,sPerro perros[],int tamPerros){
	int retorno =-1;;
	int index;
	if(estadias != NULL && tamEstadias > -1){
		index = estadia_buscarEstadiaPorId(estadias, tamEstadias, id);
		if(index != -1){
			printf("\nEstadia a eliminar:\n"
					"%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
			estadiaPerro_mostrarEstadia(estadias[index],perros,tamPerros);
			if(!verificarConfirmacion("Ingrese s para confirmar la cancelacion: ")){
				estadias[index].isEmpty = 1;
				printf("Estadia cancelada. Regresando al menu\n");
				retorno =0;
			}
			else {
				printf("Se cancelo la cancelacion de la estadia.\n");
			}
		}
		else {
			printf("Error. Estadia no encontrada\n");
		}
	}
	return retorno;
}
int estadiaPerro_cargarEstadia(sEstadiaDiaria estadias[],int index, int id,sPerro perros[],int tamPerros){
	int retorno =-1;
	int aux;
	estadias[index].id = id;

	getString(estadias[index].nombreDuenio, "Ingrese el nombre del dueño: ", "Error. Reingrese el nombre del dueño (max 35 caracteres)", 35);
	while(!esNombreValido(estadias[index].nombreDuenio, TAMDUENIO)){
		printf("Error. Caracteres no validos en el ingreso del nombre. Reintentar\n");
		getString(estadias[index].nombreDuenio, "Ingrese el nombre del dueño: ", "Error. Reingrese el nombre del dueño (max 35 caracteres)", 35);
	}

	getString(estadias[index].telefonoContacto, "Ingrese el telefono del dueño: ", "Error. Reingresar telefono (max 10 digitos): ",10);
	while(!esNumerico(estadias[index].telefonoContacto, TAMTELEFONO) || strlen(estadias[index].telefonoContacto) < 8){
		printf("Error. Ingresar solo digitos. El telefono debe tener entre 8 y 10 digitos \n");
		getString(estadias[index].telefonoContacto, "Reingrese el telefono del dueño: ", "Error. Reingresar telefono (max 10 digitos): ",10);
	}

	//estadias[index].idPerro = getInteger("Ingrese el ID del perro: ", "Error. Reingrese id.", 7000, 7002);
	aux = perro_elegirPerro();
	estadias[index].idPerro = aux;
	printf("Ingrese la fecha de la reserva: \n");
	estadias[index].fecha.anio = getInteger("Año: ", "Error. Reingrese el año", 2021, 2023);
	estadias[index].fecha.mes = getInteger("Mes: ", "Error. Reingrese el mes", 1, 12);
	estadias[index].fecha.dia = getInteger("Dia: ", "Error. Reingrese el año", 1, 31);
	printf("\nEstadia a reservar:\n"
						"%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
	estadiaPerro_mostrarEstadia(estadias[index],perros,tamPerros);
	if(!verificarConfirmacion("\nIngrese S para confirmar la reserva: "))
	{
		estadias[index].isEmpty = 0;
		retorno = 0;
	}
	return retorno;
}
int estadiaPerro_reservarEstadia(sEstadiaDiaria estadias[],int tamEstadias, int ultimoID,sPerro perros[],int tamPerros){
	int retorno =-1;
	int index;
	if(estadias != NULL && tamEstadias > -1){
		index = estadia_buscarEspacioLibre(estadias, tamEstadias);
		if(index !=-1){
			if(!estadiaPerro_cargarEstadia(estadias, index, ultimoID,perros,tamPerros)){
				printf("Se cargo la reserva exitosamente.\n");
				retorno =0;
			}
			else{
				printf("Se cancelo la reserva.\n");
			}
		}
	}
	return retorno;
}
