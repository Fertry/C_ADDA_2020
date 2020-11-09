/*
 * ejercicio1iterativa.c
 *
 *  	Análisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernández Trigo
 *      Práctica Individual 2
 *
 */

#include "ejercicio1iterativa.h"

// ###################################################################################
// ###################################################################################
// ####################### 		EJERCICIO 1 - ITERATIVO				##################
// ###################################################################################
// ###################################################################################

// Dada una lista de listas de strings, donde cada lista contiene dos frases,
// itera sobre ambas frases de cada lista. Determina en que punto de ambas frases
// dejan de ser iguales y devuelve esa posición numérica:
int hastaDondeSonIgualesIterativo (list lista) {

	int i = 0;
	string frase1 = string_of_pchar("Hola mundo");
	string frase2 = string_of_pchar("Hola mondo");
	bool verdadero = true;

	//frase1 = list_get(&lista, 0);
	//frase2 = list_get(&lista, 1);

	while (i < frase1.size && verdadero) {

		if (frase1.data[i] == frase2.data[i]) {

			i++;

		} else {

			verdadero = false;
		}

	}

	return i;

}

/*
 * 	int i = 0;
	char mem[500];
	string frase1;
	string frase2;
	int posicionIterativo;
	//int posicionRecursivoFinal;
	list miniLista = list_empty(string_type);

	while (i < list_size(&lista)) {

		list frases = list_empty(string_type);
		miniLista = list_get(&lista, i);
		frase1 = list_get(&miniLista, 0);
		frase2 = list_get(&miniLista, 1);
		list_add(&frases, &frase1);
		list_add(&frases, &frase2);
		posicionIterativo = hastaDondeSonIgualesIterativo(frases);
		//posicionRecursivoFinal = hastaDondeSonIgualesRecursivoFinal(frases);
		printf("%s\n", string_tostring(frase1, mem));
		printf("%s\n", string_tostring(frase2, mem));
		prinf("1. Iterativo: %d\n", posicionIterativo);
		//prinf("2. Recursivo final: %d\n", posicionRecursivoFinal);
		prinf("\n");
		i++;
 */
