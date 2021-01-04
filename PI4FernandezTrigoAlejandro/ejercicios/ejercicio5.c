/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#include "ejercicio5.h"
#include "funcionesAuxiliares.h"

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
		// Descomentar para pasar a string
		// tree * arbol = tree_parse(linea, &memoria);
		tree * arbol = tree_map(tree_parse(linea, &memoria), int_type, castearArbol, &memoria);
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
	char mem1[500];
	//char mem2[500];

	printf("\n");
	while (i < listaArboles.size) {

		tree * arbol = list_get(&listaArboles, i);
		//hash_table resultado = ejercicio5Interno(listaArboles, i);

		printf("Arbol de entrada: %s\n", tree_tostring(arbol, mem1));
		//printf("Hash table de salida: %s\n", hash_table_tostring(&resultado, mem2));
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
hash_table ejercicio5Interno(list arboles, int arbol) {

	hash_table resultado = hash_table_empty(int_type, set_type);

	return * ejercicio5(arboles, arbol, 0, 0, &resultado);

}

/*
Funcion que dado un arbol n-ario (lista de arboles e indice del arbol a leer),
devuelve un mapa de tipo int, set donde las claves representan el nº de hijos
del arbol y sus valores son un Set de arboles que contienen ese mismo nº de hijos.
Es decir, asociado a la clave 0, estaran los arboles cuyo nº de hijos sea 0,
asociado a la clave 1, estaran los arboles cuyo nº de hijos sea 1, etc:
*/
hash_table * ejercicio5(
		list arboles,
		int arbol,
		int i,
		int j,
		hash_table * resultado) {

	// Obtener el arbol:
	tree * arbolito = list_get(&arboles, arbol);

	// Altura del arbol:
	int altura = calculaAlturaArbol(arbolito);

	// Anchura del arbol (nivel) y nº de hijos:
	list nivel = calculaNivelArbol(arbolito, i);
	tree * arbolDeNivelJ = list_get(&nivel, j);
	int numeroDeHijos = tree_child_number(arbolDeNivelJ);

	// Altura:
	if (i < altura) {

		// Anchura:
		if (j < nivel.size) {

			// Conjunto vacio de tipo Tree:
			set conjunto = set_empty(tree_type);

			// Si el conjunto ya contiene la clave:
			if (hash_table_contains(resultado, &numeroDeHijos)) {

				conjunto = *(set*) hash_table_get(resultado, &numeroDeHijos);

				// Si el arbol NO es vacio:
				if (arbolDeNivelJ->tree_type != Empty_Tree) {

					set_add(&conjunto, arbolDeNivelJ);

				// Si el arbol SI es vacio:
				} else {

					memory_heap memoria1 = memory_heap_create();
					tree * arbolVacio = tree_empty(&memoria1);
					set_add(&conjunto, arbolVacio);

				}

				// Añadir al mapa resultado la clave (nº hijos) + el set de arboles:
				hash_table_put(resultado, &numeroDeHijos, &conjunto);

			// Si el conjunto no contiene la clave:
			} else {

				// Si el arbol NO es vacio:
				if (arbolDeNivelJ->tree_type != Empty_Tree) {

					set_add(&conjunto, arbolDeNivelJ);

				// Si el arbol SI es vacio:
				} else {

					memory_heap memoria2 = memory_heap_create();
					tree * arbolVacio = tree_empty(&memoria2);
					set_add(&conjunto, arbolVacio);

				}

				// Añadir al mapa resultado la clave (nº hijos) + el set de arboles:
				hash_table_put(resultado, &numeroDeHijos, &conjunto);

			}

			// Vaciar el set:
			conjunto = set_empty(tree_type);

			// Recursion:
			int indice = j + 1;
			resultado = ejercicio5(arboles, arbol, i, indice, resultado);

		}

		// Recursion:
		int indice = i + 1;
		resultado = ejercicio5(arboles, arbol, indice, j, resultado);

	// Caso base: si no entramos en el if, se devuelve el set vacio:
	} else {

		return resultado;

	}

	return resultado;

}
