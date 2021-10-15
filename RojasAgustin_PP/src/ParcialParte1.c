/*
Para esta instancia del parcial, deberá agregar la siguiente estructura y relacionarla de
manera adecuada con la/s estructura/s de la parte 1. Eliminando de las anteriores los
campos que sobren.
Duenio:
 id (comienza en 30000)
 nombre(máximo 41 caracteres)
telefono (int)
Hardcodear por lo menos 5 dueños.
Nota importante: Deberá impactar este cambio en las funcionalidades solicitadas en la
parte 1. Recordar que al dar de alta una estadía, se deberá verificar que el dueño ingresado
exista.
Agregar los siguientes informes:
7. El perro que tiene más estadías reservadas.
8. Listado de perros con sus estadías diarias reservadas.
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "duenio.h"
#include "estadia-perro-duenio.h"
#include "estadia-perro.h"
#include "estadia-duenio.h"


int main(void) {
	setbuf(stdout,NULL);
	sPerro perros[3] = {
			{7000,"Lobo","Sharpei",2},
			{7001,"Sheila","Golden",12},
			{7002,"Reina","Galgo",13}
	};
	sDuenio duenios[5] ={
			{30000,"Juan",1255924334},
			{30001,"Lucas",1544442233},
			{30002,"Rodrigo",1242442288},
			{30003,"Marcos",129441112},
			{30004,"Brian",1499338118},
	};
	sEstadiaDiaria estadias[TAMESTADIAS];
	estadia_inicializar(estadias, TAMESTADIAS);
	estadiaPerroDuenio_operarMenuPrincipal(estadias, TAMESTADIAS,perros, TAMPERRROS,duenios,5);
	return 0;
}
