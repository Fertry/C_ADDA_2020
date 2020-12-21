/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio1recursiva.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 1 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion privada recursiva que se llama a si misma para reducir la matriz a la par que
se comprueba si sus extremos siguen siendo distintos o no mediante el uso
de HashSets para evitar emplear excesivos booleanos. Se llama tantas veces como sea
necesario hasta que la matriz sea 2x2 o no se cumpla el requerimiento de que
sus cuatro esquinas difieran:
* Recursividad: 2 casos base + 1 caso recursivo multiple
*/
bool ejercicio1RecursivoC(matrix matriz, int fila, int columna, int dimension) {

	char mem[2000];
	bool resultado = false;

	if (dimension == 2) {

		// Caso base:
		int A00 = matrix_get(matriz, 0, 0);
		int A01 = matrix_get(matriz, 0, matriz.nf - 1);
		int A10 = matrix_get(matriz, matriz.nf - 1, 0);
		int A11 = matrix_get(matriz, matriz.nf - 1, matriz.nf - 1);

		set extremos1 = set_empty(int_type);

		set_add(&extremos1, &A00);		// [0][0]
		set_add(&extremos1, &A01);		// [0][1]
		set_add(&extremos1, &A10);		// [1][0]
		set_add(&extremos1, &A11);		// [1][1]

		if (set_size(&extremos1) == 4) {

			resultado = true;

		} else {

			resultado = false;

		}

	} else {

		// Caso recursivo:
		int A00 = matrix_get(matriz, 0, 0);
		int A01 = matrix_get(matriz, 0, matriz.nf - 1);
		int A10 = matrix_get(matriz, matriz.nf - 1, 0);
		int A11 = matrix_get(matriz, matriz.nf - 1, matriz.nf - 1);

		set extremos2 = set_empty(int_type);

		set_add(&extremos2, &A00);		// [0][0]
		set_add(&extremos2, &A01);		// [0][1]
		set_add(&extremos2, &A10);		// [1][0]
		set_add(&extremos2, &A11);		// [1][1]

		if (set_size(&extremos2) == 4) {

			bool matriz1 = ejercicio1RecursivoC(matriz, fila, columna, (dimension / 2));
			bool matriz2 = ejercicio1RecursivoC(matriz, fila, (columna + dimension / 2), (dimension / 2));
			bool matriz3 = ejercicio1RecursivoC(matriz, (fila + dimension / 2), columna, (dimension / 2));
			bool matriz4 = ejercicio1RecursivoC(matriz, (fila + dimension / 2), (columna + dimension / 2), (dimension / 2));

			resultado = matriz1 && matriz2 && matriz3 && matriz4;

		} else {

			resultado = false;

		}

	}

	return resultado;

}
