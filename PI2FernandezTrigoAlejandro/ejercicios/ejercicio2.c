/*
 * ejercicio2.c
 *
 *  	Análisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernández Trigo
 *      Práctica Individual 2
 *
 */

#include "ejercicio2.h"
#include "ejercicio2iterativa.h"
#include "ejercicio2recursivafinal.h"

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 2                         #################
//###################################################################################
//###################################################################################

// Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
// y en cada linea dos integers separados por una ",", devuelve una lista de listas de integers
// donde cada lista contiene cada par de integers:
list leeDatosEjercicio2 (char * fichero) {

    iterator lista = file_iterable_pchar(fichero);
    list miniLista = list_empty(int_type);
    list resultado = list_empty(list_type);

    while (iterable_has_next(&lista)) {

        miniLista = list_empty(int_type);
        char *fila = (char*) iterable_next(&lista);
        iterator miniFila = split_iterable_pchar(fila, ",");

        while (iterable_has_next(&miniFila)) {

            char *numero = (char*) iterable_next(&miniFila);
            int numeroEntero = int_parse_s(numero);
            list_add(&miniLista, &numeroEntero);

        }

        list_add(&resultado, &miniLista);
    }

    return resultado;

}

// Funcion auxiliar para, dado una lista de listas de integers devuelta por
// la función de lectura, invocar a la función esMultiplo() tantas veces
// como pares de integers recibamos por fichero:
void funcionAuxiliarEjercicio2 (list lista) {

	int i = 0;
	int numero1;
	int numero2;
	char mem[500];
	bool resultadoIterativo;
	bool resultadoRecursivoFinal;

	while (i < list_size(&lista)) {

		list parDeNumeros = *(list*) list_get(&lista, i);
		numero1 = *(int*) list_get(&parDeNumeros, 0);
		numero2 = *(int*) list_get(&parDeNumeros, 1);

		resultadoIterativo = esMultiploIterativo(numero1, numero2);
		resultadoRecursivoFinal = esMultiploRecursivoFinal(numero1, numero2);

		printf("%s\n", int_tostring(&numero1, mem));
		printf("%s\n", int_tostring(&numero2, mem));
		printf("1. Iterativo: %d\n", resultadoIterativo);
		printf("2. Recursivo final: %d\n", resultadoRecursivoFinal);
		printf("\n");
		i++;

	}

}
