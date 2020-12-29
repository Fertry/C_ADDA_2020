/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#include "main.h"
#include "ejercicios/ejercicio1.h"
#include "ejercicios/ejercicio2.h"
#include "ejercicios/ejercicio3.h"
#include "ejercicios/ejercicio4.h"
#include "ejercicios/ejercicio5.h"

int main() {

	char mem[500];

	// Variables:
	list lista1 = leeDatosEjercicio1("ficheros/PI4Ej1DatosEntrada.txt");
	//list lista2A = leeDatosEjercicio2Arboles("ficheros/PI4Ej2DatosEntrada.txt");
	list lista2B = leeDatosEjercicio2Listas("ficheros/PI4Ej2DatosEntrada.txt");
	list lista3 = leeDatosEjercicio3("ficheros/PI4Ej3DatosEntrada.txt");
	list lista4 = leeDatosEjercicio4("ficheros/PI4Ej4DatosEntrada.txt");
	list lista5 = leeDatosEjercicio5("ficheros/PI4Ej5DatosEntrada.txt");

	// Salida por consola:
	printf("#######################################################################\n");
	printf("######################### TEST EJERCICIO 1 ############################\n");
	funcionAuxiliarEjercicio1(lista1);
	printf("#######################################################################\n");
	printf("#######################################################################\n");
	printf("\n");

	printf("#######################################################################\n");
	printf("######################### TEST EJERCICIO 2 ############################\n");
	//funcionAuxiliarEjercicio2(lista2A, lista2B);
	printf("Lista: %s", list_tostring(&lista2B, mem));
	printf("#######################################################################\n");
	printf("#######################################################################\n");
	printf("\n");

	printf("#######################################################################\n");
	printf("######################### TEST EJERCICIO 3 ############################\n");
	funcionAuxiliarEjercicio3(lista3);
	printf("#######################################################################\n");
	printf("#######################################################################\n");
	printf("\n");

	printf("#######################################################################\n");
	printf("######################### TEST EJERCICIO 4 ############################\n");
	funcionAuxiliarEjercicio4(lista4);
	printf("#######################################################################\n");
	printf("#######################################################################\n");
	printf("\n");

	printf("#######################################################################\n");
	printf("######################### TEST EJERCICIO 5 ############################\n");
	funcionAuxiliarEjercicio5(lista5);
	printf("#######################################################################\n");
	printf("#######################################################################\n");
	printf("\n");

}
