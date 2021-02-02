/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Exámenes del 1º cuatrimestre de ADDA
 */

#include "Ejercicios18_19.h"

/*
 * Decidir si los elementos de una lista de enteros forman una progresión aritmética.
 * Una progresión aritmética es una sucesión de números tales que su distancia
 * (diferencia de cualquier par de términos sucesivos de la secuencia) es constante. Se
 * considera que una lista vacía o con tamaño igual a 1 o 2, son progresiones
 * aritméticas.
 */

/*
 * Solución iterativa
 */
bool ejercicioIterativo(list lista) {

	int i = 2;
	bool resultado = true;

	// Si la lista es de tamaño 2 o menor, automaticamente es true:
	if (lista.size > 2) {

		// Diferencia entre los dos primeros números:
		int diferencia = list_get(&lista, 1) - list_get(&lista, 0);

		// Con la diferencia anterior, recorremos la lista comprobando
		// si los demas elementos cumplen la sucesión:
		while (i < lista.size) {

			resultado = (list_get(&lista, i + 1) - list_get(&lista, i)) == diferencia;
			i++;

		}

	}

	return resultado;

}
