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
list leeDatosEjercicioDos(char * fichero) {

	char espacio[] = "";
	char limite[] = "Limite: ";
	iterator filas = file_iterable_pchar(fichero);
    list resultado = list_empty(int_type);

    while (iterable_has_next(&filas)) {

        char fila = (char) iterable_next(&filas);
        char numero = replaceWord(fila, limite, espacio);
        int numeroEntero = int_parse_s(numero);
        list_add(&resultado, &numeroEntero);

    }

    return resultado;

}

// Dado un numero entero, devuelve una cadena (con saltos de linea) formada por
// todos los nº primos (al cuadrado) desde el 2 hasta el limite (numero introducido como parametro):
string primosHastaLimite(int limite) {

	int i = 1;
    string resultado = "";
    int cuadrado = 0;

    while (i <= limite) {

        if (siguiente_primo(i) <= limite) {

            int cuadrado = pow(siguiente_primo(i), 2);
            resultado = resultado + cuadrado + "\n";

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
	string resultado = "";

	while (i < list_size(&lista)) {

		resultado = primosHastaLimite(list_get(&lista, i));
		printf("Limite %d\n", list_get(&lista, i));
		printf("%s", resultado);
		i++;

	}

}
