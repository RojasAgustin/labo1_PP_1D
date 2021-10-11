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

	aux = perro_elegirPerro();
	estadias[index].idPerro = aux;
	printf("Ingrese la fecha de la reserva: \n");
	estadias[index].fecha.anio = fecha_cargarAnio();
	estadias[index].fecha.mes = fecha_cargarMes();
	estadias[index].fecha.dia = fecha_cargarDia();
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
int estadiaPerro_operarMenuPrincipal(sEstadiaDiaria estadias[], int tamEstadias,sPerro perros[],int tamPerros){
	int retorno =-1;
	int opcionElegida;
	int ultimoID = 100005;
	int cantidadDeReservas =2;
	int idCancelacion;
	if(estadias != NULL && tamEstadias > -1){
	do{
			opcionElegida = getInteger("------------------------\n"
									   "1-Reservar Estadia\n"
									   "2-Modificar Estadia\n"
									   "3-Cancelar Estadia\n"
									   "4-Listar Estadias\n"
									   "5-Listar Perros\n"
									   "6-Promedio de edad de los perros\n"
									   "7-Salir\n"
									   "Elija una opcion: ", "Error. Ingrese una opcion entre 1 y 7", 1, 7);
			switch(opcionElegida){
			case 1:
				if(cantidadDeReservas < tamEstadias){
					if(!estadiaPerro_reservarEstadia(estadias, tamEstadias, ultimoID,perros,tamPerros)){
						ultimoID++;
						cantidadDeReservas++;
					}
					system("pause");
				}
				else{
					printf("No hay mas espacio disponible\n");
				}
				break;
			case 2:
				if(cantidadDeReservas > 0){
					estadiaPerro_subMenuModificar(estadias, tamEstadias, perros, tamPerros);
				}
				else {
					printf("Aun no se ha hecho ninguna reserva.\n");
				}

				break;
			case 3:
				if(cantidadDeReservas > 0){
					estadiaPerro_mostrarEstadias(estadias, tamEstadias,perros,tamPerros);
					idCancelacion = getInteger("Ingrese el ID de la estadia a cancelar: ", "Error. ID no valido. Reintentar", 100000, 100100);
					if(!estadiaPerro_cancelarEstadia(estadias, tamEstadias, idCancelacion,perros,tamPerros)){
						cantidadDeReservas--;
					}
					system("pause");
				}
				else{
					printf("Aun no se ha hecho ninguna reserva.\n");
				}

				break;
			case 4:
				if(cantidadDeReservas > 0){
					estadia_ordenarListadoEstadias(estadias, tamEstadias);
					printf("Mostrando lista: \n");
					estadiaPerro_mostrarEstadias(estadias, tamEstadias,perros,tamPerros);
				}
				else {
					printf("Aun no se ha hecho ninguna reserva.\n");
				}
				break;
			case 5:
				if(cantidadDeReservas > 0){
					perro_mostrarPerros(perros, tamPerros);
					system("pause");
				}
				else{
					printf("Aun no se ha hecho ninguna reserva.\n");
				}
				break;
			case 6:
				if(cantidadDeReservas > 0){
					perro_calcularPromedioDeEdadDeLosPerros(perros, tamPerros);
					system("pause");
				}
				else{
					printf("Aun no se ha hecho ninguna reserva.\n");
				}
				break;
			case 7:
				printf("Saliendo del programa.\n");
				break;
			default:
				printf("Error en el ingreso de la opcion. Reingresar.\n");
				break;
			}
		}while(opcionElegida != 7);
		retorno =0;
	}
	else {
		printf("Error con la lista. Longitud invalida o array vacio");
	}
	return retorno;
}
