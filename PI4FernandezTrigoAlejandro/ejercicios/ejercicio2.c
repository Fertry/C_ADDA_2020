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

	list listaArboles = list_empty(binary_tree_type);
	iterator filas = file_iterable_pchar(fichero);
	memory_heap memoria = memory_heap_create();

	while (iterable_has_next(&filas)) {

		char * a = (char*) iterable_next(&filas);
		char b[] = "#";
		char * c[200];
		pchar_split_text(a, b, c);
		binary_tree * arbol = binary_tree_parse(c[0], &memoria);
		list_add(&listaArboles, arbol);

	}

	return listaArboles;

}

/*
Funcion que lee...
*/
list leeDatosEjercicio2Listas(char * fichero) {

	list listaFinal = list_empty(list_type);
	iterator f = file_iterable_pchar(fichero);
	while (iterable_has_next(&f)) {
		char *s = (char*) iterable_next(&f);
		char d[] = "#";
		char *tt[80];
		pchar_split_text(s, d, tt);
		char *inicio[50];
		char *fin[50];
		char p1[] = "[";
		char p2[] = "]";
		pchar_split_text(tt[1], p1, inicio);
		pchar_split_text(inicio[0], p2, fin);
		iterator f1 = text_to_iterable_pchar(fin[0], ",");
		list listaCad = list_empty(pchar_type);
		while (iterable_has_next(&f1)) {
			char *letra = (char*) iterable_next(&f1);
			list_add(&listaCad, letra);
		}
		list_add(&listaFinal, &listaCad);
	}
	return listaFinal;

}

/*
Funcion que lee...
*/

/*
void funcionAuxiliarEjercicio2(list listaArboles, list listaLetras) {

	int i = 0;
	int j = 0;
	char mem[500];
	char mem2[500];

	while (i < listaArboles.size) {

		while (j < listaLetras.size) {

			binary_tree * arbol = (binary_tree*) list_get(&listaArboles, i);
			list miniLista = *(list*)list_get(&listaLetras, i);
			printf("Arbol de entrada: %s", binary_tree_tostring(arbol, mem));
			printf("Lista de entrada: %s", list_tostring(&miniLista, mem2));
			printf("\n");
			i++;
			j++;

		}

	}

}
*/

/*
	private static Boolean ejercicio2Privado(Tuple2<BinaryTree<String>, List<String>> conjunto) {

		BinaryTree<String> arbol = conjunto.getV1();
		List<String> lista = conjunto.getV2();

		return ejercicio2(arbol, lista, 0);

	}


	private static Boolean ejercicio2(BinaryTree<String> arbol, List<String> lista, Integer i) {

		if (arbol.isBinary()) {

			return arbol.getLabel().equals(lista.get(i)) && (ejercicio2(arbol.getLeft(), lista, i +1) || ejercicio2(arbol.getRight(), lista, i + 1));

		} else {

			if (i == lista.size() - 1) {

				return arbol.getLabel().equals(lista.get(i));

			} else {

				return false;

			}

		}

	}
 */
