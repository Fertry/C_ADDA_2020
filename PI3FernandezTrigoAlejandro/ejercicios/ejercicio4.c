/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio4.h"
#include "ejercicio4iterativa.h"
#include "ejercicio4recursivaconmemoria.h"
#include "ejercicio4recursivasinmemoria.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 4 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
y en cada linea dos enteros separados por coma, devuelve una lista de listas
de enteros donde cada minilista representa un par de enteros:
*/
list leeDatosEjercicio4 (char * fichero) {

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

/*
Funcion auxiliar para, dado una lista de listas de integers devuelta por
la funcion de lectura, invocar a las funciones que resuelven el
ejercicio tantas veces como pares de numeros tenga la lista de entrada:
*/
void funcionAuxiliarEjercicio4 (list lista) {

	int i = 0;
	int resultadoIterativo = 0;
	int resultadoRecursivoConMemoria = 0;
	int resultadoRecursivoSinMemoria = 0;

	while (i < list_size(&lista)) {

		list numeros = *(list*) list_get(&lista, i);
		int a = *(int*) list_get(&numeros, 0);
		int b = *(int*) list_get(&numeros, 1);

		//resultadoIterativo = ejercicio4Iterativo(a, b);
		resultadoRecursivoSinMemoria = ejercicio4RecursivoSinMemoria(a, b);
		//resultadoRecursivoConMemoria = ejercicio4RecursivoConMemoria(a, b);

		printf("Par de entrada: (a,b) = (%d,%d)\n", a, b);
		printf("1. Resultado iterativo: ");
		printf("%d\n", resultadoIterativo);
		printf("2. Resultado recursivo con memoria: ");
		printf("%d\n", resultadoRecursivoConMemoria);
		printf("3. Resultado recursivo sin memoria: ");
		printf("%d\n", resultadoRecursivoSinMemoria);
		i++;

	}

}
