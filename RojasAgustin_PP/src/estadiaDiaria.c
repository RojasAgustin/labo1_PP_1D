/*
 * estadiaDiaria.c
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */

#include "estadiaDiaria.h"




int estadia_ordenarListadoEstadias(sEstadiaDiaria estadias[],int tamEstadias){
	int retorno =-1;
	int i;
	int flagSwap;
	int nuevoLimite;
	sEstadiaDiaria auxEstadia;
	nuevoLimite = tamEstadias-1;

	if(estadias != NULL && tamEstadias > -1){
		do{
			flagSwap =0;
			for(i=0;i<tamEstadias;i++){
				if(estadias[i].idPerro != 0 && estadias[i+1].idPerro != 0
						&& estadias[i].fecha.anio > estadias[i+1].fecha.anio){
					auxEstadia = estadias[i];
					estadias[i] = estadias[i+1];
					estadias[i+1] = auxEstadia;
					flagSwap = 1;
				}
				else if (estadias[i].idPerro != 0 && estadias[i+1].idPerro != 0 && estadias[i].fecha.anio == estadias[i+1].fecha.anio){
						if(estadias[i].idPerro != 0 && estadias[i+1].idPerro != 0 && strcmp(estadias[i].nombreDuenio,estadias[i+1].nombreDuenio) == 1){
							auxEstadia = estadias[i];
							estadias[i] = estadias[i+1];
							estadias[i+1] = auxEstadia;
							flagSwap = 1;
						}
					}

			}
			nuevoLimite--;
		}while(flagSwap);
		retorno =0;
	}
	return retorno;
}
int estadia_buscarEstadiaPorId(sEstadiaDiaria estadias[], int tamEstadias, int id){
	int i;
	int index = -1;
	if(estadias != NULL && tamEstadias > -1) {
		for(i=0; i<tamEstadias; i++){
			if(estadias[i].idPerro != 0 && estadias[i].id == id){
				index = i;
				break;
			}
		}
	}
	return index;
}
int estadia_buscarEspacioLibre(sEstadiaDiaria estadias[], int tamEstadias){
	int i;
	int index = -1;
	if(estadias != NULL && tamEstadias > -1){
		for(i=0; i<tamEstadias; i++){
			if(estadias[i].isEmpty == 0){
				index = i;
				break;
			}
		}
	}
	return index;
}
void estadia_inicializar(sEstadiaDiaria estadias[], int tamEstadias){
	int i;
	for(i=0;i<tamEstadias;i++){
		estadias[i].isEmpty = 1;
	}
}


void hardCode(sEstadiaDiaria estadias[], int tamEstadias){
	int i;
	int ids[5] = {100000,100001,100002,100003,100004};
	char nombres[5][31] = {"Jorge","Marta","Lionel","Tusa","Lommbe"};
	char teles[5][11] = {"1234537893","2234565943","1223156783","5446236420","7447274373"};
	int idPerros[5] = {7000,7001,7002,7001,7000};
	int dias[5] = {14,13,6,31,23};
	int meses[5] = {2,5,12,9,10};
	int anios[5] = {2021,2021,2021,2020,2021};
	for(i =0; i< tamEstadias;i++){
		estadias[i].id = ids[i];
		strcpy(estadias[i].nombreDuenio,nombres[i]);
		strcpy(estadias[i].telefonoContacto,teles[i]);
		estadias[i].idPerro = idPerros[i];
		estadias[i].fecha.dia = dias[i];
		estadias[i].fecha.mes = meses[i];
		estadias[i].fecha.anio = anios[i];
		estadias[i].isEmpty = 0;
	}
}


