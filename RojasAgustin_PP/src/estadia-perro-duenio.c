/*
 * estadia-perro.c
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */

#include "estadia-perro-duenio.h"

int estadiaPerroDuenio_operarSubMenuModificar(sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[], int tamPerros,sDuenio duenios[],int tamDuenios){
	int retorno = -1;
	int index;
	int idIngresado;
	int idTelefono;
	int telNuevo;
	int indexTelefono;
	int opcion;
	sEstadiaDiaria auxEstadia;
	if((estadias != NULL && tamEstadias > -1)|| (perros != NULL && tamPerros > -1)|| (estadias != NULL && tamDuenios > -1)){
		estadiaPerroDuenio_mostrarEstadias(estadias, tamEstadias,perros,tamPerros,duenios,tamDuenios);
		idIngresado = getInteger("Ingrese el ID de la estadia a modificar (100000-100099): ", "Reingrese el ID de la estadia a modificar (100000-100099): ", 100000, 100099);
		index = estadia_buscarEstadiaPorId(estadias, tamEstadias, idIngresado);
		if(index != -1) //Existe el producto?
		{
			printf("\nEstadia a modificar:\n"
					"%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
			estadiaPerroDuenio_mostrarEstadia(estadias[index],perros,tamPerros,duenios,tamDuenios);
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
						estadiaPerroDuenio_mostrarEstadia(estadias[index],perros,tamPerros,duenios,tamDuenios);
						idTelefono = estadias[index].idDuenio;
						indexTelefono = duenio_buscarDuenioPorId(duenios, tamDuenios, idTelefono);
						telNuevo = getInteger("Telefono nuevo: ", "Error.Reingresar (8 a 10 digitos)", 10000000, 1000000000);
						duenio_cambiarTelefono(&duenios[indexTelefono],telNuevo);
						printf("Telefono modificado con exito!\n");
						system("pause");
						break;
					case 2:
						printf("Estadia a modificar: \n"
							   "%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
						estadiaPerroDuenio_mostrarEstadia(estadias[index],perros,tamPerros,duenios,tamDuenios);
						auxEstadia.idPerro = perro_elegirPerro();
						printf("Estadia luego de la modificacion: \n"
							   "%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
						estadiaPerroDuenio_mostrarEstadia(auxEstadia,perros,tamPerros,duenios,tamDuenios);
						if(!verificarConfirmacion("Modificar Perro? S para confirmar, N para cancelar: ")){
							estadias[index].idPerro = auxEstadia.idPerro;
							printf("Estadia modificada con exito\n");
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
			printf("Error. estadia no encontrada\n");
			system("pause");
		}
		retorno =0;
	}
	return retorno;
}
int estadiaPerroDuenio_cancelarEstadia(sEstadiaDiaria estadias[], int tamEstadias, int id,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios){
	int retorno =-1;;
	int index;
	if((estadias != NULL && tamEstadias > -1)|| (perros != NULL && tamPerros > -1)|| (estadias != NULL && tamDuenios > -1)){
		index = estadia_buscarEstadiaPorId(estadias, tamEstadias, id);
		if(index != -1){
			printf("\nEstadia a eliminar:\n"
					"%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
			estadiaPerroDuenio_mostrarEstadia(estadias[index],perros,tamPerros,duenios,tamDuenios);
			if(!verificarConfirmacion("Ingrese S para confirmar la cancelacion - N para regresar: ")){
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
int estadiaPerroDuenio_cargarEstadia(sEstadiaDiaria estadias[],int index, int id,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios){
	int retorno =-1;
	int auxPerro;
	int auxNombre;
	estadias[index].id = id;
	auxNombre = duenio_elegirDuenio();
	estadias[index].idDuenio = auxNombre;
	auxPerro = perro_elegirPerro();
	estadias[index].idPerro = auxPerro;
	printf("Ingrese la fecha de la reserva: \n");
	estadias[index].fecha.anio = fecha_cargarAnio();
	estadias[index].fecha.mes = fecha_cargarMes();
	estadias[index].fecha.dia = fecha_cargarDia();
	printf("\nEstadia a reservar:\n"
						"%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
	estadiaPerroDuenio_mostrarEstadia(estadias[index],perros,tamPerros,duenios,tamDuenios);
	if(!verificarConfirmacion("\nIngrese S para confirmar la reserva - N para cancelar: "))
	{
		estadias[index].isEmpty = 0;
		retorno = 0;
	}
	return retorno;
}
int estadiaPerroDuenio_reservarEstadia(sEstadiaDiaria estadias[],int tamEstadias, int id,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios){
	int retorno =-1;
	int index;
	if((estadias != NULL && tamEstadias > -1)|| (perros != NULL && tamPerros > -1) || (estadias != NULL && tamDuenios > -1)){
		index = estadia_buscarEspacioLibre(estadias, tamEstadias);
		if(index !=-1){
			if(!estadiaPerroDuenio_cargarEstadia(estadias, index, id,perros,tamPerros,duenios,tamDuenios)){
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
int estadiaPerroDuenio_operarMenuPrincipal(sEstadiaDiaria estadias[], int tamEstadias,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios){
	int retorno =-1;
	int opcionElegida;
	int ultimoID = 100000;
	int cantidadDeReservas =0;
	int idCancelacion;
	if((estadias != NULL && tamEstadias > -1)|| (perros != NULL && tamPerros > -1)|| (estadias != NULL && tamDuenios > -1)){
		do{
				opcionElegida = getInteger("------------------------\n"
										   "1-Reservar Estadia\n"
										   "2-Modificar Estadia\n"
										   "3-Cancelar Estadia\n"
										   "4-Listar Estadias\n"
										   "5-Listar Perros\n"
										   "6-Promedio de edad de los perros\n"
										   "7-Sacar perro con mas estadias\n"
										   "8-Listado de perros con sus estadias\n"
										   "9-Salir\n"
										   "Elija una opcion: ", "Error. Ingrese una opcion entre 1 y 9", 1, 9);
				switch(opcionElegida){
				case 1:
					if(cantidadDeReservas < tamEstadias){
						if(!estadiaPerroDuenio_reservarEstadia(estadias, tamEstadias, ultimoID,perros,tamPerros,duenios,tamDuenios)){
							ultimoID++;
							cantidadDeReservas++;
						}
					}
					else{
						printf("No hay mas espacio disponible\n");
					}
					system("pause");
					break;
				case 2:
					if(cantidadDeReservas > 0){
						estadiaPerroDuenio_operarSubMenuModificar(estadias, tamEstadias, perros, tamPerros,duenios,tamDuenios);
					}
					else {
						printf("Aun no se ha hecho ninguna reserva.\n");
						system("pause");
					}
					break;
				case 3:
					if(cantidadDeReservas > 0){
						estadiaPerroDuenio_mostrarEstadias(estadias, tamEstadias,perros,tamPerros,duenios,tamDuenios);
						idCancelacion = getInteger("Ingrese el ID de la estadia a cancelar: ", "Error. ID no valido. Reintentar (de 100000 a 100099)", 100000, 100099);
						if(!estadiaPerroDuenio_cancelarEstadia(estadias, tamEstadias, idCancelacion,perros,tamPerros,duenios,tamDuenios)){
							cantidadDeReservas--;
						}
					}
					else{
						printf("Aun no se ha hecho ninguna reserva.\n");
					}
					system("pause");
					break;
				case 4:
					if(cantidadDeReservas > 0){
						estadiaDuenio_ordenarListadoEstadias(estadias, tamEstadias,duenios,tamDuenios);
						printf("Mostrando lista: \n");
						estadiaPerroDuenio_mostrarEstadias(estadias, tamEstadias,perros,tamPerros,duenios,tamDuenios);
					}
					else {
						printf("Aun no se ha hecho ninguna reserva.\n");
					}
					system("pause");
					break;
				case 5:
					if(cantidadDeReservas > 0){
						perro_mostrarPerros(perros, tamPerros);
					}
					else{
						printf("Aun no se ha hecho ninguna reserva.\n");
					}
					system("pause");
					break;
				case 6:
					if(cantidadDeReservas > 0){
						perro_calcularPromedioDeEdadDeLosPerros(perros, tamPerros);
					}
					else{
						printf("Aun no se ha hecho ninguna reserva.\n");
					}
					system("pause");
					break;
				case 7:
					if(cantidadDeReservas > 0){
						estadiaPerro_sacarPerroConMasEstadias(estadias, tamEstadias, perros, tamPerros);
					}
					else {
						printf("Aun no se ha hecho ninguna reserva.\n");
					}
					system("pause");
					break;
				case 8:
					if(cantidadDeReservas > 0){
						estadiaPerroDuenio_listarPerrosConEstadias(estadias, tamEstadias, perros, tamPerros, duenios, tamDuenios);
					}
					else {
						printf("Aun no se ha hecho ninguna reserva.\n");
					}
					system("pause");
					break;
				case 9:
					printf("Saliendo del programa.\n");
					break;
				default:
					printf("Error en el ingreso de la opcion. Reingresar.\n");
					break;
				}
			}while(opcionElegida != 9);
			retorno =0;
		}
	else {
		printf("Error con la lista. Longitud invalida o array vacio");
	}
	return retorno;
}

int estadiaPerroDuenio_mostrarEstadias (sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios){
	int retorno =-1;
	int i;
	if((estadias != NULL && tamEstadias > -1)|| (perros != NULL && tamPerros > -1) || (duenios != NULL && tamPerros > -1)){
		printf("%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
		for(i=0;i<tamEstadias;i++){
			if(estadias[i].isEmpty == 0){
				estadiaPerroDuenio_mostrarEstadia(estadias[i],perros,tamPerros,duenios,tamDuenios);
			}
		}
		retorno =0;
	}
	return retorno;
}

void estadiaPerroDuenio_mostrarEstadia (sEstadiaDiaria estadia,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios){
	char auxNombrePerro[20];
	char auxNombreDuenio[20];
	int auxTelefono;
	perro_copiarNombre(perros, tamPerros, estadia.idPerro, auxNombrePerro);
	duenio_copiarNombre(duenios, tamDuenios, estadia.idDuenio, auxNombreDuenio);
	duenio_copiarTelefono(duenios, tamDuenios, estadia.idDuenio, &auxTelefono);
	printf("%-10d %-20s %-20d %-15s %-1d/%-1d/%-1d\n",estadia.id,auxNombreDuenio,
										 auxTelefono,auxNombrePerro,
										 estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio);
}


void estadiaPerroDuenio_listarPerrosConEstadias(sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios){
	for(int i=0;i<tamPerros;i++)
	{
		printf("%s:\n",perros[i].nombre);
		printf("%-10s %-20s %-20s %-15s %-30s\n", "ID", "Dueño", "Telefono","Mascota","Fecha");
		for(int j=0; j<tamEstadias;j++)
		{
			if((estadias[j].isEmpty==0) && (perros[i].id == estadias[j].idPerro))
			{
				estadiaPerroDuenio_mostrarEstadia(estadias[j], perros, tamPerros, duenios, tamDuenios);
			}
		}
		printf("--------------------------------------\n");

	}
}

