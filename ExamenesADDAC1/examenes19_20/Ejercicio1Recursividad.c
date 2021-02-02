/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Exámenes del 1º cuatrimestre de ADDA
 */

#include "Ejercicios19_20.h"

/*
* Dada la siguiente implementación funcional se pide dar una versión iterativa y recursiva
* final C:
*/

// ##############################################
// Versión funcional del enunciado:
//	public static Long mistral(int n, int k) {
//		return LongStream.rangeClosed(1l, k)
//				.filter(e -> e % 2==0)
//				.map(e -> (n-e + 1) / e)
//				.sum();
//	}
// ##############################################

/*
* Solución iterativa: la función recibe dos parámetros n y k de tipo entero e itera de 1
* a k, mientras dura la iteración filtra los nº que cumplan el predicado (e%2 == 0), es
* decir, aquellos cuyo módulo sea igual a 0 (pares). Actualiza el nº en base a una condición
* ((n-e + 1) / e) y devuelve la suma de todos los nºs al final como dato de tipo Long.
*/
long solucionIterativa(int n, int k) {

	// Arranca el bucle en 1 y declara un acumulador que será el resultado:
	int e = 1;
	long resultado = 1l;

	// Mientras que e <= k:
	while (e <= k) {

		if (e % 2 == 0) {

			// Calcula el nº en base a la condición dada y lo suma al resultado:
			long numero = ((n - e + 1) / e);
			resultado = resultado + numero;

		}

		e = e + 1;

	}

	return resultado;

}

// ##############################################
// ##############################################

/*
* Solución recursiva final: la función recibe dos parámetros n y k de tipo entero e itera de 1
* a k, mientras dura la iteración filtra los nº que cumplan el predicado (e%2 == 0), es
* decir, aquellos cuyo módulo sea igual a 0 (pares). Actualiza el nº en base a una condición
* ((n-e + 1) / e) y devuelve la suma de todos los nºs al final como dato de tipo Long.
*/
long solucionRecursiva(int n, int k) {

	int e = 1;
	long resultado = 0l;

	// Llamada "opaca" a la función recursiva con datos iniciales:
	return solucionRecursivaInterna(n, k, e, resultado);

}

long solucionRecursivaInterna(int n, int k, int e, long resultado) {

	if (e <= k) {
		if (e % 2 == 0) {

			// Calculo del término y llamada recursiva a la función con los nuevos parámetros:
			long numero = ((n - e + 1) / e);
			resultado = solucionRecursivaInterna(n, k, e + 1, resultado + numero);

		} else {

			// Llamada recursiva en el caso de que no se cumpla la condición
			// e%2==0, el valor de resultado no se actualiza pero si lo hace
			// el contador e:
			resultado = solucionRecursivaInterna(n, k, e + 1, resultado);

		}

	}

	return resultado;

}
