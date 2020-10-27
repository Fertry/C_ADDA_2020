/*
 * main.c
 *
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 1
 *
 */

// Includes:
#include "main.h"
#include "ejercicios/ejercicio1.h"
#include "ejercicios/ejercicio2.h"
#include "ejercicios/ejercicio3.h"

// Funcion principal:
int main() {

	char mem[3000];

	// Variables:
	list listaEnteros = leeDatosEjercicio1("ficheros/PI1Ej1DatosEntrada.txt");
	list resultadoEjercicio1 = compruebaSiEsPrimo(listaEnteros);
	list Listalimites = leeDatosEjercicio2("ficheros/PI1Ej2DatosEntrada.txt");
	list listaPuntos = leeDatosEjercicio3("ficheros/PI1Ej3DatosEntrada.txt");
	//resultadoEjercicio3 = sumaPorCuadrantes(listaPuntos);

	// Debug:
	//long numerosEnteros[] = { 6, 7, 9, 12, 1, 7, 15, 5 };
	//list listaEnteros = list_of(numerosEnteros, 8, int_type);
	//list resultadoEjercicio1 = compruebaSiEsPrimo(listaEnteros);
	//int listaRecurso[] = {7, 10, 46, 23, 27};
	//list lista = list_of(listaRecurso, 5, int_type);

	// Salida por consola:
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
	printf("Dato de entrada --> Limite: \n");
	printf("%s\n", list_tostring(&Listalimites, mem));
	printf("Resultado del ejercicio 2 --> Cuadrado de los siguientes primos : \n");
	funcionAuxiliarEjercicio2(Listalimites);
	printf("###################################################################################\n");
	printf("###################################################################################\n");

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 3 ################################\n");
	printf("Datos de entrada --> Lista de puntos: \n");
	printf("%s\n", list_tostring(&listaPuntos, mem));
	printf("Resultado del ejercicio 3 --> Cuadrantes con sus sumas: \n");
	//printf("%s\n", list_tostring(&resultadoEjercicio3, mem));
	printf("###################################################################################\n");
	printf("###################################################################################\n");

}
