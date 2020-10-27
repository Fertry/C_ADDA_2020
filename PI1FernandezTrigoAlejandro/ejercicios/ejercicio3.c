/*
 * ejercicio3.c
 *
 *  	An�lisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fern�ndez Trigo
 *      Pr�ctica Individual 1
 *
 */

#include "ejercicio3.h"

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 3                         #################
//###################################################################################
//###################################################################################

// Funcion que lee una lista de puntos del formato (coordenadaX, coordenadaY) y devuelve
// una lista de Punto2D formada por los puntos del fichero:
list leeDatosEjercicio3 (char * fichero) {

	list resultado = list_empty(punto_type);
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		char *fila = (char*) iterable_next(&filas);
		punto P = punto_parse_s(fila);
		list_add(&resultado, &P);

	}

	return resultado;

}

// Dado una lista de puntos, devuelve una colecci�n de tipo Map con la suma de sus
// coordenadas X e Y por cuadrantes:
hash_table sumaPorCuadrantes (list lista) {

	int i = 0;
	hash_table resultado = hash_table_empty(int_type, double_type);

	while (i < list_size(&lista)) {

		double sumatorio = 0.;
		punto * Punto = (punto*) list_get(&lista, i);
		Cuadrante cuadrante = punto_cuadrante(Punto);

		if (hash_table_contains(&resultado, &cuadrante) != 0) {

			sumatorio = *(double*) hash_table_get(&resultado, &cuadrante);

		}

		double valorCoordenadaX = Punto -> x;
		double suma = sumatorio + valorCoordenadaX;
		hash_table_put(&resultado, &cuadrante, &suma);
		printf("%f", sumatorio);
		i++;

	}

	return resultado;

}
