/*
 * ejercicio2.c
 *
 *  	Análisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernández Trigo
 *      Práctica Individual 1
 *
 */

#include "ejercicio2.h"

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 2                         #################
//###################################################################################
//###################################################################################

// Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
// y en cada linea un concepto "Limite: numero", toma ese numero para pasarlo como
// parametro a la funcion del ejercicio 2:
list leeDatosEjercicio2 (char * fichero) {

	char *tt[255];
	char limite[] = ": ";
	list resultado = list_empty(int_type);
	iterator filas = file_iterable_pchar(fichero);

	while (iterable_has_next(&filas)) {

		char *fila = (char*) iterable_next(&filas);
		split_text(fila, limite, tt);
		int numero = int_parse_s(tt[1]);
		list_add(&resultado, &numero);

	}

	return resultado;

}

// Dado un numero entero, devuelve una cadena (con saltos de linea) formada por
// todos los nº primos (al cuadrado) desde el 2 hasta el limite (numero introducido como parametro):
string primosHastaLimite (int limite) {

	int i = 1;
	char mem [255];
	string resultado = string_empty();
	string saltoLinea = string_of_pchar("\n");

	while (i <= limite) {

		char * cadena;
		string numero = string_empty();

		if (siguiente_primo(i) <= limite) {

			int cuadrado = pow(siguiente_primo(i), 2);
			cadena = int_tostring(&cuadrado, mem);
			numero = string_of_pchar(cadena);
			string_add_string(&resultado, &numero);
			string_add_string(&resultado, &saltoLinea);

		}

		i = siguiente_primo(i);

	}

	return resultado;

}

// Función auxiliar para mostrar el resultado del ejercicio 2. Dado que se
// recibe un entero (no una lista), iteramos para llamar a la función tantas
// veces como límites nos den en el fichero de entrada:
void funcionAuxiliarEjercicio2 (list lista) {

	int i = 0;
	char mem[255];
	int limite = 0;
	string resultado = string_empty();

	while (i < list_size(&lista)) {

		limite = *(int*) list_get(&lista, i);
		resultado = primosHastaLimite(limite);
		printf("Limite %d\n", limite);
		printf("%s", string_tostring(&resultado, mem));
		printf("\n");
		i++;

	}

}
