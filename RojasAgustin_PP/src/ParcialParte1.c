/*
 ============================================================================
 Name        : ParcialParte1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "estadia-perro.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcionElegida;
	int ultimoID = 100005;
	int cantidadDeReservas =4;
	int idCancelacion;
	sPerro perros[TAMPERRROS] = {
			{7000,"Lobo","Sharpei",2},
			{7001,"Sheila","Golden",12},
			{7002,"Reina","Galgo",13}
	};
	sEstadiaDiaria estadias[TAMESTADIAS];
	hardCode(estadias, TAMESTADIAS);
	//estadia_inicializar(estadias, TAMESTADIAS);
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
			if(cantidadDeReservas < TAMESTADIAS){
				if(!estadiaPerro_reservarEstadia(estadias, TAMESTADIAS, ultimoID,perros,TAMPERRROS)){
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
				estadiaPerro_subMenuModificar(estadias, TAMESTADIAS, perros, TAMPERRROS);
			}
			else {
				printf("Aun no se ha hecho ninguna reserva.\n");
			}

			break;
		case 3:
			if(cantidadDeReservas > 0){
				estadiaPerro_mostrarEstadias(estadias, TAMESTADIAS,perros,TAMPERRROS);
				idCancelacion = getInteger("Ingrese el ID de la estadia a cancelar: ", "Error. ID no valido. Reintentar", 100000, 100100);
				if(!estadiaPerro_cancelarEstadia(estadias, TAMESTADIAS, idCancelacion,perros,TAMPERRROS)){
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
				estadiaPerro_mostrarEstadias(estadias, TAMESTADIAS,perros,TAMPERRROS);
			}
			else {
				printf("Aun no se ha hecho ninguna reserva.\n");
			}
			break;
		case 5:
			if(cantidadDeReservas > 0){
				perro_mostrarPerros(perros, TAMPERRROS);
				system("pause");
			}
			else{
				printf("Aun no se ha hecho ninguna reserva.\n");
			}
			break;
		case 6:
			if(cantidadDeReservas > 0){
				perro_calcularPromedioDeEdadDeLosPerros(perros, TAMPERRROS);
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
	return 0;
}
