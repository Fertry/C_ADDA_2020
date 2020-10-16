/*
 * main.c
 *
 *  	Análisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernández Trigo
 *      Práctica Individual 1
 *
 */

#include "main.h"

// Función principal:
int main() {

	char mem[256];

	// Variables:
	//list listaEnteros = leeDatosEjercicio1("Tests/PI1Ej1DatosEntrada.txt");
	//list resultadoEjercicio1 = compruebaSiEsPrimo(listaEnteros);
	//list listaLimites = leeDatosEjercicio2("Tests/PI1Ej2DatosEntrada.txt");
	//list listaPuntos = leeDatosEjercicio3("Tests/PI1Ej3DatosEntrada.txt");
	//mapa? resultadoEjercicio3 = sumaPorCuadrantes(listaPuntos);

	// Debug:
	//long numerosEnteros[] = { 6, 7, 9, 12, 1, 7, 15, 5 };
	//list listaEnteros = list_of(numerosEnteros, 8, int_type);
	//list resultadoEjercicio1 = compruebaSiEsPrimo(listaEnteros);

	// Salida por consola:
	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 1 ################################\n");
	printf("Datos de entrada --> Lista de enteros: \n");
	//printf("%s\n", list_tostring(&listaEnteros, mem));
	printf("Resultado del ejercicio 1 --> Lista de primos: \n");
	//printf("%s\n", list_tostring(&resultadoEjercicio1, mem));
	printf("###################################################################################\n");
	printf("###################################################################################\n");

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 2 ################################\n");
	printf("Dato de entrada --> Limite: \n");
	//printf("%s\n", list_tostring(&listaLimites, mem));
	printf("Resultado del ejercicio 2 --> Cuadrado de los siguientes primos : \n");
	//funcionAuxiliarEjercicio2(listaLimites);
	printf("###################################################################################\n");
	printf("###################################################################################\n");

	printf("###################################################################################\n");
	printf("############################# Test de Ejercicio 3 ################################\n");
	printf("Datos de entrada --> Lista de puntos: \n");
	//printf("%s\n", list_tostring(&listaPuntos, mem));
	printf("Resultado del ejercicio 3 --> Cuadrantes con sus sumas: \n");
	//printf("%s\n", list_tostring(&resultadoEjercicio3, mem));
	printf("###################################################################################\n");
	printf("###################################################################################\n");

}

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 1                         #################
//###################################################################################
//###################################################################################

// Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
// y en cada linea numeros enteros separados por comas, devuelve una lista de listas
// formadas por los numeros del fichero:
list leeDatosEjercicio1 (char * fichero) {

	list lista = list_empty(int_type);
	iterator iterador1 = file_iterable_pchar(fichero);
	while (iterable_has_next(&iterador1)) {

		int * n;
		iterator iterador2 = split_iterable_pchar(n, ",");
		while (iterable_has_next(&iterador2)) {

			int numero = *(int*) iterable_next(&iterador2);
			list_add(&lista, &numero);

		}

	}

	return lista;

}

// Dada una lista de listas de enteros, comprueba que elementos son primos
// y los devuelve, todos, en una lista nueva como resultado:
list compruebaSiEsPrimo (list lista) {

	int i = 0;
	int j = 0;
	list resultado = list_empty(int_type);

	while (i < list_size(&lista)) {
		while (j < list_size(list_get(&lista, i))) {

			if (es_primo(list_get(list_get(&lista, i), j))) {

				list_add(&resultado, list_get(list_get(&lista, i), j));

			}

			j++;

		}

		j = 0;
		i++;

	}

	return resultado;

}

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 2                         #################
//###################################################################################
//###################################################################################

// Funcion que lee un fichero de entrada; dado un fichero con multiples lineas
// y en cada linea un concepto "Limite: numero", toma ese numero para pasarlo como
// parametro a la funcion del ejercicio 2:
/*int leeDatosEjercicio2 (char * fichero) {

	return NULL;

}*/

// Dado un numero entero, devuelve una cadena (con saltos de linea) formada por
// todos los nº primos (al cuadrado) desde el 2 hasta el limite (numero introducido como parametro):
/*string primosHastaLimite(int limite) {

	int i = 1;
    string resultado = "";

    while (i < 100) {

        if (siguiente_primo(i) < limite + 1) {

            int cuadrado = pow(siguiente_primo(i), 2);
            string cuadradoString = "";
            cuadradoString = itoa(cuadrado, cuadradoString, 100);
            resultado = resultado + cuadrado + "";

        }

        i = siguiente_primo(i);

    }

    return resultado;

}*/

// Función auxiliar para mostrar el resultado del ejercicio 2. Dado que se
// recibe un entero (no una lista), iteramos para llamar a la función tantas
// veces como límites nos den en el fichero de entrada:
/*void funcionAuxiliarEjercicio2 (list lista) {

	int i = 0;
	string resultado = "";

}*/

//###################################################################################
//###################################################################################
//#######################		EJERCICIO 3                         #################
//###################################################################################
//###################################################################################

// Funcion que lee una lista de puntos del formato (coordenadaX, coordenadaY) y devuelve
// una lista de Punto2D formada por los puntos del fichero:
/*void leeDatosEjercicio3 (char * fichero) {


}*/

// Dado una lista de puntos, devuelve una colección de tipo Map con la suma de sus
// coordenadas X e Y por cuadrantes:
/*void sumaPorCuadrantes (list lista) {


}*/
