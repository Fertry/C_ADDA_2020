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
	string frase1 = *(string*) list_get(&lista, 0);
	string frase2 = *(string*) list_get(&lista, 1);
	bool verdadero = true;

	while (i < frase1.size && verdadero) {

		if (frase1.data[i] == frase2.data[i]) {

			i++;

		} else {

			verdadero = false;
		}

	}

	return i;

}
