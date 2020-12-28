/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#include "ejercicio2.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 2 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que lee...
*/
list leeDatosEjercicio2Arboles(char * fichero) {

	memory_heap memoria = memory_heap_create();
	iterator filas = file_iterable_pchar(fichero);
	list listaArboles = list_empty(binary_tree_type);

	while (iterable_has_next(&filas)) {

		char ** token[80];
		char limite[] = "#";
		char * linea = (char*) iterable_next(&filas);

		// Split con token:
		pchar_split_text(linea, limite, token);

		binary_tree *arbol = binary_tree_parse(token[0], &memoria);
		list_add(&listaArboles, arbol);

	}

	return listaArboles;

}

/*
Funcion que lee...
*/
list leeDatosEjercicio2Listas(char * fichero) {

	list listaLetras = list_empty(list_type);
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		char ** token[80];
		char limite[] = "#";
		char * linea = (char*) iterable_next(&filas);

		// Split con token:
		pchar_split_text(linea, limite, token);

		// Eliminar los "[]"
		char izquierda[] = "[";
		char derecha[] = "]";
		char * izq[100];
		char * drc[100];
		pchar_split_text(token[1], izquierda, izq);
		pchar_split_text(drc[0], derecha, drc);

		// Sacar la lista
		list miniLista = list_empty(pchar_type);
		iterator listas = text_to_iterable_pchar(drc[0], ",");

		while (iterable_has_next(&listas)) {

			char * letra = (char*) iterable_next(&filas);
			list_add(&miniLista, letra);

		}

		list_add(&listaLetras, &miniLista);

	}

	return listaLetras;

}

/*
Funcion que lee...
*/
//void funcionAuxiliarEjercicio2() {



//}


