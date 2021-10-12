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
				if(estadias[i].isEmpty != 1 && estadias[i+1].isEmpty != 1 && estadias[i].fecha.anio < estadias[i+1].fecha.anio){
					auxEstadia = estadias[i];
					estadias[i] = estadias[i+1];
					estadias[i+1] = auxEstadia;
					flagSwap = 1;
				}
				else {
					if(estadias[i].isEmpty != 1 && estadias[i+1].isEmpty != 1 && estadias[i].fecha.anio == estadias[i+1].fecha.anio)
					{
						if(estadias[i].isEmpty != 1 && estadias[i+1].isEmpty != 1 && estadias[i].fecha.mes < estadias[i+1].fecha.mes)
						{
							auxEstadia = estadias[i];
							estadias[i] = estadias[i+1];
							estadias[i+1] = auxEstadia;
							flagSwap = 1;
						}
						else
						{
							if(estadias[i].isEmpty != 1 && estadias[i+1].isEmpty != 1 && estadias[i].fecha.anio == estadias[i+1].fecha.anio
								&& estadias[i].fecha.mes == estadias[i+1].fecha.mes)
							{
								if(estadias[i].isEmpty != 1 && estadias[i+1].isEmpty != 1 && estadias[i].fecha.dia < estadias[i+1].fecha.dia)
								{
									auxEstadia = estadias[i];
									estadias[i] = estadias[i+1];
									estadias[i+1] = auxEstadia;
									flagSwap = 1;
								}
								else
								{
									if(estadias[i].isEmpty != 1 && estadias[i+1].isEmpty != 1 && estadias[i].fecha.anio == estadias[i+1].fecha.anio
										&& estadias[i].fecha.mes == estadias[i+1].fecha.mes && estadias[i].fecha.dia == estadias[i+1].fecha.dia)
									{
										if((estadias[i].isEmpty != 1 && estadias[i+1].isEmpty != 1) && strcmp(estadias[i].nombreDuenio,estadias[i+1].nombreDuenio) == 1)
										{
											auxEstadia = estadias[i];
											estadias[i] = estadias[i+1];
											estadias[i+1] = auxEstadia;
											flagSwap = 1;
										}
									}
								}
							}
						}
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





