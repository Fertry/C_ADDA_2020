/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio4iterativa.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 4 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que dados dos enteros a, b, calcule la siguiente sucesion numerica de forma
iterativa gracias a un bucle while en base a los parametros de entrada y devuelve
el resultado como entero usando pares (tuplas) para calcular cada termino por separado
en base a las condiciones del ejercicio:
*/
int ejercicio4Iterativo(int numeroA, int numeroB) {

	int_pair resultado;
	hash_table mapa = hash_table_empty(int_pair_type, int_type);

	for (int i = 0; i <= numeroA; i++) {

		for (int j = 0; j <= numeroB; j++) {

			int_pair tupla;
			tupla.a = i;
			tupla.b = j;

			if (i < 2 && j < 2) {

				int res1 = i + j * j;
				hash_table_put(&mapa, &tupla, &res1);

			} else if (i < 2 || j < 2) {

				int res2 = i * i + j;
				hash_table_put(&mapa, &tupla, &res2);

			} else {

				// Calculo de los terminos:
				int_pair tupla1;
				tupla1.a = i / 2;
				tupla1.b = j - 1;
				int_pair tupla2;
				tupla2.a = i / 3;
				tupla2.b = j - 2;
				int_pair tupla3;
				tupla3.a = i - 2;
				tupla3.b = j / 4;

				// Suma de los terminos:
				int total = *(int*) hash_table_get(&mapa, &tupla1)
							+ *(int*) hash_table_get(&mapa, &tupla2)
						    + *(int*) hash_table_get(&mapa, &tupla3);

				hash_table_put(&mapa, &tupla, &total);

			}

		}

	}

	resultado.a = numeroA;
	resultado.b = numeroB;

	int sumatorio = *(int*) hash_table_get(&mapa, &resultado);
	return sumatorio;

}
