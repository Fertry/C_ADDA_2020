/*
 * ejercicio2iterativa.c
 *
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 2
 *
 */

#include "ejercicio2iterativa.h"

// ###################################################################################
// ###################################################################################
// ####################### 		EJERCICIO 2 - ITERATIVO				##################
// ###################################################################################
// ###################################################################################

// Dado dos numeros a,b se calcula si a es múltiplo de b en base a las siguientes condiciones
// Si a==0 --> true, si 0<a<b --> false y si a>=b --> a=a-b lo que supone una complejidad lineal:
bool esMultiploIterativo (int numero1, int numero2) {

	bool resultado = false;

	while (numero1 > 0) {

			numero1 = numero1 - numero2;
			if (numero1 == 0) {

				return true;

			} else if (numero1 < 0) {

				return false;

			}

		}

	return resultado;

}
