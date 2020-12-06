/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#include "ejercicio1recursiva.h"

// ###################################################################################
// ###################################################################################
// ####################### 				EJERCICIO 1 				 #################
// ###################################################################################
// ###################################################################################

/*
 Funcion privada recursiva que se llama a si misma para reducir la matriz a la par que
 se comprueba si sus extremos siguen siendo distintos o no mediante el uso
 de HashSets para evitar emplear excesivos booleanos. Se llama tantas veces como sea
 necesario hasta que la matriz sea 2x2 o no se cumpla el requerimiento de que
 sus cuatro esquinas difieran:
 * Recursividad: 2 casos base + 1 caso recursivo multiple
 * Complejidad: ????????????????????????
 */
bool ejercicio1RecursivoC(matrix matriz, int fila, int columna, int dimension) {

	bool resultado = false;

	if (dimension == 2) {

		// Caso base:
		int A00 = matrix_get(matriz, 0, 0);
		int A01 = matrix_get(matriz, 0, matriz.nf - 1);
		int A10 = matrix_get(matriz, matriz.nf - 1, 0);
		int A11 = matrix_get(matriz, matriz.nf - 1, matriz.nf - 1);

		set extremos1 = set_empty(int_type);

		set_add(&extremos1, &A00);		// [0][0]
		set_add(&extremos1, &A01);		// [0][1]
		set_add(&extremos1, &A10);		// [1][0]
		set_add(&extremos1, &A11);		// [1][1]

		if (set_size(&extremos1) == 4) {

			resultado = true;

		} else {

			resultado = false;

		}

	} else {

		// Caso recursivo:
		int A00 = matrix_get(matriz, 0, 0);
		int A01 = matrix_get(matriz, 0, matriz.nf - 1);
		int A10 = matrix_get(matriz, matriz.nf - 1, 0);
		int A11 = matrix_get(matriz, matriz.nf - 1, matriz.nf - 1);

		set extremos2 = set_empty(int_type);

		set_add(&extremos2, &A00);		// [0][0]
		set_add(&extremos2, &A01);		// [0][1]
		set_add(&extremos2, &A10);		// [1][0]
		set_add(&extremos2, &A11);		// [1][1]

		if (set_size(&extremos2) == 4) {

			bool matriz1 = ejercicio1RecursivoC(matriz, fila, columna, (dimension / 2));
			bool matriz2 = ejercicio1RecursivoC(matriz, fila, (columna + dimension / 2), (dimension / 2));
			bool matriz3 = ejercicio1RecursivoC(matriz, (fila + dimension / 2), columna, (dimension / 2));
			bool matriz4 = ejercicio1RecursivoC(matriz, (fila + dimension / 2), (columna + dimension / 2), (dimension / 2));

			resultado = matriz1 && matriz2 && matriz3 && matriz4;

		} else {

			resultado = false;

		}

	}

	return resultado;

}

// Funcion que dada una matriz calcula primero si sus elementos en las cuatro
// esquinas son distintos, si no es así devuelve false, de lo contrario,
// parte la matriz en cuatro (las matrices siempre son cuadradas) y repite el proceso:
bool ejercicio1Recursivo(matrix matriz) {

	// Si los extremos de la matriz de entrada son iguales, hemos acabado;
	// si no, entramos en la funcion recursiva privada:
	if (extremosDistintosONo(matriz) == true) {

		return ejercicio1RecursivoPrivado(matriz);

	} else {

		return false;

	}

}

// Funcion recursiva que se llama a si misma para reducir la matriz una vez
// comprobado que sus cuatro esquinas iniciales son distintas. Hace uso de la funcion
// extremosDistintosONo() y calculaMatrizPartidaEnCuatro() tantas veces como sea
// necesario hasta que la matriz sea 2x2 o no se cumpla el requerimiento de que
// sus cuatro esquinas difieran:
/*
 * Recursividad: 2 casos base + 1 caso recursivo multiple
 * Complejidad: ????????????????????????
 */
bool ejercicio1RecursivoPrivado(matrix matriz) {

	char mem[2000];
	bool resultado = false;

	// Condicion de parada para una matriz cuadrada de dimension 2x2:
	if (matriz.nf == 2) {

		resultado = extremosDistintosONo(matriz);

	} else {

		if (extremosDistintosONo(matriz) == true) {

			// Llamada recursiva multiple:
			bool primerCuadrante = ejercicio1RecursivoPrivado(calculaMatrizPartidaEnCuatro(matriz, 0, 0));
			bool segundoCuadrante = ejercicio1RecursivoPrivado(calculaMatrizPartidaEnCuatro(matriz, 0, matriz.nf));
			bool tercerCuadrante = ejercicio1RecursivoPrivado(calculaMatrizPartidaEnCuatro(matriz, matriz.nf, 0));
			bool cuartoCuadrante = ejercicio1RecursivoPrivado(calculaMatrizPartidaEnCuatro(matriz, matriz.nf, matriz.nf));

			resultado = (primerCuadrante && segundoCuadrante && tercerCuadrante && cuartoCuadrante);

		} else {

			resultado = false;

		}

	}

	return resultado;

}

// Funcion privada que dada una matriz y la fila/columna desde la que partir, corta la matriz de entrada en una matriz
// mas pequeña:
matrix calculaMatrizPartidaEnCuatro(matrix matriz, int filaDePartida, int columnaDePartida) {

	int fila = 0;
	int columna = 0;
	int ultimaFila = 0;
	int primeraFila = 0;
	int ultimaColumna = 0;
	int primeraColumna = 0;
	int rango[(matriz.nf / 2) * (matriz.nf / 2)];
	matrix resultado = matrix_of_array(rango, matriz.nf / 2, matriz.nf / 2);
	//matrix resultado = new Integer [matriz.nf / 2][matriz.nf / 2];

	// Fila desde la que partimos:
	if (filaDePartida < matriz.nf) {

		primeraFila = 0;
		ultimaFila = matriz.nf / 2;

	} else {

		primeraFila = matriz.nf / 2;
		ultimaFila = matriz.nf;

	}

	// Columna desde la que partimos:
	if (columnaDePartida < matriz.nf) {

		primeraColumna = 0;
		ultimaColumna = matriz.nf / 2;

	} else {

		primeraColumna = matriz.nf / 2;
		ultimaColumna = matriz.nf;

	}

	// Creamos el array bidimensional:
	while (primeraFila < ultimaFila) {

		while (primeraColumna < ultimaColumna) {

			//resultado [fila][columna] = matriz [primeraFila][primeraColumna];
			matrix_set(resultado, fila, columna, matrix_get(matriz, primeraFila, primeraColumna));

			columna++;
			primeraColumna++;

		}

		columna = 0;

		// Saltar a la siguiente columna:
		if (columnaDePartida < matriz.nf) {

			primeraColumna = 0;

		} else {

			primeraColumna = matriz.nf / 2;

		}

		fila++;
		primeraFila++;

	}

	return resultado;

}

// Posiciones de la matriz:
/*
 * A00 = [0][0]									Esquina superior izquierda
 * A0n = [0][matriz.nf - 1]						Esquina superior derecha
 * An0 = [matriz.nf - 1][0]						Esquina inferior izquierda
 * Ann = [matriz.nf - 1][matriz.nf - 1]			Esquina inferior derecha
 */

// Funcion que dada una matriz cuadrada n*n calcula si sus valores
// localizados en las 4 esquinas son distintos o no:
bool extremosDistintosONo(matrix matriz) {

	/*
	bool IzqSupIgualADrcSup = matriz [0][0] != matriz [0][matriz.nf - 1];
	bool IzqSupIgualAIzqInf = matriz [0][0] != matriz [matriz.nf - 1][0];
	bool IzqSupIgualADrcInf = matriz [0][0] != matriz [matriz.nf - 1][matriz.nf - 1];
	bool DrcSupIgualAIzqInf = matriz [0][matriz.nf - 1] != matriz [matriz.nf - 1][0];
	bool DrcSupIgualADrcInf = matriz [0][matriz.nf - 1] != matriz [matriz.nf - 1][matriz.nf - 1];
	bool IzqInfIgualADrcInf = matriz [matriz.nf - 1][0] != matriz [matriz.nf - 1][matriz.nf - 1];
	*/

	bool IzqSupIgualADrcSup = matrix_get(matriz, 0, 0) != matrix_get(matriz, 0, matriz.nf - 1);
	bool IzqSupIgualAIzqInf = matrix_get(matriz, 0, 0) != matrix_get(matriz, matriz.nf - 1, 0);
	bool IzqSupIgualADrcInf = matrix_get(matriz, 0, 0) != matrix_get(matriz, matriz.nf - 1, matriz.nf - 1);
	bool DrcSupIgualAIzqInf = matrix_get(matriz, 0, matriz.nf - 1) != matrix_get(matriz, matriz.nf - 1, 0);
	bool DrcSupIgualADrcInf = matrix_get(matriz, 0, matriz.nf - 1) != matrix_get(matriz, matriz.nf - 1, matriz.nf - 1);
	bool IzqInfIgualADrcInf = matrix_get(matriz, matriz.nf - 1, 0) != matrix_get(matriz, matriz.nf - 1, matriz.nf - 1);

	return (IzqSupIgualADrcSup && IzqSupIgualAIzqInf && IzqSupIgualADrcInf && DrcSupIgualAIzqInf && DrcSupIgualADrcInf && IzqInfIgualADrcInf);

}
