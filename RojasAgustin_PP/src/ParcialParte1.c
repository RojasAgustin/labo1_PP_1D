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
	sPerro perros[TAMPERRROS] = {
			{7000,"Lobo","Sharpei",2},
			{7001,"Sheila","Golden",12},
			{7002,"Reina","Galgo",13}
	};
	sEstadiaDiaria estadias[TAMESTADIAS];
	estadia_inicializar(estadias, TAMESTADIAS);
	estadiaPerro_operarMenuPrincipal(estadias, TAMESTADIAS,perros, TAMPERRROS);
	return 0;
}
