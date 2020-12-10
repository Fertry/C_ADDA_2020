/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio3recursivasinmemoria.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 3 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que dado un nº n entero calcula la siguiente sucesion numerica
en base a dos casos bases y uno recursivo que se llama a si mismo tantas
veces como sea necesario y devuelve el resultado como Long:
* Recursividad: 2 casos base y uno recursivo
* Complejidad: ????????????????????????
*/
long ejercicio3RecursivoSinMemoria (long numero) {

	long resultado;

	// Casos bases:
	if (numero == 0) {

		resultado = 2L;

	} else if (numero == 1 || numero == 2) {

		resultado = 1L;

	// Caso recursivo:
	} else {

		resultado = (4 * ejercicio3RecursivoSinMemoria((numero - 1))) +
					ejercicio3RecursivoSinMemoria((numero - 2)) +
					ejercicio3RecursivoSinMemoria((numero - 3));

	}

	return resultado;

}

