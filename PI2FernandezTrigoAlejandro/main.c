/*
 * main.c
 *
 *  	Análisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernández Trigo
 *      Práctica Individual 2
 *
 */

// Includes:
#include "main.h"
#include "ejercicios/ejercicio1.h"
#include "ejercicios/ejercicio2.h"
#include "ejercicios/ejercicio3.h"

// Funcion principal:
int main() {

	char mem[500];

	// Variables:
	list listaFrases = leeDatosEjercicio1("ficheros/PI2Ej1DatosEntrada.txt");
	//list listaEnteros = leeDatosEjercicio2("ficheros/PI2Ej2DatosEntrada.txt");
	//list listaEnteros3 = leeDatosEjercicio3("ficheros/PI2Ej3DatosEntrada.txt");

	// Salida por consola:
	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 1 ################################\n");
	funcionAuxiliarEjercicio1(listaFrases);
	printf("###################################################################################\n");
	printf("###################################################################################\n");
	printf("\n");

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 2 ################################\n");

	printf("###################################################################################\n");
	printf("###################################################################################\n");
	printf("\n");

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 3 ################################\n");

	printf("###################################################################################\n");
	printf("###################################################################################\n");

}


