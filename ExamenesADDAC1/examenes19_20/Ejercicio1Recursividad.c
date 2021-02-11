/*
 *  	Analisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Ex�menes del 1� cuatrimestre de ADDA
 */

#include "Ejercicios19_20.h"

/*
* Dada la siguiente implementaci�n funcional se pide dar una versi�n iterativa y recursiva
* final C:
*/

// ##############################################
// Versi�n funcional del enunciado:
//	public static Long mistral(int n, int k) {
//		return LongStream.rangeClosed(1l, k)
//				.filter(e -> e % 2==0)
//				.map(e -> (n-e + 1) / e)
//				.sum();
//	}
// ##############################################

/*
* Soluci�n iterativa: la funci�n recibe dos par�metros n y k de tipo entero e itera de 1
* a k, mientras dura la iteraci�n filtra los n� que cumplan el predicado (e%2 == 0), es
* decir, aquellos cuyo m�dulo sea igual a 0 (pares). Actualiza el n� en base a una condici�n
* ((n-e + 1) / e) y devuelve la suma de todos los n�s al final como dato de tipo Long.
*/
long solucionIterativa(int n, int k) {

	// Arranca el bucle en 1 y declara un acumulador que ser� el resultado:
	int e = 1;
	long resultado = 1l;

	// Mientras que e <= k:
	while (e <= k) {

		if (e % 2 == 0) {

			// Calcula el n� en base a la condici�n dada y lo suma al resultado:
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
* Soluci�n recursiva final: la funci�n recibe dos par�metros n y k de tipo entero e itera de 1
* a k, mientras dura la iteraci�n filtra los n� que cumplan el predicado (e%2 == 0), es
* decir, aquellos cuyo m�dulo sea igual a 0 (pares). Actualiza el n� en base a una condici�n
* ((n-e + 1) / e) y devuelve la suma de todos los n�s al final como dato de tipo Long.
*/
long solucionRecursiva(int n, int k) {

	int e = 1;
	long resultado = 0l;

	// Llamada "opaca" a la funci�n recursiva con datos iniciales:
	return solucionRecursivaInterna(n, k, e, resultado);

}

long solucionRecursivaInterna(int n, int k, int e, long resultado) {

	if (e <= k) {
		if (e % 2 == 0) {

			// Calculo del t�rmino y llamada recursiva a la funci�n con los nuevos par�metros:
			long numero = ((n - e + 1) / e);
			resultado = solucionRecursivaInterna(n, k, e + 1, resultado + numero);

		} else {

			// Llamada recursiva en el caso de que no se cumpla la condici�n
			// e%2==0, el valor de resultado no se actualiza pero si lo hace
			// el contador e:
			resultado = solucionRecursivaInterna(n, k, e + 1, resultado);

		}

	}

	return resultado;

}

/*
 * Dado una cadena de chars, comprobar si cada caracter aparece 2 veces
 * consecutivamente. Tener en cuenta que la cadena tiene un n� par de letras.
 */

/*
 * Soluci�n iterativa:
 */
bool secuencia (char * letras) {

	bool resultado = true;

	int i = 0;
	int j = strlen(letras) - 2;

	// Si no hemos llegado al final y es true:
	while(i <= j && resultado) {

		// Coinciden el elemento en i y en i + 1:
		resultado = letras[i] == letras[i + 1];
		i += 2;

	}

	return resultado;

}

/*
 * Soluci�n recursiva final:
 */
bool secuenciaRF1 (char * letras) {

	return secuenciaRF2(letras, 0, strlen(letras) - 2, true);

}

bool secuenciaRF2 (char * letras, int i, int j, bool resultado) {

	// Si no hemos llegado al final y es true:
	if (i <= j && resultado) {

		bool booleano = letras[i] == letras[i + 1];
		resultado = secuenciaRF2(letras, i + 2, j, booleano);

	} else {

		return resultado;

	}

	return resultado;

}
