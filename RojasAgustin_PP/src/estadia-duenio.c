/*
 * estadia.duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Usuario
 */

#include "estadia-duenio.h"
int estadiaDuenio_ordenarListadoEstadias(sEstadiaDiaria estadias[],int tamEstadias,sDuenio duenios[], int tamDuenios){
	int retorno =-1;
	int i;
	int flagSwap;
	int nuevoLimite;
	int idNombreUno;
	int idNombreDos;
	char nombreUno[20];
	char nombreDos[20];
	sEstadiaDiaria auxEstadia;
	nuevoLimite = tamEstadias-1;

	if((estadias != NULL && tamEstadias > -1)|| (estadias != NULL && tamDuenios > -1)){
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
							}
							else {
								if(estadias[i].isEmpty != 1 && estadias[i+1].isEmpty != 1 && estadias[i].fecha.anio == estadias[i+1].fecha.anio
								   && estadias[i].fecha.mes == estadias[i+1].fecha.mes && estadias[i].fecha.dia == estadias[i+1].fecha.dia){

									idNombreUno = estadias[i].idDuenio;
									idNombreDos = estadias[i+1].idDuenio;
									duenio_copiarNombre(duenios, tamDuenios, idNombreUno, nombreUno);
									duenio_copiarNombre(duenios, tamDuenios, idNombreDos, nombreDos);
									if(estadias[i].isEmpty != 1 && estadias[i+1].isEmpty != 1 && strcmp(nombreUno,nombreDos) == 1){
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
			nuevoLimite--;
		}while(flagSwap);
		retorno =0;
	}
	return retorno;
}
