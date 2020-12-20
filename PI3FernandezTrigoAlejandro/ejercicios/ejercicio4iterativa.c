/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio4iterativa.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 4 				 #################
// ###################################################################################
// ###################################################################################

/*
Funcion que dados dos enteros a, b, calcule la siguiente sucesion numerica de forma
iterativa gracias a un bucle while en base a los parametros de entrada y devuelve
el resultado como Long usando pares (tuplas) para calcular cada termino por separado
en base a las condiciones del ejercicio:
*/
long ejercicio4Iterativo(int numeroA, int numeroB) {

    hash_table mapa = hash_table_empty(int_pair_type, long_type);
    int i = 0;
    int_pair res_pair;

    while (i <= numeroA) {

        int j = 0;
        while (j <= numeroB) {

            pair p;
            if (i < 2 && j < 2) {

                int_pair p;
                p.a = i;
                p.b = j;
                hash_table_put(&mapa, &p, (long) (i + (j * j)));

            } else if (i < 2 || j < 2) {

                int_pair p;
                p.a = i;
                p.b = j;
                hash_table_put(&mapa, &p, (long) ((i * i) + j));

            } else {

                int_pair p;
                p.a = i;
                p.b = j;
                int_pair p1;
                p1.a = i / 2;
                p1.b = j - 1;
                int_pair p2;
                p2.a = i / 3;
                p2.b = j - 2;
                int_pair p3;
                p3.a = i - 2;
                p3.b = j / 4;
                long termino1 = hash_table_get(&mapa, p1);
                long termino2 = hash_table_get(&mapa, p2);
                long termino3 = hash_table_get(&mapa, p3);
                hash_table_put(&mapa, p, (termino1 + termino2 + termino3));

            }

            j++;

        }

        i++;
        res_pair.a = i;
        res_pair.b = j;

    }

    return hash_table_get(&mapa, res_pair);

}
