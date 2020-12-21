/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio4recursivaconmemoria.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 4 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que llame al ejercicio recursivo pasando como parametro
el HashTable que se emplea como memoria para actuar de forma opaca al usuario:
*/
int ejercicio4RecursivoConMemoria (int numeroA, int numeroB) {

	// Empleamos pair_type para "encapsular" los dos numeros que se reciben como parametros:
	hash_table memoria = hash_table_empty(int_pair_type, int_type);

	return ejercicio4RecursivoConMemoriaInterno(numeroA, numeroB, &memoria);

}

/*
Funcion que dados dos enteros a, b, calcule la siguiente sucesion numerica en funcion
de tres casos bases y uno recursivo que se llama a si mismo tantas veces como sea necesario
haciendo uso de memoria con un HashTable para evitar repetir calculos y devuelve el
resultado en forma de entero:
* Recursividad: 3 casos base y uno recursivo
*/
int ejercicio4RecursivoConMemoriaInterno (int numeroA, int numeroB, hash_table * memoria) {

	int resultado;
	int_pair tupla;
	tupla.a = numeroA;
	tupla.b = numeroB;

	// Casos bases:
	if (hash_table_contains(memoria, &tupla)) {

		resultado = *(int*) hash_table_get(memoria, &tupla);

	} else if (numeroA < 2 && numeroB < 2) {

		resultado = (numeroA + pow(numeroB, 2));
		hash_table_put(memoria, &tupla, &resultado);

	} else if (numeroA < 2 || numeroB < 2) {

		resultado = (pow(numeroA, 2) + numeroB);
		hash_table_put(memoria, &tupla, &resultado);

	// Caso recursivo:
	} else {

		resultado = ejercicio4RecursivoConMemoriaInterno((numeroA / 2), (numeroB - 1), memoria) +
					ejercicio4RecursivoConMemoriaInterno((numeroA / 3), (numeroB - 2), memoria) +
					ejercicio4RecursivoConMemoriaInterno((numeroA - 2), (numeroB / 4), memoria);

		hash_table_put(memoria, &tupla, &resultado);

	}

	return resultado;

}
