/*
 * estadia-perro.h
 *
 *  Created on: 7 oct. 2021
 *      Author: Usuario
 */

#ifndef ESTADIA_PERRO_DUENIO_H_
#define ESTADIA_PERRO_DUENIO_H_
#include "perros.h"
#include "estadiaDiaria.h"
#include "funciones.h"
#include "estadia-duenio.h"
#include "estadia-perro.h"
#include "fecha.h"
#include "duenio.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @fn int estadiaPerro_operarSubMenuModificar(sEstadiaDiaria[], int, sPerro[], int)
 * @brief Muestra y permite al usuario operar el sub menu para las modificaciones
 *
 * @param estadias[] sEstadiaDiaria - El array de estadias.
 * @param tamEstadias int - La longitud del array de estadias.
 * @param perros[] sPerro - El array de perros.
 * @param tamPerros int - La longitud del array de perros.
 * @return retorno int - -1 si hay un error (arrays NULL o longitudes invalidas). 0 si puede ingresar al primer if.
 */
int estadiaPerroDuenio_operarSubMenuModificar(sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[], int tamPerros,sDuenio duenios[],int tamDuenios);

/**
 * @fn int estadiaPerro_cancelarEstadia(sEstadiaDiaria[], int, int, sPerro[], int)
 * @brief Cancela una estadia por ID, asignando el valor 1 a la bandera isEmpty de la misma.
 *
 * @param estadias[] sEstadiaDiaria - El array de estadias.
 * @param tamEstadias int - La longitud del array de estadias.
 * @param id int - El id de la estadia a cancelar.
 * @param perros[] sPerro - El array de perros.
 * @param tamPerros int - La longitud del array de perros.
 * @return retorno int - 0 si se confirma la cancelacion. -1 si hay un error, no se encuentra el ID o se cancela la cancelacion.
 */
int estadiaPerroDuenio_cancelarEstadia(sEstadiaDiaria estadias[], int tamEstadias, int id,sPerro perros[],int tamPerros, sDuenio duenios[],int tamDuenios);
/**
 * @fn int estadiaPerro_reservarEstadia(sEstadiaDiaria[], int, int, sPerro[], int)
 * @brief Permite al usuario reservar una estadia
 *
 * @param estadias[] sEstadiaDiaria - El array de estadias.
 * @param tamEstadias int - La longitud del array de estadias.
 * @param id int - El ID de la reserva.
 * @param perros[] sPerro - El array de perros.
 * @param tamPerros int - La longitud del array de perros.
 * @return retorno int - 0 si se puede hacer la reserva exitosamente.
 * 						 -1 si hay un error, no encuentra espacio libre o se cancela la reserva.
 */
int estadiaPerroDuenio_reservarEstadia(sEstadiaDiaria estadias[],int tamEstadias, int id,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios);
/**
 * @fn int estadiaPerro_cargarEstadia(sEstadiaDiaria[], int, int, sPerro[], int)
 * @brief Permite al usuario ingresar uno por uno los datos de la reserva.
 *
 * @param estadias[] sEstadiaDiaria - El array de estadias.
 * @param index int - La posicion de la reserva en el array.
 * @param id int - El ID de la reserva.
 * @param perros[] sPerro - El array de perros.
 * @param tamPerros int - La longitud del array de perros.
 * @return retorno int - 0 si se confirma la reserva. -1 si se cancela la reserva.
 */
int estadiaPerroDuenio_cargarEstadia(sEstadiaDiaria estadias[],int index, int id,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios);
/**
 * @fn int estadiaPerro_operarMenuPrincipal(sEstadiaDiaria[], int, sPerro[], int)
 * @brief Muestra y permite al usuario operar el menu principal
 *
 * @param estadias[] sEstadiaDiaria - El array de estadias.
 * @param tamEstadias int - La longitud del array de estadias.
 * @param perros[] sPerro - El array de perros.
 * @param tamPerros int - La longitud del array de perros.
 * @return retorno int - -1 si hay un error (arrays NULL o longitudes invalidas). 0 si puede ingresar al primer if.
 */
int estadiaPerroDuenio_operarMenuPrincipal(sEstadiaDiaria estadias[], int tamEstadias,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios);
/**
 * @fn int estadiaPerro_mostrarEstadias(sEstadiaDiaria[], int, sPerro[], int)
 * @brief Muestra el listado de las estadias
 *
 * @param estadias[] sEstadiaDiaria - El array de estadias.
 * @param tamEstadias int - La longitud del array de estadias.
 * @param perros[] sPerro - El array de perros.
 * @param tamPerros int - La longitud del array de perros.
 * @return retorno int - -1 si hay un error (arrays NULL o longitudes invalidas). 0 si puede ingresar al primer if.
 */
int estadiaPerroDuenio_mostrarEstadias (sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios);
/**
 * @fn void estadiaPerro_mostrarEstadia(sEstadiaDiaria, sPerro[], int)
 * @brief Muestra una sola estadia
 *
 * @param estadia sEstadiaDiaria - La estadia a mostrar
 * @param perros[] sPerro - El array de perros.
 * @param tamPerros int - La longitud del array de perros
 */
void estadiaPerroDuenio_mostrarEstadia (sEstadiaDiaria estadia,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios);

void estadiaPerroDuenio_listarPerrosConEstadias(sEstadiaDiaria estadias[],int tamEstadias,sPerro perros[],int tamPerros,sDuenio duenios[],int tamDuenios);



#endif /* ESTADIA_PERRO_DUENIO_H_ */
