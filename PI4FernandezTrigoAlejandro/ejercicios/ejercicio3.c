/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#include "ejercicio3.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 3 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que lee...
*/
list leeDatosEjercicio3(char * fichero) {

	memory_heap memoria = memory_heap_create();
	iterator filas = file_iterable_pchar(fichero);
	list listaArboles = list_empty(tree_type);

	while (iterable_has_next(&filas)) {

		char * linea = (char*) iterable_next(&filas);
		tree * arbol = tree_parse(linea, &memoria);
		list_add(&listaArboles, arbol);

	}

	return listaArboles;

}

/*
Funcion que lee...
*/
void funcionAuxiliarEjercicio3(list listaArboles) {

	int i = 0;
	char mem[500];

	while (i < listaArboles.size) {

		tree * arbol = list_get(&listaArboles, i);
		printf("Arbol de entrada: ");
		printf("%s", tree_tostring(arbol, mem));
		printf("\n");
		i++;

	}

}
