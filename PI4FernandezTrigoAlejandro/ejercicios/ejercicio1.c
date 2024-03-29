/*
 *  	Analisis y Dise�o de Datos y Algoritmos - 2020
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
Funcion que lee el fichero de entrada que, por cada linea, representa un arbol binario
de tipo entero y devuelve una lista de BinaryTree tras parsearlos:
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
Funcion auxiliar para recorrer la lista de arboles y por cada uno, mostrar dicho arbol
por pantalla y llamar a la funcion que resuelve el ejercicio pasandole como argumento
dicho arbol:
*/
void funcionAuxiliarEjercicio1(list listaArboles) {

	int i = 0;
	char mem1[500];
	char mem2[500];

	printf("\n");
	while (i < listaArboles.size) {

		binary_tree * arbol = (binary_tree*) list_get(&listaArboles, i);
		bool res = ejercicio1(arbol);

		printf("Arbol de entrada: %s\n", binary_tree_tostring(arbol, mem1));
		printf("�Cumple el predicado?: %s\n", bool_tostring(&res, mem2));
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		i++;

	}
	printf("\n");

}

/*
Funcion que dado un arbol binario suma las componentes de sus hijos
y devuelve como booleano el resultado, siendo este true cuando la suma
de sus valores sea igual a la del padre y false en caso contrario. Para
ello se llama recursivamente a la funcion una vez por cada rama:
*/
bool ejercicio1(binary_tree * arbol) {

	if (arbol->tree_type == Binary_Tree) {

		// Obtener el valor de las etiquetas de los nodos:
		char * label = (char*) binary_tree_label(arbol);
		binary_tree * arbolIzquierdo = binary_tree_left(arbol);
		char * izquierda = (char*) binary_tree_label(arbolIzquierdo);
		binary_tree * arbolDerecho = binary_tree_right(arbol);
		char * derecha = (char*) binary_tree_label(arbolDerecho);

		// Castear los char a enteros para operar:
		int labelEntero = int_parse_s(label);
		int izquierdaEntero = int_parse_s(izquierda);
		int derechaEntero = int_parse_s(derecha);

		bool iguales = (izquierdaEntero + derechaEntero) == labelEntero;

		return iguales && ejercicio1(arbolIzquierdo) && ejercicio1(arbolDerecho);

	} else {

		return true;

	}

}
