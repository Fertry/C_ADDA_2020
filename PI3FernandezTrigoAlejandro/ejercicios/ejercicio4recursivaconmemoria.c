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
long ejercicio4RecursivoConMemoria (int numeroA, int numeroB) {

	// Empleamos Tuple2 para "encapsular" los dos numeros que se reciben como parametros:
	hash_table memoria = hash_table_empty(list_type, long_type);

	return ejercicio4RecursivoConMemoriaInterno(numeroA, numeroB, memoria);

}

/*
Funcion que dados dos enteros a, b, calcule la siguiente sucesion numerica en funcion
de tres casos bases y uno recursivo que se llama a si mismo tantas veces como sea necesario
haciendo uso de memoria con un HashTable para evitar repetir calculos y devuelve el
resultado en forma de Long:
* Recursividad: 3 casos base y uno recursivo
* Complejidad: ????????????????????????
*/
long ejercicio4RecursivoConMemoriaInterno (int numeroA, int numeroB, hash_table memoria) {

	long resultado;
	//Tuple2 < Integer, Integer > tupla = Tuple.create(numeroA, numeroB);
	list lista = list_empty(int_type);
	list_add(&lista, &numeroA);
	list_add(&lista, &numeroB);

	// Casos bases:
	if (hash_table_contains(&memoria, &lista)) {

		resultado = hash_table_get(&memoria, &lista);

	} else if (numeroA < 2 && numeroB < 2) {

		resultado = (long) (numeroA + pow(numeroB, 2));
		hash_table_put(&memoria, &lista, &resultado);

	} else if (numeroA < 2 || numeroB < 2) {

		resultado = (long) (pow(numeroA, 2) + numeroB);
		hash_table_put(&memoria, &lista, &resultado);

	// Caso recursivo:
	} else {

		resultado = (long) ejercicio4RecursivoConMemoriaInterno((numeroA / 2), (numeroB - 1), memoria) +
						   ejercicio4RecursivoConMemoriaInterno((numeroA / 3), (numeroB - 2), memoria) +
						   ejercicio4RecursivoConMemoriaInterno((numeroA - 2), (numeroB / 4), memoria);

		hash_table_put(&memoria, &lista, &resultado);

	}

	return resultado;

}

