/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio2recursiva.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 2 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que dado una lista de numeros localiza la sublista cuya suma de adyacentes
es mayor usando divide y venceras y que se realiza llamando a la funcion
ejercicio2RecursivoInterno para actuar de forma opaca hacia el usuario:
*/
smax ejercicio2Recursivo(list lista) {

	// Tamaño menos 1:
	int i = list_size(&lista) - 1;

	return ejercicio2RecursivoInterno(lista, 0, i);

}

/*
Funcion  que emplea el algoritmo de divide y venceras sobre la lista de entrada
tantas veces como sea necesario para devolver una tupla con los indices que definen la
subsecuencia y la suma asociada:
* Recursividad: 1 Caso base + 2 recursivos
*/
smax ejercicio2RecursivoInterno(list lista, int inicio, int fin) {

	// Caso base:
	if (inicio == fin) {

		return smax_of(inicio, fin, *(int*) list_get(&lista, inicio));

	}

	int mitad = (inicio + fin) / 2;

	// Casos recursivos:
	// Calcula la suma de la izquierda:
	smax secuenciaIzquierda = ejercicio2RecursivoInterno(lista, inicio, mitad);
	// Calcula la suma de la derecha:
	smax secuenciaDerecha = ejercicio2RecursivoInterno(lista, mitad + 1, fin);
	// Calcula la suma del cruze:
	smax secuenciaMitad = calculaSecuenciaMitad(lista, inicio, fin, mitad);

	// Obtiene los valores de sus sumas:
	int totalIzquierda = secuenciaIzquierda.suma;
	int totalDerecha = secuenciaDerecha.suma;
	int totalMitad = secuenciaMitad.suma;

	// Compara las sumas para devolver la mayor:
	if (totalIzquierda > totalDerecha && totalIzquierda > totalMitad) {

		return secuenciaIzquierda;

	} else if (totalDerecha > totalIzquierda && totalDerecha > totalMitad) {

		return secuenciaDerecha;

	} else {

		return secuenciaMitad;

	}

}

/*
Funcion auxiliar para calcular la subsecuencia asociada al cruce; esto es
devuelve una tupla con sus indices y la suma asociada para comparar:
*/
smax calculaSecuenciaMitad(list lista, int i, int j, int k) {

	int maximoIzquierda = k;
	int maximoDerecha = k + 1;
	int total = *(int*) list_get(&lista, k);
	int totalDerecha = *(int*) list_get(&lista, k);
	int totalIzquierda = *(int*) list_get(&lista, k);

	// Hacia la izquierda:
	int indice1 = k - 1;
	while (indice1 >= i) {

		total = total + *(int*) list_get(&lista, indice1);

		if (total > totalIzquierda) {

			totalIzquierda = total;
			maximoIzquierda = indice1;

		}

		indice1--;

	}

	// Reseteo:
	total = *(int*) list_get(&lista, k);

	// Hacia la derecha:
	int indice2 = k + 1;
	while (indice2 < j) {

		total = total + *(int*) list_get(&lista, indice2);

		if (total > totalDerecha) {

			totalDerecha = total;
			maximoDerecha = indice2 + 1;

		}

		indice2++;

	}

	// Devuelvo la tupla con los indices y la suma:
	return smax_of(maximoIzquierda, maximoDerecha, ((totalIzquierda + totalDerecha) - *(int*) list_get(&lista, k)));

}

