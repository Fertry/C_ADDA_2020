/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#include "ejercicio4.h"

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
	memory_heap memoria = memory_heap_create();
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		char * linea = (char*) iterable_next(&filas);
		tree * arbol = tree_parse(linea, &memoria);
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
	char mem[500];

	printf("\n");
	while (i < listaArboles.size) {

		tree * arbol = list_get(&listaArboles, i);

		printf("Arbol de entrada: %s\n", tree_tostring(arbol, mem));
		printf("Hash table de salida: \n");
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
/*
hash_table ejercicio4Interno(list arboles, int arbol) {

	hash_table mapa = hash_table_empty(int_pair_type, list_type);

	return ejercicio4(arboles, mapa, arbol, 0);

}
*/

/*
Funcion que dado la lista de arboles, el mapa resultante de tipo entero y lista de string
junto con un indice y el arbol a leer, genera un mapa cuyas claves representan los niveles
del arbol y sus valores son listas de nodos del mismo nivel que tiene un nº par de hijos.
Para ello se emplea la funcion auxiliar predicado() que comprueba la validez del predicado
(nodo binario) para cada nivel dado:
*/
/*
hash_table ejercicio4(
		list arboles,
		hash_table resultado,
		int arbol,
		int i) {

	// Recursion:
	tree * arbolito = list_get(&arboles, arbol);
	list lista = tree_to_list(arbolito);

	if (i < lista.size + 1) {

		// Lista a añadir como valor del mapa para la clave i:
		list lista = list_empty(string_type);

		// Llamada a la funcion auxiliar predicado() con el nivel:
		list listaAuxiliar = list_empty(string_type);
		list nivel = calculaNivelArbol(arbolito, lista);
		list listaPredicado = predicado(nivel, listaAuxiliar, 0);
		list_add(&lista, &listaPredicado);

		// Añadir al mapa la clave con su valor:
		hash_table_put(&resultado, &i, &lista);

		// Vaciar la lista:
		lista = list_empty(string_type);

		// Llamada recursiva al ejercicio incrementando el nivel:
		resultado = ejercicio4(arboles, resultado, arbol, i + 1);

	// Caso base:
	} else {

		return resultado;
	}

	return resultado;

}
*/

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
/*
list predicado(
		list listaEntrada,
		list listaSalida,
		int i) {

	if (i < listaEntrada.size) {

		// Caso base:
		tree * arbol = list_get(&listaEntrada, i);
		tree * arbolVacio = tree_empty(tree_type);
		if (!tree_equals(arbol, arbolVacio) && arbol.num_children != 0 && esPar(arbol.num_children)) {

			// Añadir a la lista:
			int label = *(int*) tree_label(arbol);
			list_add(&listaSalida, &label);

		}

		// Recursion:
		listaSalida = predicado(listaEntrada, listaSalida, i + 1);

	// Caso base:
	} else {

		return listaSalida;
	}

	return listaSalida;

}
*/

/*
Funcion auxiliar para calcular el nivel de un arbol
dado como parametro el arbol y la lista correspondiente
al nivel 0 del arbol:
*/
/*
list calculaNivelArbol(tree * arbol, list nivelCero) {

	int size = list_size(&nivelCero);
	list resultado = list_empty(tree_type);

	for (int j = 0; j < size; j++) {

		int numeroHijos = tree_child_number(arbol);

		for (int hijo = 0; hijo < numeroHijos; hijo++) {

			list_add(&resultado, tree_get_child(arbol, hijo));

		}

	}

	return resultado;

}
*/
