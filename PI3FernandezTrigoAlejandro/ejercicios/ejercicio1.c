/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio1.h"
#include "ejercicio1recursiva.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 1 				 #################
// ###################################################################################
// ###################################################################################

// Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
// y en cada linea un nº n de numeros enteros, las filas del fichero representan las
// filas de una matriz cuadrada de orden n*n. Pasamos los numeros de las filas al metodo
// toMultiArray() de Miguel Toro para acceder a las posiciones con facilidad:
matrix leeDatosEjercicio1 (char * fichero) {

	list lista = list_empty(list_type);
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		char *fila = (char*) iterable_next(&filas);
		iterator miniFila = split_iterable_pchar(fila, " ");
		list miniLista = list_empty(int_type);

		while (iterable_has_next(&miniFila)) {

			char *numeroCaracter = (char*) iterable_next(&miniFila);
			int numeroEntero;
			int_type.parse(&numeroEntero, numeroCaracter);
			list_add(&miniLista, &numeroEntero);

		}

		list_add(&lista, &miniLista);

	}

	int i = 0;
	int posicion = 0;
	list dimension = *(list*) list_get(&lista, 0);

	int rango = list_size(&dimension);
	int array[rango * rango];

	while (i < lista.size) {

		int j = 0;
		list elementos = *(list*) list_get(&lista, i);

		while (j < elementos.size) {

			int elemento = *(int*) list_get(&elementos, j);
			array [posicion] = elemento;
			posicion++;
			j++;

		}

		j = 0;
		i++;

	}

	matrix resultado = matrix_of_array(array, rango, rango);

	return resultado;

}

// Funcion auxiliar para, dado una matriz leida por la funcion leeDatosEjercicio1(),
// llamar a la funcion recursiva que resuelve el ejercicio y formatear la salida
// acorde al fichero de salida de ejemplo proporcionado:
void funcionAuxiliarEjercicio1(matrix matriz) {

	char mem[2000];
	int dimension = matriz.nf;
	bool resultado = ejercicio1Recursivo(matriz);

	printf("Matriz de entrada de dimensión: %d * %d: %d\n", dimension, dimension, dimension * dimension);

	if (matriz.nf > 8) {

		printf("La matriz no se muestra debido al tamaño.");

	} else {

		// Método de Miguel Toro:
		matrix_print(matriz, mem);

	}

	printf("¿Es la matriz válida? --> %s\n", bool_tostring(&resultado, mem));
	printf("\n");

}

/*
// Método propio "a lo bestia":
int i, j;
for (i = 0; i < matriz.nf; i++) {
	for (j = 0; j < matriz.nc; j++) {

		printf("%d ", matrix_get(matriz,i,j));
		printf("\n");

	}

}
*/
