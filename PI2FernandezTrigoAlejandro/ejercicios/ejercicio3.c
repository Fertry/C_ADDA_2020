/*
 * ejercicio3.c
 *
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 2
 *
 */

#include "ejercicio3.h"
#include "ejercicio3iterativa.h"
#include "ejercicio3recursivafinal.h"
#include "ejercicio3recursivanofinal.h"

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 3                         #################
//###################################################################################
//###################################################################################

// Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
// y en cada linea dos integers (+ y -) separados por una ",", devuelve una lista de listas de
// integers donde cada lista contiene cada par de integers:
list leeDatosEjercicio3 (char * fichero) {

    iterator lista = file_iterable_pchar(fichero);
    list miniLista = list_empty(int_type);
    list resultado = list_empty(list_type);

    while (iterable_has_next(&lista)) {

        miniLista = list_empty(int_type);
        char *fila = (char*) iterable_next(&lista);
        iterator miniFila = text_to_iterable_pchar(fila, ",");

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
// la función de lectura, invocar a la función elevaA() tantas veces
// como pares de integers recibamos por fichero:
void funcionAuxiliarEjercicio3 (list lista) {

	int n;
	int i = 0;
	long exponente;
	char mem[500];
	long resultadoIterativo;
	long resultadoRecursivoFinal;
	long resultadoRecursivoNoFinal;

	while (i < list_size(&lista)) {

		list parDeNumeros = *(list*) list_get(&lista, i);
		exponente = *(long*) list_get(&parDeNumeros, 0);
		n = *(int*) list_get(&parDeNumeros, 1);

		resultadoIterativo = elevaAIterativo(exponente, n);
		resultadoRecursivoFinal = elevaARecursivoFinal(exponente, n);
		resultadoRecursivoNoFinal = elevaARecursivoNoFinal(exponente, n);

		printf("%s\n", long_tostring(&exponente, mem));
		printf("%s\n", int_tostring(&n, mem));
		printf("1. Iterativo: %ld\n", resultadoIterativo);
		printf("2. Recursivo final: %ld\n", resultadoRecursivoFinal);
		printf("3. Recursivo no final: %ld\n", resultadoRecursivoNoFinal);
		printf("\n");
		i++;

	}

}
