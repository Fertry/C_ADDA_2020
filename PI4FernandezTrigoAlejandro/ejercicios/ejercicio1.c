/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#include "ejercicio1.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 1 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que lee...
*/
list leeDatosEjercicio1(char * fichero) {

	memory_heap memoria = memory_heap_create();
	iterator filas = file_iterable_pchar(fichero);
	list listaArboles = list_empty(binary_tree_type);

	while (iterable_has_next(&filas)) {

		char * linea = (char*) iterable_next(&filas);
		binary_tree * arbol = binary_tree_parse(linea, &memoria);
		list_add(&listaArboles, arbol);

	}

	return listaArboles;

}

/*
Funcion que lee...
*/
void funcionAuxiliarEjercicio1(list listaArboles) {

	int i = 0;
	char mem[500];
	char mem2[500];

	while (i < listaArboles.size) {

		binary_tree * arbol = (binary_tree*) list_get(&listaArboles, i);
		bool res = ejercicio1(arbol);
		printf("Arbol de entrada: %s", binary_tree_tostring(arbol, mem));
		printf("\n");
		printf("¿Cumple el predicado?: %s", bool_tostring(&res, mem2));
		printf("\n");
		i++;

	}

}

/*
Funcion que...
*/
bool esBinario(binary_tree * arbol) {

	bool resultado = false;
	int tam = binary_tree_size(arbol);

	if (tam >= 3) {

		resultado = true;

	}

	return resultado;

}

/*
Funcion que...
*/
bool ejercicio1(binary_tree * arbol) {

	if (arbol->tree_type == Binary_Tree) {

		int label = *(int*) binary_tree_label(arbol);
		binary_tree * arbolIzquierdo = binary_tree_left(arbol);
		int izquierda = *(int*) binary_tree_label(arbolIzquierdo);
		binary_tree * arbolDerecho = binary_tree_right(arbol);
		int derecha = *(int*) binary_tree_label(arbolDerecho);

		bool iguales = (izquierda + derecha) == label;

		return iguales && ejercicio1(arbolIzquierdo) && ejercicio1(arbolDerecho);

	} else {

		return true;

	}

}
