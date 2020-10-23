/*
 * ejercicio3.c
 *
 *  	Análisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernández Trigo
 *      Práctica Individual 1
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
	list miniLista = list_empty(double_type);
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		miniLista = list_empty(double_type);
		char *fila = (char*) iterable_next(&filas);
		iterator miniFila = split_iterable_pchar(fila, ",");

		while (iterable_has_next(&filas)) {


			/*
			char *numero = (char*) iterable_next(&miniFila);
            int numeroEntero = int_parse_s(numero);
            list_add(&miniLista, &numeroEntero);
			 */

		}

	}

	return resultado;

}

// Dado una lista de puntos, devuelve una colección de tipo Map con la suma de sus
// coordenadas X e Y por cuadrantes:
hash_table sumaPorCuadrantes (list lista) {

	int i = 0;
	hash_table resultado = hash_table_empty(int_type, double_type);

	while (i < list_size(&lista)) {

		double valorPunto = 0.;
		punto *p = (punto*) list_get(&lista, i);
		Cuadrante c = punto_cuadrante(p);

		if (hash_table_contains(&resultado, &c) != 0) {

			valorPunto = *(double*) hash_table_get(&resultado, &c);

		}

		double valorActual = p->x;
		double suma = valorPunto + valorActual;
		hash_table_put(&resultado, &c, &suma);
		printf("%f", valorPunto);
		i++;

	}

	return resultado;

}

