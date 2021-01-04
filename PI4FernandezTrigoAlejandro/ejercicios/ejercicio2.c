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
, una para leer los arboles (a la izquierda del "#") y otra para las listas. Para que
funcione, llamamos a la funcion que devuelve los arboles dentro de esta de forma que
solo llamaremos a esta funcion que nos devolvera la lista de arboles y la lista de
listas en una sola variable:
*/
list leeDatosEjercicio2Listas(char * fichero) {

	list letras = list_empty(list_type);
	list resultado = list_empty(list_type);
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

	// Llamada a la funcion que lee los arboles del fichero:
	list arboles = leeDatosEjercicio2Arboles(fichero);

	list_add(&resultado, &arboles);
	list_add(&resultado, &letras);

	return resultado;

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
	char mem3[500];

	printf("\n");
	while (i < listaArboles.size) {

		while (j < listaLetras.size) {

			// Extraer el arbol y la lista de letras correspondiente a los indices
			// de las listas proporcionadas como parametros:
			list letras = *(list*) list_get(&listaLetras, j);
			binary_tree * arbol = (binary_tree*) list_get(&listaArboles, i);
			bool resultado = ejercicio2Interno(arbol, letras);

			printf("Arbol de entrada: %s\n", binary_tree_tostring(arbol, mem1));
			printf("Lista de entrada: %s\n", list_tostring(&letras, mem2));
			printf("¿Existe camino desde la raiz para la lista? %s\n", bool_tostring(&resultado, mem3));
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			i++;
			j++;

		}

	}
	printf("\n");

}

/*
Funcion que llama de forma opaca al usuario a la funcion que resuelve el ejercicio
pasandole a esta como parametros los valores invocados en la funcion auxiliar que
corresponden al arbol y la lista leidos junto con un indice:
*/
bool ejercicio2Interno(binary_tree * arbol, list lista) {

    return ejercicio2(arbol, lista, 0);

}

/*
Funcion que dado el arbol y una lista de caracteres, comprueba por cada rama si existe
un camino donde sus caracteres (los del arbol) coinciden con los de la lista dada. Usa el
índice i para recorrer la lista de caracteres y se llama de forma recursiva para cada rama:
*/
bool ejercicio2(binary_tree * arbol, list lista, int i) {

	// Recursividad:
    if (arbol->tree_type == Binary_Tree) {

    	// Obtener la etiqueta del nodo padre
    	char * letra = (char*) list_get(&lista, i);
        char * label = (char*) binary_tree_label(arbol);

        // Rama izquierda y derecha del arbol dado:
        binary_tree * arbolIzquierdo = binary_tree_left(arbol);
        binary_tree * arbolDerecho = binary_tree_right(arbol);

        // Comparar el valor de la etiqueta obtenido con la de la lista:
        int compara = strcmp(label, letra);

        int indice = i + 1;
        return !compara && (ejercicio2(arbolIzquierdo, lista, indice) || ejercicio2(arbolDerecho, lista, indice));

    // Caso base: no es binario:
    } else {

        if (i == (lista.size - 1)) {

        	// Obtener la etiqueta del nodo
        	char * letra = (char*) list_get(&lista, i);
            char * label = (char*) binary_tree_label(arbol);

            // Comparar el valor de la etiqueta obtenido con la de la lista:
            int compara = strcmp(label, letra);

            return compara;

        } else {

            return false;

        }

    }

}
