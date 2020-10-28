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
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		char *fila = (char*) iterable_next(&filas);
		punto P = punto_parse_s(fila);
		list_add(&resultado, &P);

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

// Función auxiliar para mostrar el resultado del ejercicio 3. Dado que
// el método hash_table_tostring() devuelve el resultado como (nº cuadrante,
// valor), construimos una función para igualar la salida al fichero de
// resultados proporcionado:
void funcionAuxiliarEjercicio3 (hash_table tabla) {

	int i = 0;

	while (i < 4) {

		double * valorCuadrante = hash_table_get(&tabla, &i);

		if (i == 0) {

			printf("PRIMER_CUADRANTE = %f\n", *valorCuadrante);

		} else if (i == 1) {

			printf("SEGUNDO_CUADRANTE = %f\n", *valorCuadrante);

		} else if (i == 2) {

			printf("TERCER_CUADRANTE = %f\n", *valorCuadrante);

		} else if (i == 3) {

			printf("CUARTO_CUADRANTE = %f\n", *valorCuadrante);

		}

		i++;

	}

}
