/*
 * funciones.h
 *
 *  Created on: 3 sep. 2021
 *      Author: Usuario
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * @fn int getInteger(char*, char*, int, int)
 * @brief Pide un entero en un rango
 *
 * @param mensaje char* - Mensaje que informa al usuario sobre lo que se esta pidiendo
 * @param mensajeError char* - Mensaje de error que se muestra si el usuario ingresa un numero fuera del rango o algo que no sea un numero
 * @param minimo int - El numero mas bajo del rango
 * @param maximo int - El numero mas alto del rango
 * @return numero int - El entero ingresado por el usuario
 */
int getInteger (char* mensaje, char* mensajeError, int minimo,int maximo);
/**
 * @fn void getString(char*, char*, char*, int)
 * @brief Pide una cadena/array de caracteres.
 *
 * @param cadena char* - Donde se guarda la cadena
 * @param mensaje char* - Mensaje que informa al usuario sobre lo que se esta pidiendo
 * @param mensajeError char* - Mensaje de error que se muestra si el usuario se pasa del limite de caracteres
 * @param max int - El limite de caracteres
 */
void getString(char* cadena, char* mensaje, char* mensajeError, int max);
/**
 * @fn int responderSiONo(char*, char*)
 * @brief Pide uno de dos caracteres. S/s = si --  N/n = no
 *
 * @param caracter char* - Donde se guarda el caracter
 * @param mensaje char* - Mensaje que informa al usuario sobre lo que se esta pidiendo
 * @return retorno int - -1(Error) si ambos parametros son NULL. 0 si el caracter se puede ingresar correctamente.
 */
int responderSiONo(char* caracter, char*mensaje);
/**
 * @fn int verificarConfirmacion(char*)
 * @brief Verifica que el usuario quiera proceder con la reserva/cancelacion/modificacion
 *
 * @param mensaje char* - Mensaje que informa al usuario sobre lo que se esta confirmando, junto a sus opciones.
 * @return retorno int - 0 si el usuario confirma. -1 si el usuario cancela.
 */
int verificarConfirmacion(char* mensaje);
/**
 * @fn int esNumerico(char*, int)
 * @brief Verifica que la cadena ingresada este compuesta solo de numeros.
 *
 * @param cadena char* - La cadena ingresada
 * @param length int - La longitud de la cadena
 * @return retorno int - -1 si la cadena esta vacia o la longitud es invalida
 * 						  0 si encuentra algo que no sea un numero.
 * 						  1 si no encuentra nada que no sea un numero.
 */
int esNumerico(char*cadena,int length);
/**
 * @fn int esNombreValido(char*, int)
 * @brief Verifica que la cadena ingresada este compuesta solo por letras
 *
 * @param cadena char* - La cadena ingresada
 * @param length int - La longitud de la cadena
 * @return retorno int - -1 si la cadena esta vacia o la longitud es invalida
 * 						  0 si encuentra algo que no sea una letra
 * 						  1 si no encuentra nada que no sea una letra
 */
int esNombreValido(char*cadena,int length);

#endif /* FUNCIONES_H_ */
