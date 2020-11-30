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

	matrix resultado;

	/*
    int fila = 0;
    int columna = 0;
    int dimension = 0;
	iterator lista = file_iterable_pchar(fichero);

    while (iterable_has_next(&lista)) {

    	char *fila = (char*) iterable_next(&lista);
    	iterator miniFila = split_iterable_pchar(fila, " ");
        int miniLista [];

        while (iterable_has_next(&miniFila)) {

            char *numeros = (char*) iterable_next(&miniFila);
            int numero = int_of_pchar(numeros);
            list_add(&miniLista, &numero);

        }

        while (columna < 0) {


        }

    	int rango = sizeof(list_get(&fila, 0));


    }

    //resultado = matrix_of_array(int * NULL, rango, rango);
	*/

    return resultado;

}

// Funcion auxiliar para, dado una matriz leida por la funcion leeDatosEjercicio1(),
// llamar a la funcion recursiva que resuelve el ejercicio y formatear la salida
// acorde al fichero de salida de ejemplo proporcionado:
void funcionAuxiliarEjercicio1(matrix matriz) {


}

// Funcion privada para mostrar una matriz por pantalla al pasarse esta
// por parametro siempre y cuando la dimension no exceda 16:
void muestraMatrizPorPantalla(matrix matriz) {

	int fila;
	int columna;

	if (matriz.__n > 16) {

		printf("La matriz no se muestra debido al tamaño.\n");

	} else {

		for (fila = 0; fila < matriz.__n; fila++) {
			for (columna = 0; columna < matriz.__n; columna++) {

				printf(matriz [fila][columna]);

				if (columna != matriz.__n - 1) {

					printf(" ");

				}

			}

			printf("");

		}

	}

}
