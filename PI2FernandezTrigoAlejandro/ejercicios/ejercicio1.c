/*
 * ejercicio1.c
 *
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 2
 *
 */

#include "ejercicio1.h"
#include "ejercicio1iterativa.h"
#include "ejercicio1recursivafinal.h"

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 1                         #################
//###################################################################################
//###################################################################################

// Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
// y en cada linea dos frases separadas por un "#", devuelve una lista de listas de strings,
// donde cada lista contiene cada par de frases:
list leeDatosEjercicio1 (char * fichero) {

    iterator lista = file_iterable_pchar(fichero);
    list resultado = list_empty(list_type);

    while (iterable_has_next(&lista)) {

    	char *fila = (char*) iterable_next(&lista);
    	iterator miniFila = split_iterable_pchar(fila, "#");
        list miniLista = list_empty(string_type);

        while (iterable_has_next(&miniFila)) {

            char *frases = (char*) iterable_next(&miniFila);
            string frase = string_of_pchar(frases);
            list_add(&miniLista, &frase);

        }

        list_add(&resultado, &miniLista);
    }

    return resultado;

}

// Funcion auxiliar para, dado una lista de listas de strings devuelta por
// la función de lectura, invocar a la función hastaDondeSonIguales()
// tantas veces como pares de frases recibamos por fichero:
void funcionAuxiliarEjercicio1 (list lista) {

	int i = 0;
	char mem[500];
	string frase1;
	string frase2;
	int posicionIterativo;
	//int posicionRecursivoFinal;

	while (i < list_size(&lista)) {

		list parDeFrases = *(list*) list_get(&lista, i);
		frase1 = *(string*) list_get(&parDeFrases, 0);
		frase2 = *(string*) list_get(&parDeFrases, 1);

		posicionIterativo = hastaDondeSonIgualesIterativo(frase1, frase2);
		//posicionRecursivoFinal = hastaDondeSonIgualesRecursivoFinal(frases);

		printf("%s\n", string_tostring(&frase1, mem));
		printf("%s\n", string_tostring(&frase2, mem));
		printf("1. Iterativo: %d\n", posicionIterativo);
		//printf("2. Recursivo final: %d\n", posicionRecursivoFinal);
		printf("\n");
		i++;

	}

}
