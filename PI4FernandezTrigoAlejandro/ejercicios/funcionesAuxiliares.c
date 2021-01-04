/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#include "funcionesAuxiliares.h"

// ###################################################################################
// ###################################################################################
// ####################### 			FUNCIONES AUXILIARES	         #################
// ###################################################################################
// # Funciones que implementan utilidades para trabajar con arboles que no se hallan #
// # en la libreria:																 #
// ###################################################################################
// ###################################################################################

/*
Funcion auxiliar para castear el arbol a entero:
*/
int * castearArbol(int * numeroA, char * numeroB) {

	int * resultado = int_parse(numeroA, numeroB);

	return resultado;

}

/*
Funcion auxiliar para calcular el siguiente nivel de un arbol
dado como parametro:
*/
list calculaSiguienteNivel(list nivelCero) {

	int size = list_size(&nivelCero);
	list resultado = list_empty(tree_type);

	for (int i = 0; i < size; i++) {

		tree * arbol = (tree*) list_get(&nivelCero, i);
		int numeroHijos = tree_child_number(arbol);

		for (int hijo = 0; hijo < numeroHijos; hijo++) {

			list_add(&resultado, tree_get_child(arbol, hijo));

		}

	}

	return resultado;

}

/*
Funcion auxiliar para calcular la altura de un arbol
dado como parametro el arbol haciendo uso de calculaSiguienteNivel():
*/
int calculaAlturaArbol(tree * arbol) {

    int i;
    int acumulador = 1;

    list listaArboles = list_empty(tree_type);
    list_add(&listaArboles, arbol);

    list resultado = calculaSiguienteNivel(listaArboles);
    i = list_size(&resultado);

    while (i != 0) {

    	resultado = calculaSiguienteNivel(resultado);
        i = list_size(&resultado);
        acumulador++;

    }

    return acumulador;

}

/*
Funcion auxiliar para calcular el nivel de un arbol
dado como parametro el arbol y un indice correspondiente
al nivel requerido haciendo uso de calculaSiguienteNivel():
*/
list calculaNivelArbol(tree * arbol, int i) {

    list listaNivel = list_empty(tree_type);
    list_add(&listaNivel, arbol);

    while (i >= 1) {

    	listaNivel = calculaSiguienteNivel(listaNivel);
        i--;

    }

    return listaNivel;

}
