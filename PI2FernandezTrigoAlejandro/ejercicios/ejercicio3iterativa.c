/*
 * ejercicio3iterativa.c
 *
 *  	Analisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 2
 *
 */

#include "ejercicio3iterativa.h"

// ###################################################################################
// ###################################################################################
// ####################### 		EJERCICIO 3 - ITERATIVO				##################
// ###################################################################################
// ###################################################################################

// Dados dos numeros 1 y 2, se calcula a^expo en base a las siguientes condiciones
// Si n=0 --> 1, si n>0 --> en funcion del modulo, usamos divide y venceras para obtener
// una complejidad logaritmica:
long elevaAIterativo (long exponente, int n) {

	long base = 1L;

	while (n > 0) {

		if (n % 2 == 1) {

			base = base * exponente;

		}

		exponente *= exponente;
		n = n / 2;

	}

	return base;

}
