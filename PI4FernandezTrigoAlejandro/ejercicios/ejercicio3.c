/*
 *  	Analisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#include "ejercicio3.h"
#include "funcionesAuxiliares.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 3 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que lee el fichero de entrada que, por cada linea, un arbol n-ario
de tipo generico que se parsea y a�ade a la lista resultante:
*/
list leeDatosEjercicio3(char * fichero) {

	list listaArboles = list_empty(tree_type);
	memory_heap memoria1 = memory_heap_create();
	memory_heap memoria2 = memory_heap_create();
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		char * linea = (char*) iterable_next(&filas);
		// Descomentar para pasar a string
		// tree * arbol = tree_parse(linea, &memoria);
		tree * arbol = tree_map(tree_parse(linea, &memoria1), int_type, castearArbol, &memoria2);
		list_add(&listaArboles, arbol);

	}

	return listaArboles;

}

/*
Funcion que llama a las funciones encargadas de comprobar el predicado
para cada arbol de la lista devuelta por la lectura. Se recorre dicha lista
dos veces, una para para cada predicado, y se muestra por pantalla el arbol
de entrada a la vez que se usa el indice como parametro para la funcion que
resuelve el ejercicio:
*/
void funcionAuxiliarEjercicio3(list listaArboles) {

	char mem1[500];
	char mem2[500];
	char mem3[500];
	char mem4[500];

	int i = 0;
	printf("\n");
	printf("=========================== Predicado par ===========================\n");
	while (i < listaArboles.size) {

		tree * arbol = list_get(&listaArboles, i);
		list resultadoPar = ejercicioPredicadoPar(listaArboles, i);

		printf("Arbol de entrada: %s\n", tree_tostring(arbol, mem1));
		printf("�Cumple el predicado? %s\n", list_tostring(&resultadoPar, mem2));
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		i++;

	}
	printf("\n");

	int j = 0;
	printf("========================== Predicado primo ==========================\n");
	while (j < listaArboles.size) {

		tree * arbol = list_get(&listaArboles, j);
		list resultadoPrimo = ejercicioPredicadoPrimo(listaArboles, j);

		printf("Arbol de entrada: %s\n", tree_tostring(arbol, mem3));
		printf("�Cumple el predicado? %s\n", list_tostring(&resultadoPrimo, mem4));
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		j++;

	}
	printf("\n");

}

/*
Llamada opaca al usuario de la comprobacion del predicado par para una lista de arboles,
dado dicha lista y el indice que corresponde al arbol que hay que leer, se le pasan la
lista resultante y dos listas auxiliares:
*/
list ejercicioPredicadoPar(list arboles, int arbol) {

	list niveles = list_empty(tree_type);
	list resultado = list_empty(bool_type);
	list booleanos = list_empty(bool_type);

	return funcionAuxiliarPredicadoPar(arboles, resultado, niveles, booleanos, arbol, 0);

}

/*
Llamada opaca al usuario de la comprobacion del predicado primo para una lista de arboles,
dado dicha lista y el indice que corresponde al arbol que hay que leer, se le pasan la
lista resultante y dos listas auxiliares:
*/
list ejercicioPredicadoPrimo(list arboles, int arbol) {

	list niveles = list_empty(tree_type);
	list resultado = list_empty(bool_type);
	list booleanos = list_empty(bool_type);

	return funcionAuxiliarPredicadoPrimo(arboles, resultado, niveles, booleanos, arbol, 0);

}

/*
Funcion que dado la lista de arboles, las listas auxiliares y el indice correspondiente al
arbol a leer, comprueba para cada nivel si toodos los elementos del nivel verifican el
predicado esPar en ese nivel y devuelve una lista de tantos elementos como niveles tenga
el arbol con valores booleanos correspondientes a la verificacion o no del predicado en ese
nivel. Para ello hace uso de una funcion auxiliar llamada predicadoPar():
*/
list funcionAuxiliarPredicadoPar(
		list arboles,
		list resultado,
		list nivel,
		list lista,
		int arbol,
		int i) {

	tree * arbolito = list_get(&arboles, arbol);
	int altura = calculaAlturaArbol(arbolito);

	if (i < altura) {

		// Obtener el nivel:
		nivel = calculaNivelArbol(arbolito, i);

		// A�adir a la lista el booleano correspondiente a la
		// llamada de la funcion que comprueba el predicado:
		bool booleano = predicadoPar(nivel, true, 0);
		list_add(&resultado, &booleano);

		// Recursion: siguente nivel:
		int indice = i + 1;
		resultado = funcionAuxiliarPredicadoPar(arboles, resultado, nivel, lista, arbol, indice);

	}

	return resultado;

}

/*
Funcion que dado la lista de arboles, las listas auxiliares y el indice correspondiente al
arbol a leer, comprueba para cada nivel si toodos los elementos del nivel verifican el
predicado esPrimo en ese nivel y devuelve una lista de tantos elementos como niveles tenga
el arbol con valores booleanos correspondientes a la verificacion o no del predicado en ese
nivel. Para ello hace uso de una funcion auxiliar llamada predicadoPrimo():
*/
list funcionAuxiliarPredicadoPrimo(
		list arboles,
		list resultado,
		list nivel,
		list lista,
		int arbol,
		int i) {

	tree * arbolito = list_get(&arboles, arbol);
	int altura = calculaAlturaArbol(arbolito);

	if (i < altura) {

		// Obtener el nivel:
		nivel = calculaNivelArbol(arbolito, i);

		// A�adir a la lista el booleano correspondiente a la
		// llamada de la funcion que comprueba el predicado:
		bool booleano = predicadoPrimo(nivel, true, 0);
		list_add(&resultado, &booleano);

		// Recursion: siguente nivel:
		int indice = i + 1;
		resultado = funcionAuxiliarPredicadoPrimo(arboles, resultado, nivel, lista, arbol, indice);

	}

	return resultado;

}


// Predicado 1: predicado sobre enteros que devuelve cierto cuando el entero es par.
/*
Funcion que comprueba, dado un nivel de un arbol n-ario, de forma recursiva, que todos
los elementos del nivel verifican el predicado esPar usando la libreria Math2 y devuelve
el resultado como booleano:
*/
bool predicadoPar(
		list arboles,
		bool resultado,
		int i) {

	if (i < arboles.size) {

		tree * arbol = list_get(&arboles, i);

		if (arbol->tree_type != Empty_Tree) {

			tree * arbol = list_get(&arboles, i);
			int label = *(int*) tree_label(arbol);
			resultado = resultado && es_par(label);

		}

		// Recursion:
		int indice = i + 1;
		resultado = predicadoPar(arboles, resultado, indice);

	// Caso base:
	} else {

		return resultado;

	}

	return resultado;

}

// Predicado 2: predicado sobre enteros que devuelve cierto cuando el entero es primo.
/*
Funcion que comprueba, dado un nivel de un arbol n-ario, de forma recursiva, que todos
los elementos del nivel verifican el predicado esPrimo usando la libreria Math2 y devuelve
el resultado como booleano:
*/
bool predicadoPrimo(
		list arboles,
		bool resultado,
		int i) {

	if (i < arboles.size) {

		tree * arbol = list_get(&arboles, i);

		if (arbol->tree_type != Empty_Tree) {

			int label = *(int*) tree_label(arbol);
			resultado = resultado && es_primo(label);

		}

		// Recursion:
		int indice = i + 1;
		resultado = predicadoPrimo(arboles, resultado, indice);

	// Caso base:
	} else {

		return resultado;

	}

	return resultado;

}
