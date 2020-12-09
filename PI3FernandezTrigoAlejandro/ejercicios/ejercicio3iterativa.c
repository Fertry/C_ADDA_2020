/*
 *  	Analisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio3iterativa.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 3 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que dado un n� n entero calcula la siguiente sucesion numerica
haciendo uso de un bucle while y devuelve el resultado como Long:
* Complejidad: ????????????????????????
*/
long ejercicio3Iterativo (int numero) {

    int i = 3;
    long f1 = 1L;
    long f2 = 1L;
    long f3 = 2L;
    long fn = 0L;

    while (i <= numero) {

        fn = 4 * f1 + f2 + f3;
        f3 = f2;
        f2 = f1;
        f1 = fn;
        i++;

    }

    return fn;

}


