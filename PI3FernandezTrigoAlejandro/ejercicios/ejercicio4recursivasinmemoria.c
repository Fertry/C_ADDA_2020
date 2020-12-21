/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio4recursivasinmemoria.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 4 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que dados dos enteros a, b, calcule la siguiente sucesion numerica en funcion
de dos casos bases y uno recursivo que se llama a si mismo tantas veces como sea necesario
y devuelve el resultado en forma de entero:
* Recursividad: 2 casos base y uno recursivo
*/
int ejercicio4RecursivoSinMemoria (int numeroA, int numeroB) {

	int resultado;

	// Casos bases:
	if (numeroA < 2 && numeroB < 2) {

		resultado = (numeroA + pow(numeroB, 2));

	} else if (numeroA < 2 || numeroB < 2) {

		resultado = (pow(numeroA, 2) + numeroB);

	// Caso recursivo:
	} else {

		resultado = ejercicio4RecursivoSinMemoria((numeroA / 2), (numeroB - 1)) +
					ejercicio4RecursivoSinMemoria((numeroA / 3), (numeroB - 2)) +
					ejercicio4RecursivoSinMemoria((numeroA - 2), (numeroB / 4));

	}

	return resultado;

}
