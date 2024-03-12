#include <iostream>
#include "keyboard.h"
using namespace std;
#define iFilas 10
#define iColumnas 20

//Variables Globales
int xCabeza = 5;    
int yCabeza = 10;
short sContador = 0;
char cFruta = 'O';
char cCabeza = 'X';
const char xMargen = '|';
const char yMargen = '-';
//Funcion para crear e imprimir el tablero
void fTablero(char cTablero[iFilas][iColumnas]) {
	//Declaracion de variables
	//Bucle para insertar los - y | al tablero, este bucle recorre todas las posiciones del array, si una posicion esta en la fila 0 o 19, este inserta un - en esa posicion, tambien si esa posicion esta en la columna 0 o 9 inserta un | y si no esta en ninguna de estas inserta un espacio en la posicion.
	for (int i = 0; i < iFilas; ++i)
	{
		for (int j = 0; j < iColumnas; ++j)
		{
			if (i == 0 || i == iFilas - 1)
				cTablero[i][j] = yMargen;
			else if (j == 0 || j == iColumnas - 1)
				cTablero[i][j] = xMargen;
			else
				cTablero[i][j] = ' ';
		}
	}
	cTablero[xCabeza][yCabeza] = cCabeza;  
}

void fFruta() {




}

void fMostrar_Tablero(char cTablero[iFilas][iColumnas]) {
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

void fMovimiento(char cTablero[iFilas][iColumnas], bool bGameOver) {
	if (IsWPressed())
	{ 
		xCabeza--;
	}
	else if (IsSPressed())
	{ 
		xCabeza++;
		
	}
	else if (IsAPressed())
	{
		yCabeza--;
	}
	else if (IsDPressed())
	{
		yCabeza++;

	} 
	else
	{

	}

	for (int i = xCabeza; i < sContador; ++i)
	{
		for (int j = yCabeza; j < sContador; ++j)
		{
			
		}
	}


	if (cTablero[xCabeza][yCabeza] == cFruta)
	{
		sContador++;

	}
}

