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
	char mem2[500];

	printf("\n");
	// ATENCION: Por problemas de memoria de C, no puedo mostrar todos los arboles
	// por eso el bucle while esta comentado y solo muestra el primero!!!!
	//while (i < listaArboles.size) {

		tree * arbol = list_get(&listaArboles, i);
		hash_table resultado = ejercicio5Interno(listaArboles, i);

		printf("Arbol de entrada: %s\n", tree_tostring(arbol, mem1));
		printf("Hash table de salida: %s\n", hash_table_tostring(&resultado, mem2));
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		//i++;

	//}
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
hash_table * ejercicio5(list arboles, int arbol, int i, int j, hash_table * resultado) {

	// Obtener el arbol:
	tree * arbolito = list_get(&arboles, arbol);

	// Altura del arbol:
	int altura = calculaAlturaArbol(arbolito);

	// Anchura del arbol (nivel):
	list nivel = calculaNivelArbol(arbolito, i);

	if (i < altura) {

		if (j < nivel.size) {

			// Conjunto vacio de tipo Tree:
			set conjunto = set_empty(tree_type);

			// Nº de hijos del arbol:
			tree * arbolDeNivelJ = list_get(&nivel, j);
			int numeroHijos = arbolDeNivelJ->num_children;

			// Si el conjunto ya contiene la clave:
			if (hash_table_contains(resultado, &numeroHijos)) {

				// Añadir el arbol al conjunto:
				conjunto = *(set*) hash_table_get(resultado, &numeroHijos);
				set_add(&conjunto, arbolDeNivelJ);

		    // Si el conjunto no contiene la clave:
			} else {

				// Añadir el arbol al conjunto:
				set_add(&conjunto, arbolDeNivelJ);

			}

			// Añadir al hash_table resultado la clave (nº hijos) + el set de arboles:
			hash_table_put(resultado, &numeroHijos, &conjunto);

			// Vaciar el set:
			conjunto = set_empty(tree_type);

			// Recursion: siguiente nivel:
			int indice = j + 1;
			resultado = ejercicio5(arboles, arbol, i, indice, resultado);

		}

		// Resetear el arbol de nivel j:
		int j = 0;

		// Recursion: siguiente arbol:
		int indice = i + 1;
		resultado = ejercicio5(arboles, arbol, indice, j, resultado);

	// Caso base: si no entramos en el if, se devuelve el set vacio:
	} else {

		return resultado;

	}

	return resultado;

}
