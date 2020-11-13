/*
 * ejercicio3recursivafinal.c
 *
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 2
 *
 */

#include "ejercicio3recursivafinal.h"

// ###################################################################################
// ###################################################################################
// ####################### 		EJERCICIO 3 - RECURSIVO FINAL		##################
// ###################################################################################
// ###################################################################################

// Dados dos numeros 1 y 2, se calcula a^expo en base a las siguientes condiciones
// Si n=0 --> 1, si n>0 --> en funcion del modulo, usamos divide y venceras para obtener
// una complejidad logaritmica:
long elevaARecursivoFinal (long exponente, int n) {

	return elevaARecursivoFinalInterno(1L, exponente, n);

}

// Funcion interna para ser llamada por la de arriba con
// parametros ya establecidos:
long elevaARecursivoFinalInterno (long base, long exponente, int n) {

	if (n > 0) {

		if (n % 2 == 1) {

			// base *= base && exponente *= exponente && n = n / 2;
			return elevaARecursivoFinalInterno((base *= exponente), (exponente *= exponente), (n / 2));

		} else {

			// base *= base && exponente *= exponente && n = n / 2;
			return elevaARecursivoFinalInterno((base *= exponente), exponente, (n / 2));

		}

	}

	return base;

}
