#include <iostream>

#define iFilas 10
#define iColumnas 20
//Funcion para crear e imprimir el tablero
void fTablero(char cTablero[iFilas][iColumnas]) {
	using namespace std;
	//Declaracion de variables

	//Bucle para insertar los - y | al tablero, este bucle recorre todas las posiciones del array, si una posicion esta en la fila 0 o 19, este inserta un - en esa posicion, tambien si esa posicion esta en la columna 0 o 9 inserta un | y si no esta en ninguna de estas inserta un espacio en la posicion.
	for (int i = 0; i < iFilas; ++i)
	{
		for (int j = 0; j < iColumnas; ++j)
		{
			if (i == 0 || i == iFilas - 1)
				cTablero[i][j] = '-';
			else if (j == 0 || j == iColumnas - 1)
				cTablero[i][j] = '|';
			else
				cTablero[i][j] = ' ';
		}
	}

	//Bucle para mostrar el tablero
	for (int i = 0; i < iFilas; ++i)
	{
		for (int j = 0; j < iColumnas; ++j)
		{
			cout << cTablero[i][j];
		}
		cout << endl;
	}

}