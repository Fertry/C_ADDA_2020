/*
 * ejercicio1iterativa.c
 *
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 2
 *
 */

#include "ejercicio1iterativa.h"

// ###################################################################################
// ###################################################################################
// ####################### 		EJERCICIO 1 - ITERATIVO				##################
// ###################################################################################
// ###################################################################################

// Dada una lista de listas de strings, donde cada lista contiene dos frases,
// itera sobre ambas frases de cada lista. Determina en que punto de ambas frases
// dejan de ser iguales y devuelve esa posición numérica:
int hastaDondeSonIgualesIterativo (list lista) {

	int i = 0;
	bool verdadero = true;
	char *frase1 = (char*) list_get(&lista, 0);
	char *frase2 = (char*) list_get(&lista, 1);

	while (i < sizeof(frase1) && verdadero) {

		if (*(frase1 + i) == *(frase2 + i)) {

			i++;

		} else {

			verdadero = false;

		}

	}

	return i;

}
