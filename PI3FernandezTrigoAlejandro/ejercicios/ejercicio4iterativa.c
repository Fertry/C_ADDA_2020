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
el resultado como Long:
*/
long ejercicio4Iterativo (int numeroA, int numeroB) {

	hash_table mapa = hash_table_empty(pair_type, long_type);

	int i = 0;
	while (i <= numeroA) {

		int j = 0;
		while (j <= numeroB) {

			if (i < 2 && j < 2) {

				// mapa.put(Pair.of(i, j), (long)(i + (j * j)));ç
				hash_table_put(&mapa, NULL, (long)(i + (j * j)));

			} else if (i < 2 || j < 2) {

				// mapa.put(Pair.of(i, j), (long)((i * i) + j));
				hash_table_put(&mapa, NULL, (long)((i * i) + j));

			} else {


				/*
				 	Long termino1 = mapa.get(Pair.of(i / 2, j - 1));
					Long termino2 = mapa.get(Pair.of(i / 3, j - 2));
					Long termino3 = mapa.get(Pair.of(i - 2, j / 4));
					mapa.put(Pair.of(i, j), (termino1 + termino2 + termino3));
				 */
				long termino1 = hash_table_get(&mapa, NULL);
				long termino2 = hash_table_get(&mapa, NULL);
				long termino3 = hash_table_get(&mapa, NULL);

				hash_table_put(&mapa, NULL, (termino1 + termino2 + termino3));

			}

			j++;

		}

		i++;

	}

	// return mapa.get(Pair.of(numeroA, numeroB));
	return hash_table_get(&mapa, NULL);

}
