/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio1.h"
#include "ejercicio1recursiva.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 1 				 #################
// ###################################################################################
// ###################################################################################

// Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
// y en cada linea un nº n de numeros enteros, las filas del fichero representan las
// filas de una matriz cuadrada de orden n*n. Pasamos los numeros de las filas al metodo
// toMultiArray() de Miguel Toro para acceder a las posiciones con facilidad:
matrix leeDatosEjercicio1 (char * fichero) {

    int fila = 0;
    int columna = 0;
    int dimension = 0;
	iterator lista = file_iterable_pchar(fichero);
	matrix resultado;

    while (iterable_has_next(&lista)) {

    	char *fila = (char*) iterable_next(&lista);
    	iterator miniFila = split_iterable_pchar(fila, " ");
        list miniLista = list_empty(int_type);

        while (iterable_has_next(&miniFila)) {

            char *numeros = (char*) iterable_next(&miniFila);
            int numero = int_of_pchar(numeros);
            list_add(&miniLista, &numero);

        }

        while (columna < ) {


        }

    	int rango = sizeof(list_get(&fila, 0));


    }

    //resultado = matrix_of_array(int * NULL, rango, rango);

    return resultado;


    /*
     	public static Integer [][] leeDatosEjercicio1(String fichero) {

		int fila = 0;
		int columna = 0;
		int dimension = 0;
		List <String> filas = StreamsS.file(fichero).collect(Collectors.toList());
		int rango = filas.get(0).split(" ").length;
		Integer[] resultado = new Integer [rango * rango];

		while (fila < filas.size()) {

			String[] numeros = filas.get(fila).split(" ");

			while (columna < numeros.length) {

				resultado [dimension] = Integer.parseInt(numeros[columna]);

				columna++;
				dimension++;

			}

			fila++;
			columna = 0;

		}

		return Arrays2.toMultiArray(resultado, rango, rango);

	}
     */

}

// Funcion auxiliar para, dado una matriz leida por la funcion leeDatosEjercicio1(),
// llamar a la función recursiva que resuelve el ejercicio y formatear la salida
// acorde al fichero de salida de ejemplo proporcionado:
void funcionAuxiliarEjercicio1() {


}

// Funcion privada para mostrar una matriz por pantalla al pasarse esta
// por parametro siempre y cuando la dimension no exceda 16:
void muestraMatrizPorPantalla() {


}
