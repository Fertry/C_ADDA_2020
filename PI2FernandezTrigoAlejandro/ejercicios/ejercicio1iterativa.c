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

// Dados dos strings, donde cada uno representa una frase,
// itera sobre ambos. Determina en que punto de ambas frases
// dejan de ser iguales y devuelve esa posición numérica, para ello se emplea el
// algoritmo de búsqueda binaria:
int hastaDondeSonIgualesIterativo (string frase1, string frase2) {

	int i = 0;
	int k = 0;
	int resultado = -1;
	int j = frase1.size;

	while (j - i > 0 && resultado == -1) {

		// Posición: la mitad
		k = ((i + j) / 2);
		if (frase1.data[k] == frase2.data[k]) {

			i = k + 1;

		} else {

			// Hacia la izquierda
			if (frase1.data[k - 1] == frase2.data[k - 1]) {

				resultado = k;

			} else {

				j = k;

			}

		}

	}

	return resultado;

}


// Versión "simple" usando while no óptima:
/*
int hastaDondeSonIgualesIterativo (string frase1, string frase2) {

	int i = 0;
	bool verdadero = true;

	while (i < sizeof(frase1) && verdadero) {

		//*(frase1 + i) == *(frase2 + i)
		if (frase1.data[i] == frase2.data[i]) {

			i++;

		} else {

			verdadero = false;

		}

	}

	return i;

}
 */
