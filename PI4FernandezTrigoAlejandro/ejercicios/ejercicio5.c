/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
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
de tipo generico que se parsea y añade a la lista resultante:
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

		printf("Arbol de entrada: %s", tree_tostring(arbol, mem));
		printf("Hash table de salida: ");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
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
hash_table ejercicio5Interno(list arboles, int arbol) {

	hash_table resultado = hash_table_empty(int_type, set_type);

	return ejercicio5(arboles, arbol, 0, 0, 0, resultado);

}

/*
Funcion que dado un arbol n-ario (lista de arboles e indice del arbol a leer),
devuelve un mapa de tipo int, set donde las claves representan el nº de hijos
del arbol y sus valores son un Set de arboles que contienen ese mismo nº de hijos.
Es decir, asociado a la clave 0, estaran los arboles cuyo nº de hijos sea 0,
asociado a la clave 1, estaran los arboles cuyo nº de hijos sea 1, etc:
*/
hash_table ejercicio5(
		list arboles,
		int arbol,
		int i,
		int j,
		int k,
		hash_table resultado) {

	// Altura del arbol:
	if (j < list_get(&arboles, arbol).getHeight() + 1) {

		// Anchura del arbol (nivel):
		if (k < list_get(&arboles, arbol).getLevel(j).size) {

			// Conjunto vacio de tipo Tree:
			Set<Tree<String>> conjunto = new HashSet<Tree<String>>();

			// Si el conjunto ya contiene la clave
			if (resultado.containsKey(list_get(&arboles, arbol).getLevel(j).get(k).getNumOfChildren())) {

				conjunto = resultado.get(list_get(&arboles, arbol).getLevel(j).get(k).getNumOfChildren());

				// Si el arbol NO es vacio:
				if (!list_get(&arboles, arbol).getLevel(j).get(k).isEmpty()) {

					conjunto.add(arboles.get(arbol).getLevel(j).get(k));

					// Si el arbol SI es vacio:
				} else {

					conjunto.add(Tree.empty());

				}

				// Añadir al mapa resultado la clave (nº hijos) + el set de arboles:
				resultado.put(arboles.get(arbol).getLevel(j).get(k).getNumOfChildren(), conjunto);

				// Si el conjunto no contiene la clave:
			} else {

				// Si el arbol NO es vacio:
				if (!list_get(&arboles, arbol).getLevel(j).get(k).isEmpty()) {

					conjunto.add(arboles.get(arbol).getLevel(j).get(k));

					// Si el arbol SI es vacio:
				} else {

					conjunto.add(Tree.empty());

				}

				// Añadir al mapa resultado la clave (nº hijos) + el set de arboles:
				resultado.put(list_get(&arboles, arbol).getLevel(j).get(k).getNumOfChildren(), conjunto);

			}

			// Vaciar el set:
			conjunto = new HashSet<Tree<String>>();

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

