/*
 * ejercicio3.c
 *
 *  	Análisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernández Trigo
 *      Práctica Individual 2
 *
 */

#include "ejercicio3.h"

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
// la función de lectura, invocar a la función elevaA() tantas veces
// como pares de integers recibamos por fichero:
void funcionAuxiliarEjercicio3 (list lista) {

	//TO-DO

}
