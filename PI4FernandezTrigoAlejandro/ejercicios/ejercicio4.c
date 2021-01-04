/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#include "ejercicio4.h"
#include "funcionesAuxiliares.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 4 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que lee el fichero de entrada que, por cada linea, un arbol n-ario
de tipo generico que se parsea y añade a la lista resultante:
*/
list leeDatosEjercicio4(char * fichero) {

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
Funcion auxiliar para recorrer la lista de arboles y por cada uno, mostrar dicho arbol
por pantalla y llamar a la funcion que resuelve el ejercicio pasandole como argumento
la lista y el indice correspondiente al arbol a leer:
*/
void funcionAuxiliarEjercicio4(list listaArboles) {

	int i = 0;
	char mem1[500];
	char mem2[500];

	printf("\n");
	while (i < listaArboles.size) {

		tree * arbol = list_get(&listaArboles, i);
		hash_table resultado = ejercicio4Interno(listaArboles, i);

		printf("Arbol de entrada: %s\n", tree_tostring(arbol, mem1));
		printf("Hash table de salida: %s\n", hash_table_tostring(&resultado, mem2));
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		i++;

	}
	printf("\n");

}

/*
Funcion que llama de forma opaca al usuario a la funcion que resuelve el ejercicio
pasandole a esta como parametros la lista de arboles y el indice que indica el arbol
a leer:
*/
hash_table ejercicio4Interno(list arboles, int arbol) {

	hash_table mapa = hash_table_empty(int_type, list_type);

	return * ejercicio4(arboles, &mapa, arbol, 0);

}

/*
Funcion que dado la lista de arboles, el mapa resultante de tipo entero y lista de string
junto con un indice y el arbol a leer, genera un mapa cuyas claves representan los niveles
del arbol y sus valores son listas de nodos del mismo nivel que tiene un nº par de hijos.
Para ello se emplea la funcion auxiliar predicado() que comprueba la validez del predicado
(nodo binario) para cada nivel dado:
*/
hash_table * ejercicio4(
		list arboles,
		hash_table * resultado,
		int arbol,
		int i) {

	// Recursion:
	tree * arbolito = list_get(&arboles, arbol);
	int altura = calculaAlturaArbol(arbolito);

	if (i < altura) {

		// Lista a añadir como valor del mapa para la clave i:
		list lista = list_empty(int_type);

		// Llamada a la funcion auxiliar predicado() con el nivel:
		list listaAuxiliar = list_empty(int_type);
		list nivel = calculaNivelArbol(arbolito, i);
		list listaPredicado = predicado(nivel, listaAuxiliar, 0);

		// Añadir los elementos de la lista de salida de predicado()
		// a la lista resultante que se añade luego al hash_table:
		for (int j = 0; j < listaPredicado.size; j++) {

			int numero = *(int*) list_get(&listaPredicado, j);
			list_add(&lista, &numero);

		}

		// Añadir al mapa la clave con su valor:
		hash_table_put(resultado, &i, &lista);

		// Vaciar la lista:
		lista = list_empty(int_type);

		// Llamada recursiva al ejercicio incrementando el nivel:
		int indice = i + 1;
		resultado = ejercicio4(arboles, resultado, arbol, indice);

	// Caso base:
	} else {

		return resultado;
	}

	return resultado;

}

/*
Funcion auxiliar que dado una lista de entrada representando a un nivel
del arbol, un indice y una lista vacia de resultado, devuelve la lista
de salida conteniendo los elementos que verifican el predicado: comprueba
para los elementos del nivel; primero que no esten vacios, que su nº de
hijos no sea cero y que dicho nº de hijos sea un nº par. Si esto se
verifica, procedemos a añadir el valor de su etiquita (label) a la lista
y llamamos recursivamente a la funcion para leer el siguente elemento
del nivel si lo hay:
*/
list predicado(
		list listaEntrada,
		list listaSalida,
		int i) {

	if (i < listaEntrada.size) {

		// Caso base:
		tree * arbol = list_get(&listaEntrada, i);
		int numeroHijos = arbol->num_children;

		if ((arbol->tree_type != Empty_Tree) && numeroHijos != 0 && es_par(numeroHijos)) {

			// Añadir a la lista:
			int label = *(int*) tree_label(arbol);
			list_add(&listaSalida, &label);

		}

		// Recursion:
		int indice = i + 1;
		listaSalida = predicado(listaEntrada, listaSalida, indice);

	// Caso base:
	} else {

		return listaSalida;
	}

	return listaSalida;

}
