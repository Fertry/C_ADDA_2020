/*
 * main.c
 *
 *  	An�lisis y Dise�o de Datos y Algoritmos - 2020
 *  	Pr�ctica 1 - Ejercicios Iterativos
 *      Author: Alejandro Fern�ndez Trigo
 */

#include "main.h"

// Main:
int main() {

	char mem[1000];

	list listaNumerosEjercicio1 = leeDatosEjercicio1("Tests/PI1Ej1DatosEntrada.txt");
	//list resultadoEjercicio1 = compruebaSiEsPrimo(listaNumerosEjercicio1);

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 1 ################################\n");
	printf("Datos de entrada --> Lista de enteros: \n");
	printf("%s\n", list_tostring(&listaNumerosEjercicio1, mem));
	printf("Resultado del ejercicio 1 --> Lista de primos: \n");
	//printf("%s\n", list_tostring(&resultadoEjercicio1, mem));
	printf("###################################################################################\n");
	printf("###################################################################################\n");

}

// Funci�n que lee un fichero de entrada; dado un fichero con m�ltiples l�neas
// y en cada l�nea n�meros enteros separados por comas, devuelve una lista
// formada por todos los n�meros del fichero:
list leeDatosEjercicio1 (char * fichero) {

	list lista = list_empty(int_type);
	iterator iterador1 = file_iterable_pchar(fichero);
	while (iterable_has_next(&iterador1)) {

		int * n;
		iterator iterador2 = split_iterable_pchar(n, ",");
		while (iterable_has_next(&iterador2)) {

			int numero = *(int*) iterable_next(&iterador2);
			list_add(&lista, &numero);

		}

	}

	return lista;

}

// Dada una lista, comprueba que elementos son primos y los
// devuelve, todos, en una lista nueva como resultado:
list compruebaSiEsPrimo (list lista) {

	list resultado = list_empty(int_type);

	for (int i = 1; i< lista.size; i++) {

		int numero = *(int*) list_get(&lista,i);
		if (esPrimo(numero)) {

			list_add(&resultado, &numero);

		}

	}

	return resultado;

}

// Funci�n auxiliar que comprueba si un n�mero dado es
// primo o no y devuelve el resultado en forma de una
// variable l�gica:
bool esPrimo(long n) {
	long sq = (long) sqrt((double) n);
	int e = 2;
	bool a = false;
	while (e <= sq && !a) {
		a = (n%e==0);
		e = e + 1;
	}
	return !a;
}
