/*
 *  	Analisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Ex�menes del 1� cuatrimestre de ADDA
 */

#include "Ejercicios18_19.h"

/*
 * Decidir si los elementos de una lista de enteros forman una progresi�n aritm�tica.
 * Una progresi�n aritm�tica es una sucesi�n de n�meros tales que su distancia
 * (diferencia de cualquier par de t�rminos sucesivos de la secuencia) es constante. Se
 * considera que una lista vac�a o con tama�o igual a 1 o 2, son progresiones
 * aritm�ticas.
 */

/*
 * Soluci�n iterativa
 */
bool ejercicioIterativo(list lista) {

	int i = 2;
	bool resultado = true;

	// Si la lista es de tama�o 2 o menor, automaticamente es true:
	if (lista.size > 2) {

		// Diferencia entre los dos primeros n�meros:
		int diferencia = list_get(&lista, 1) - list_get(&lista, 0);

		// Con la diferencia anterior, recorremos la lista comprobando
		// si los demas elementos cumplen la sucesi�n:
		while (i < lista.size) {

			resultado = (list_get(&lista, i + 1) - list_get(&lista, i)) == diferencia;
			i++;

		}

	}

	return resultado;

}
