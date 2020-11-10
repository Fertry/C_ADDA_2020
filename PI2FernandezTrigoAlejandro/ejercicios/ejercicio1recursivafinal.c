/*
 * ejercicio1recursivafinal.c
 *
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 2
 *
 */

#include "ejercicio1recursivafinal.h"

// ###################################################################################
// ###################################################################################
// ####################### 		EJERCICIO 1 - RECURSIVO FINAL		##################
// ###################################################################################
// ###################################################################################

// Dada una lista de listas de strings, donde cada lista contiene dos frases,
// itera sobre ambas frases de cada lista. Determina en que punto de ambas frases
// dejan de ser iguales y devuelve esa posición numérica:
int hastaDondeSonIgualesRecursivoFinal (list lista) {

	return hastaDondeSonIgualesRecursivoFinalInterno (0, lista);

}

// Funcion interna para ser llamada por la de arriba (publica) con
// parametros ya establecidos:
int hastaDondeSonIgualesRecursivoFinalInterno (int i, list lista) {

	char *frase1 = (char*) list_get(&lista, 0);
	char *frase2 = (char*) list_get(&lista, 1);

	while (i < sizeof(frase1)) {

		if (*(frase1 + i) == *(frase2 + i)) {

			i++;
			return hastaDondeSonIgualesRecursivoFinalInterno (i, lista);

		} else {

			return i;

		}

	}

	return i;

}
