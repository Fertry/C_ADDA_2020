/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio2.h"
#include "ejercicio2recursiva.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 2 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
y en cada linea nºs separados por comas, devuelve una lista de listas donde
cada lista interna representa un conjunto de números que se pasan al ejercicio:
*/
list leeDatosEjercicio2 (char * fichero) {

    iterator lista = file_iterable_pchar(fichero);
    list miniLista = list_empty(int_type);
    list resultado = list_empty(list_type);

    while (iterable_has_next(&lista)) {

        miniLista = list_empty(int_type);
        char *fila = (char*) iterable_next(&lista);
        iterator miniFila = text_to_iterable_pchar(fila, ", ");

        while (iterable_has_next(&miniFila)) {

            char *numero = (char*) iterable_next(&miniFila);
            int numeroEntero = int_parse_s(numero);
            list_add(&miniLista, &numeroEntero);

        }

        list_add(&resultado, &miniLista);

    }

    return resultado;

}

/*
Funcion auxiliar para, dado una lista de listas de integers devuelta por
la función de lectura, invocar a la funcion recursiva que resuelve el
ejercicio tantas veces como filas tenga el fichero de entrada:
*/
void funcionAuxiliarEjercicio2 (list lista) {

	int i = 0;
	char mem[2000];

	while (i < list_size(&lista)) {

		list numeros = *(list*) list_get(&lista, i);

		smax resultado = ejercicio2Recursivo(numeros);
		list subsecuencia = list_sublist(&numeros, resultado.li, resultado.ls);

		printf("Lista de entrada: ");
		printf("%s\n", list_tostring(&numeros, mem));
		printf("Subsecuencia de suma mayor en intervalo: [%d,%d)\n", resultado.li, resultado.ls);
		printf("Subsecuencia: %s\n", list_tostring(&subsecuencia, mem));
		printf("Suma obtenida: %d\n", resultado.suma);
		printf("\n");
		i++;

	}

}
