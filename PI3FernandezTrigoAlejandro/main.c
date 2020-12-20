/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

// Includes:
#include "main.h"
#include "ejercicios/ejercicio1.h"
#include "ejercicios/ejercicio2.h"
#include "ejercicios/ejercicio3.h"
#include "ejercicios/ejercicio4.h"

// Funcion principal:
int main() {

	// Variables:
	//matrix matriz1 = leeDatosEjercicio1("ficheros/PI3Ej1DatosEntrada1.txt");
	//matrix matriz2 = leeDatosEjercicio1("ficheros/PI3Ej1DatosEntrada2.txt");
	//matrix matriz3 = leeDatosEjercicio1("ficheros/PI3Ej1DatosEntrada3.txt");
	//matrix matriz4 = leeDatosEjercicio1("ficheros/PI3Ej1DatosEntrada4.txt");
	//matrix matriz5 = leeDatosEjercicio1("ficheros/PI3Ej1DatosEntrada5.txt");
	//matrix matriz6 = leeDatosEjercicio1("ficheros/PI3Ej1DatosEntrada6.txt");
	list listaNumeros2 = leeDatosEjercicio2("ficheros/PI3Ej2DatosEntrada.txt");
	list listaNumeros3 = leeDatosEjercicio3("ficheros/PI3Ej3DatosEntrada.txt");
	list listaNumeros4 = leeDatosEjercicio4("ficheros/PI3Ej4DatosEntrada.txt");

	// Salida por consola:
	//funcionAuxiliarEjercicio1(matriz1);
	//funcionAuxiliarEjercicio1(matriz2);
	//funcionAuxiliarEjercicio1(matriz3);
	//funcionAuxiliarEjercicio1(matriz4);
	//funcionAuxiliarEjercicio1(matriz5);
	//funcionAuxiliarEjercicio1(matriz6);
	printf("###################################################################################\n");
	printf("###################################################################################\n");
	printf("\n");

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 2 #################################\n");
	funcionAuxiliarEjercicio2(listaNumeros2);
	printf("###################################################################################\n");
	printf("###################################################################################\n");
	printf("\n");

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 3 #################################\n");
	funcionAuxiliarEjercicio3(listaNumeros3);
	printf("###################################################################################\n");
	printf("###################################################################################\n");
	printf("\n");

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 4 #################################\n");
	funcionAuxiliarEjercicio4(listaNumeros4);
	printf("###################################################################################\n");
	printf("###################################################################################\n");

}
