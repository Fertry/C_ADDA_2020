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
Funcion que lee el fichero de entrada que, por cada linea, representa un arbol binario
de tipo string y, separado por un "#", una lista de caracteres. Empleamos dos funciones
, una para leer los arboles (a la izquierda del "#") y otra para las listas:
*/
list leeDatosEjercicio2Arboles(char * fichero) {

	list listaArboles = list_empty(binary_tree_type);
	iterator filas = file_iterable_pchar(fichero);
	memory_heap memoria = memory_heap_create();

	while (iterable_has_next(&filas)) {

		char * a = (char*) iterable_next(&filas);
		char b[] = "#";
		char * c[200];

		// Hacer split y parsear el arbol que queda a la
		// izquierda del "#":
		pchar_split_text(a, b, c);
		binary_tree * arbol = binary_tree_parse(c[0], &memoria);

		list_add(&listaArboles, arbol);

	}

	return listaArboles;

}

/*
Funcion que lee el fichero de entrada que, por cada linea, representa un arbol binario
de tipo string y, separado por un "#", una lista de caracteres. Empleamos dos funciones
, una para leer los arboles (a la izquierda del "#") y otra para las listas:
*/
list leeDatosEjercicio2Listas(char * fichero) {

	list letras = list_empty(list_type);
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		char * a = (char*) iterable_next(&filas);
		char b[] = "#";
		char * c[80];

		// Hacer split a partir del "#" y, con el contenido
		// de la derecha (la lista), eliminar los caracteres
		// "[, ]" y hacer split en base a la coma:
		pchar_split_text(a, b, c);

		char * izquierda[50];
		char * derecha[50];
		char p1[] = "[";
		char p2[] = "]";

		pchar_split_text(c[1], p1, izquierda);
		pchar_split_text(izquierda[0], p2, derecha);

		list listaDeLetras = list_empty(pchar_type);
		iterator fila = text_to_iterable_pchar(derecha[0], ",");

		// Recorrer el nuevo iterador extrayendo cada letra separada
		// y añadiendolas a la listaDeLetras que, por ultimo se añade
		// a la lista resultante (lista de listas):
		while (iterable_has_next(&fila)) {

			char * letra = (char*) iterable_next(&fila);
			list_add(&listaDeLetras, letra);

		}

		list_add(&letras, &listaDeLetras);

	}

	return letras;

}

/*
Funcion auxiliar para recorrer las listas devueltas por las lecturas y, por cada par de listas (arbol y lista)
mostrarlos por pantalla y pasarlos como parametros a la funcion que resuelve el ejercicio:
*/
void funcionAuxiliarEjercicio2(list listaArboles, list listaLetras) {

	int i = 0;
	int j = 0;
	char mem1[500];
	char mem2[500];

	printf("\n");
	while (i < listaArboles.size) {

		while (j < listaLetras.size) {

			list miniLista = *(list*) list_get(&listaLetras, i);
			binary_tree * arbol = (binary_tree*) list_get(&listaArboles, i);

			printf("Arbol de entrada: %s\n", binary_tree_tostring(arbol, mem1));
			printf("Lista de entrada: %s\n", list_tostring(&miniLista, mem2));
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			i++;
			j++;

		}

	}
	printf("\n");

}
