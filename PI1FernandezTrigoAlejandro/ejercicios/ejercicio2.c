/*
 * ejercicio2.c
 *
 *  	An�lisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fern�ndez Trigo
 *      Pr�ctica Individual 1
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

        char *fila = (char*) iterable_next(&filas);
        char numeroChar = replaceWord(fila, limite, espacio);
        int numeroInt = int_parse_s(numeroChar);
        list_add(&resultado, &numeroInt);

    }

    return resultado;

}

// Dado un numero entero, devuelve una cadena (con saltos de linea) formada por
// todos los n� primos (al cuadrado) desde el 2 hasta el limite (numero introducido como parametro):
string primosHastaLimite(int limite) {

	int i = 1;
	int cuadrado = 0;
	char cuadradoString [255];
    string resultado = string_empty();
    //string cuadradoString = string_empty();

    while (i <= limite) {

        if (siguiente_primo(i) <= limite) {

            cuadrado = pow(siguiente_primo(i), 2);
            cuadradoString = int_tostring(&cuadrado, cuadradoString);
            // resultado = resultado + cuadradoString + "\n";

        }

        i = siguiente_primo(i);

    }

    return resultado;

}

// Funci�n auxiliar para mostrar el resultado del ejercicio 2. Dado que se
// recibe un entero (no una lista), iteramos para llamar a la funci�n tantas
// veces como l�mites nos den en el fichero de entrada:
void funcionAuxiliarEjercicio2 (list lista) {

	int i = 0;
	char mem[256];
	int limite = 0;
	string resultado = string_empty();

	while (i < list_size(&lista)) {

		limite = list_get(&lista, i);
		resultado = primosHastaLimite(limite);
		printf("Limite %d\n", list_get(&lista, i));
		printf("%s", string_tostring(&resultado, mem));
		i++;

	}

}
