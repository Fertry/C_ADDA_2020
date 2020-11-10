/*
 * ejercicio2recursivafinal.c
 *
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 2
 *
 */

#include "ejercicio2recursivafinal.h"

// ###################################################################################
// ###################################################################################
// ####################### 		EJERCICIO 2 - RECURSIVO FINAL		##################
// ###################################################################################
// ###################################################################################

// Dado dos numeros a,b se calcula si a es múltiplo de b en base a las siguientes condiciones
// Si a==0 --> true, si 0<a<b --> false y si a>=b --> a=a-b:
bool esMultiploRecursivoFinal (int numero1, int numero2) {

	return esMultiploRecursivoFinalInterno (false, numero1, numero2);

}

// Funcion interna para ser llamada por la de arriba (publica) con
// parametros ya establecidos:
bool esMultiploRecursivoFinalInterno (bool verdadero, int numero1, int numero2) {

	bool resultado;

	if (numero1 == 0) {

		return true;

	} else if (numero1 > 0) {

		return esMultiploRecursivoFinalInterno (verdadero, numero1 - numero2, numero2);

	} else {

		resultado = verdadero;
		return resultado;

	}

}
