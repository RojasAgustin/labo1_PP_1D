/*
 * estadiaDiaria.c
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */

#include "estadiaDiaria.h"





int estadia_buscarEstadiaPorId(sEstadiaDiaria estadias[], int tamEstadias, int id){
	int i;
	int index = -1;
	if(estadias != NULL && tamEstadias > -1) {
		for(i=0; i<tamEstadias; i++){
			if(estadias[i].isEmpty == 0 && estadias[i].id == id){
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
			if(estadias[i].isEmpty == 1){
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





