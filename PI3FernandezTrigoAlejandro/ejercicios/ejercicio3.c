/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio3.h"
#include "ejercicio3iterativa.h"
#include "ejercicio3recursivaconmemoria.h"
#include "ejercicio3recursivasinmemoria.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 3 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
y en cada linea un formato n=numero, hace split y se queda con los numeros
que son devueltos en una lista:
*/
list leeDatosEjercicio3 (char * fichero) {

	char *tt[255];
	char limite[] = "=";
	list resultado = list_empty(int_type);
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		char *fila = (char*) iterable_next(&filas);
		pchar_split_text(fila, limite, tt);
		int numero = int_parse_s(tt[1]);
		list_add(&resultado, &numero);

	}

	return resultado;

}

/*
Funcion auxiliar para, dado una lista de integers devuelta por
la funcion de lectura, invocar a las funciones que resuelven el
ejercicio tantas veces como numeros tenga la lista de entrada:
*/
void funcionAuxiliarEjercicio3 (list lista) {

	int i = 0;
	long resultadoIterativo = 0L;
	long resultadoRecursivoConMemoria = 0L;
	long resultadoRecursivoSinMemoria = 0L;

	while (i < list_size(&lista)) {

		long numero = *(long*) list_get(&lista, i);

		resultadoIterativo = ejercicio3Iterativo(numero);
		//resultadoRecursivoSinMemoria = ejercicio3RecursivoConMemoria(numero);
		resultadoRecursivoConMemoria = ejercicio3RecursivoSinMemoria(numero);

		printf("Entero de entrada: ");
		printf("%ld\n", numero);
		printf("1. Resultado iterativo: ");
		printf("%ld\n", resultadoIterativo);
		printf("2. Resultado recursivo con memoria: ");
		printf("%ld\n", resultadoRecursivoConMemoria);
		printf("3. Resultado recursivo sin memoria: ");
		printf("%ld\n", resultadoRecursivoSinMemoria);
		printf("\n");
		i++;

	}

}
