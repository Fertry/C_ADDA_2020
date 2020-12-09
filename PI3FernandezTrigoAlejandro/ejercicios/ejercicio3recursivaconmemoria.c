/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio3recursivaconmemoria.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 3 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que llame al ejercicio recursivo pasando como parametro
el HashTable que se emplea como memoria para actuar de forma opaca al usuario:
*/
long ejercicio3RecursivoConMemoria (int numero) {

	hash_table memoria = hash_table_empty(int_type, long_type);

	return ejercicio3RecursivoConMemoriaInterno(numero, memoria);

}

/*
Funcion que dado un nº n entero calcula la siguiente sucesion numerica
en base a tres casos bases y uno recursivo que se llama a si mismo tantas
veces como sea necesario haciendo uso de memoria con un HashTable para evitar
repetir operaciones y devuelve el resultado como Long:
* Recursividad: 3 casos base y uno recursivo
* Complejidad: ????????????????????????
*/
long ejercicio3RecursivoConMemoriaInterno (int numero, hash_table memoria) {

	long resultado = 0L;

	// Casos base:
	// memoria.containsKey(numero)
	if (hash_table_contains(&memoria, &numero)) {

		// resultado = memoria.get(numero);
		resultado = hash_table_get(&memoria, &numero);

	} else if (numero == 0) {

		resultado = 2L;
		// memoria.put(numero, resultado);
		hash_table_put(&memoria, &numero, &resultado);

	} else if (numero == 1 || numero == 2) {

		resultado = 1L;
		// memoria.put(numero, resultado);
		hash_table_put(&memoria, &numero, &resultado);

	// Caso recursivo:
	} else {

		resultado = (4
				* ejercicio3RecursivoConMemoriaPrivado((numero - 1), memoria))
				+ ejercicio3RecursivoConMemoriaPrivado((numero - 2), memoria)
				+ ejercicio3RecursivoConMemoriaPrivado((numero - 3), memoria);

		// memoria.put(numero, resultado);
		hash_table_put(&memoria, &numero, &resultado);

	}

	return resultado;

}
