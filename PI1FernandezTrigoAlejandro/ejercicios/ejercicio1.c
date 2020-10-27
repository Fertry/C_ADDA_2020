/*
 * ejercicio1.c
 *
 *  	Análisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernández Trigo
 *      Práctica Individual 1
 *
 */

#include "ejercicio1.h"

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 1                         #################
//###################################################################################
//###################################################################################

// Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
// y en cada linea numeros enteros separados por comas, devuelve una lista de listas
// formadas por los numeros del fichero:
list leeDatosEjercicio1 (char * fichero) {

    iterator lista = file_iterable_pchar(fichero);
    list miniLista = list_empty(int_type);
    list resultado = list_empty(list_type);

    while (iterable_has_next(&lista)) {

        miniLista = list_empty(int_type);
        char *fila = (char*) iterable_next(&lista);
        iterator miniFila = split_iterable_pchar(fila, ", ");

        while (iterable_has_next(&miniFila)) {

            char *numero = (char*) iterable_next(&miniFila);
            int numeroEntero = int_parse_s(numero);
            list_add(&miniLista, &numeroEntero);

        }

        list_add(&resultado, &miniLista);
    }

    return resultado;

}

// Dada una lista de listas de enteros, comprueba que elementos son primos
// y los devuelve, todos, en una lista nueva como resultado:
list compruebaSiEsPrimo (list lista) {

	int i = 0;
	int j = 0;
	list resultado = list_empty(int_type);

	while (i < list_size(&lista)) {
		list listaNumeros = *(list*) list_get(&lista, i);

		while (j < list_size(list_get(&lista, i))) {

			int numero = *(int*) list_get(&listaNumeros, j);
			if (es_primo(numero)) {

				list_add(&resultado, &numero);

			}

			j++;

		}

		j = 0;
		i++;

	}

	return resultado;

}
