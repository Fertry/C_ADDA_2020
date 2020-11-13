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

// Dados dos strings, donde cada uno representa una frase,
// itera sobre ambos. Determina en que punto de ambas frases
// dejan de ser iguales y devuelve esa posicion numerica, para ello se emplea el
// algoritmo de búsqueda binaria para obtener una complejidad de orden logaritmico:
int hastaDondeSonIgualesRecursivoFinal (string frase1, string frase2) {

	int i = 0;
	int j = frase1.size;

	return hastaDondeSonIgualesRecursivoFinalInterno (i, j, frase1, frase2);

}

// Funcion interna para ser llamada por la de arriba con
// parametros ya establecidos:
int hastaDondeSonIgualesRecursivoFinalInterno (int i, int j, string frase1, string frase2) {

	int k = 0;
	int resultado = -1;

	if (j - i > 0 && resultado == -1) {

		// Posición: la mitad
		k = ((i + j) / 2);
		if (frase1.data[k] == frase2.data[k]) {

			//i = k + 1;
			return hastaDondeSonIgualesRecursivoFinalInterno((k + 1), j, frase1, frase2);

		} else {

			// Hacia la izquierda
			if (frase1.data[k - 1] == frase2.data[k - 1]) {

				resultado = k;

			} else {

				//j = k;
				return hastaDondeSonIgualesRecursivoFinalInterno(i, k, frase1, frase2);

			}

		}

	} else {

		return resultado;

	}

	return resultado;

}


// Versión "simple" usando while no óptima:
/*
int hastaDondeSonIgualesRecursivoFinal (list lista) {

	return hastaDondeSonIgualesRecursivoFinalInterno (0, lista);

}

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
*/
