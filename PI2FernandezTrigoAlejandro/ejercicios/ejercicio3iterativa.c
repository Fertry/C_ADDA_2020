/*
 * ejercicio3iterativa.c
 *
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
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

// Dados dos numeros 1 y 2, que son respectivamente, la base (Long) y el exponente (Integer)
// se calcula a^n en base a las siguientes condiciones
// Si exponente=0 --> 0, si exponente>0 --> en funcion del modulo:
long elevaAIterativo (long numero1, int numero2) {

	long resultado = (long) 1;
	long base = (long) numero1;
	int exponente = numero2;

	while (exponente > 0) {

		if (exponente % 2 == 1) {

			//Si modulo == 1 ----> (a^(n/2))^2 * a
			resultado = (long) (base * (pow((pow(base, (exponente / 2))), 2)));
			return resultado;

		} else {

			//Si modulo == 0 ----> (a^(n/2))^2
			resultado = (long) (pow((pow(base, (exponente / 2))), 2));
			return resultado;

		}

	}

	return resultado;

}
