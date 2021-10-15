/*
 * estadia-perro.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Usuario
 */

#include "estadia-perro.h"
int estadiaPerro_sacarPerroConMasEstadias(sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[],int tamPerros){
	int retorno =-1;
	int contadorLobo = 0;
	int contadorSheila = 0;
	int contadorReina = 0;
	if((estadias != NULL && tamEstadias > -1)|| (perros != NULL && tamPerros > -1)){
		for(int i = 0;i < tamEstadias; i++){
			if(estadias[i].isEmpty == 0 && estadias[i].idPerro == 7000){
				contadorLobo++;
			}
			else if (estadias[i].isEmpty == 0 && estadias[i].idPerro == 7001){
				contadorSheila++;
			}
			else if (estadias[i].isEmpty == 0 && estadias[i].idPerro == 7002){
				contadorReina++;
			}
		}
		if(contadorLobo > contadorSheila && contadorLobo > contadorReina){
			printf("Lobo tiene mas estadias (%d) que Sheila (%d) y Reina (%d).\n",contadorLobo,contadorSheila,contadorReina);
		}
		else if (contadorSheila > contadorLobo && contadorSheila > contadorReina){
			printf("Sheila tiene mas estadias (%d) que Lobo (%d) y Reina (%d).\n", contadorSheila,contadorLobo,contadorReina);
		}
		else if (contadorReina > contadorLobo && contadorReina > contadorSheila){
			printf("Reina tiene mas estadias. (%d) que Sheila (%d) y Lobo (%d)\n",contadorReina,contadorSheila,contadorLobo);
		}
		else {
			printf("Hay una igualdad en la cantidad de estadias.\n");
		}
		retorno =0;
	}
	return retorno;
}
