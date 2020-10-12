/*
 * main.c
 *
 *  	An�lisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fern�ndez Trigo
 *      Pr�ctica Individual 1
 *
 */

#include "main.h"

// Funci�n principal:
int main() {

	char mem[1000];

	// ################################################################
	// Tests de funciones sin lectura de datos para debug:
	// ################################################################
	long numerosEnteros[] = { 6, 7, 9, 12, 1, 7, 15, 5 };
	list listaEnteros = list_of(numerosEnteros, 8, int_type);
	list resultadoEjercicio1 = compruebaSiEsPrimo(listaEnteros);
	// ################################################################

	// Variables:
	//list listaNumerosEjercicio1 = leeDatosEjercicio1("Tests/PI1Ej1DatosEntrada.txt");
	//list resultadoEjercicio1 = compruebaSiEsPrimo(listaNumerosEjercicio1);

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 1 ################################\n");
	printf("Datos de entrada --> Lista de enteros: \n");
	printf("%s\n", list_tostring(&listaEnteros, mem));
	printf("Resultado del ejercicio 1 --> Lista de primos: \n");
	printf("%s\n", list_tostring(&resultadoEjercicio1, mem));
	printf("###################################################################################\n");
	printf("###################################################################################\n");

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 2 ################################\n");
	//printf("Dato de entrada --> Limite: \n");
	//printf("%s\n", list_tostring(&listaEnteros, mem));
	//printf("Resultado del ejercicio 2 --> Siguientes primos hasta el : \n", limite);
	//printf("%s\n", list_tostring(&resultadoEjercicio1, mem));
	printf("###################################################################################\n");
	printf("###################################################################################\n");

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 3 ################################\n");
	//printf("Datos de entrada --> Lista de puntos: \n");
	//printf("%s\n", list_tostring(&listaEnteros, mem));
	//printf("Resultado del ejercicio 3 --> ????: \n");
	//printf("%s\n", list_tostring(&resultadoEjercicio1, mem));
	printf("###################################################################################\n");
	printf("###################################################################################\n");

}

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 1                         #################
//###################################################################################
//###################################################################################

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


//###################################################################################
//###################################################################################
//#######################		EJERCICIO 2                         #################
//###################################################################################
//###################################################################################

// Funci�n que lee un fichero de entrada; dado un fichero con m�ltiples l�neas
// y en cada l�nea un concepto "Limite: n�mero", toma ese n�mero para pasarlo como
// par�metro a la funci�n del ejercicio 2:
int leeDatosEjercicio2 (char * fichero) {

	return NULL;

}


// Dado un n�mero entero, devuelve una cadena (con saltos de linea) formada por
// todos los n� primos desde el 1 hasta el l�mite (n�mero introducido como par�metro):
//string primosHastaLimite (int limite) {

	//return NULL;

//}

// Funci�n auxiliar que calcula cual es el pr�ximo primo dado un n� entero:
int siguientePrimo (int numero) {

	return NULL;

}

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 3                         #################
//###################################################################################
//###################################################################################

// Funci�n que lee una lista de puntos y....


// Dado un punto...


// Funci�n auxiliar....
