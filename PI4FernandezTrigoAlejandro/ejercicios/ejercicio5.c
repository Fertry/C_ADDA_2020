/*
 *  	Analisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#include "ejercicio4.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 5 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que lee el fichero de entrada que, por cada linea, un arbol n-ario
de tipo generico que se parsea y a�ade a la lista resultante:
*/
list leeDatosEjercicio5(char * fichero) {

	list listaArboles = list_empty(tree_type);
	memory_heap memoria = memory_heap_create();
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		char * linea = (char*) iterable_next(&filas);
		tree * arbol = tree_parse(linea, &memoria);
		list_add(&listaArboles, arbol);

	}

	return listaArboles;

}

/*
Funcion auxiliar para recorrer la lista de arboles y por cada uno, mostrar dicho arbol
por pantalla y llamar a la funcion que resuelve el ejercicio pasandole como argumento
la lista y el indice correspondiente al arbol a leer:
*/
void funcionAuxiliarEjercicio5(list listaArboles) {

	int i = 0;
	char mem[500];

	printf("\n");
	while (i < listaArboles.size) {

		tree * arbol = list_get(&listaArboles, i);

		printf("Arbol de entrada: %s\n", tree_tostring(arbol, mem));
		printf("Hash table de salida: \n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		i++;

	}
	printf("\n");

}

/*
Funcion que llama de forma opaca al usuario a la funcion que resuelve el ejercicio
pasandole a esta como parametros la lista de arboles y el indice que indica el arbol
a leer. Ademas, se le pasa como parametro un mapa de tipo int, set que corresponde
al mapa a devolver:
*/

/*
hash_table ejercicio5Interno(list arboles, int arbol) {

	hash_table resultado = hash_table_empty(int_type, set_type);

	return ejercicio5(arboles, arbol, 0, 0, 0, &resultado);

}
*/

/*
Funcion que dado un arbol n-ario (lista de arboles e indice del arbol a leer),
devuelve un mapa de tipo int, set donde las claves representan el n� de hijos
del arbol y sus valores son un Set de arboles que contienen ese mismo n� de hijos.
Es decir, asociado a la clave 0, estaran los arboles cuyo n� de hijos sea 0,
asociado a la clave 1, estaran los arboles cuyo n� de hijos sea 1, etc:
*/

/*
hash_table ejercicio5(
		list arboles,
		int arbol,
		int i,
		int j,
		int k,
		hash_table * resultado) {

	// Altura del arbol:
	int alturaDelArbol = *(int*) list_get(&arboles, arbol).getHeight();
	if (j < alturaDelArbol + 1) {

		// Anchura del arbol (nivel):
		int anchuraDelArbol = *(int*) list_get(&arboles, arbol).getLevel(j).size;
		if (k < anchuraDelArbol) {

			// Conjunto vacio de tipo Tree:
			set conjunto = set_empty(tree_type);

			// Si el conjunto ya contiene la clave
			int numeroDeHijos = *(int*) list_get(&arboles, arbol).getLevel(j).get(k).getNumOfChildren();
			if (hash_table_contains(resultado, &numeroDeHijos)) {

				// MAL! ESTO ES UN SET NO UN MAP!!
				conjunto = hash_table_get(resultado, numeroDeHijos);

				// Si el arbol NO es vacio:
				tree arbolVacio = tree_empty(tree_type);
				tree arbolDeNivelJ = list_get(&arboles, arbol).getLevel(j).get(k);
				if (!tree_equals(arbolDeNivelJ, arbolVacio)) {

					// MAL! ESTO ES UN SET NO UN MAP!!
					hash_table_put(conjunto, &numeroDeHijos, &arbolDeNivelJ);

				// Si el arbol SI es vacio:
				} else {

					set_add(&conjunto, arbolVacio);

				}

				// A�adir al mapa resultado la clave (n� hijos) + el set de arboles:
				hash_table_put(resultado, &numeroDeHijos, &conjunto);

			// Si el conjunto no contiene la clave:
			} else {

				// Si el arbol NO es vacio:
				if (!list_get(&arboles, arbol).getLevel(j).get(k).isEmpty()) {

					conjunto.add(arboles.get(arbol).getLevel(j).get(k));

				// Si el arbol SI es vacio:
				} else {

					tree arbolVacio = tree_empty(tree_type);
					set_add(&conjunto, arbolVacio);

				}

				// A�adir al mapa resultado la clave (n� hijos) + el set de arboles:
				resultado.put(list_get(&arboles, arbol).getLevel(j).get(k).getNumOfChildren(), conjunto);

			}

			// Vaciar el set:
			conjunto = set_empty(tree_type);

			// Recursion:
			resultado = ejercicio5(arboles, arbol, i, j, k + 1, resultado);

		}

		// Recursion:
		resultado = ejercicio5(arboles, arbol, i, j + 1, k, resultado);

	// Caso base: si no entramos en el if, se devuelve el set vacio:
	} else {

		return resultado;

	}

	return resultado;

}
*/

/*
Funcion auxiliar para calcular el nivel de un arbol
dado como parametro el arbol y la lista correspondiente
al nivel 0 del arbol:
*/
/*
list calculaNivelArbol(tree * arbol, list nivelCero) {

	int size = list_size(&nivelCero);
	list resultado = list_empty(tree_type);

	for (int j = 0; j < size; j++) {

		int numeroHijos = tree_child_number(arbol);

		for (int hijo = 0; hijo < numeroHijos; hijo++) {

			list_add(&resultado, tree_get_child(arbol, hijo));

		}

	}

	return resultado;

}
*/
