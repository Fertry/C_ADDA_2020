/*
 * main.c
 *
 *  Created on: 6 oct. 2020
 *      Author: Alejandro Fdez. Trigo
 */
#include "main.h"


// Función de ejecución:
int main(){

	printf("Hola mundo!\n");


	double numerosReales[] = { 45., 56, 90., 1., 23., 78., 76. };
	list listaNumeros = list_of(numerosReales, 7, double_type);
	long numerosEnteros[] = { 6, 7, 9, 12, 1, 7, 15, 5 };
	list listaEnteros = list_of(numerosEnteros, 8, int_type);

	double sumaReales = 0.0;
	long sumaEnteros = 0;

	sumaReales = sumaListaReales(listaNumeros);
	sumaEnteros = sumaListaEnteros(listaEnteros);

	printf("Suma = %lf\n", sumaReales);
	printf("Suma = %ld\n", sumaEnteros);

}

// Dada una lista de nº reales, devolver su suma:
float sumaListaReales(list lista) {

	float suma = 0.0;
	for(int i=0;i<lista.size;i++) {

			suma = suma + *(double*) list_get(&lista,i);

	}

	return suma;

}

// Dada una lista de nº enteros, sumar los cuadrados de todos los elementos de la lista:
int sumaListaEnteros(list lista) {

	int suma = 0;
	for(int i=0;i<lista.size;i++) {

		int numero = *(int*) list_get(&lista,i);
		int cuadrado = numero * numero;

		suma = suma + cuadrado;

	}

	return suma;

}





