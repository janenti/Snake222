#include <iostream>
#include "keyboard.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
srand(static_cast<unsigned>(time(nullptr)));  // Semilla de srand

#define iFilas 10
#define iColumnas 20
int xCabeza = 5;    
int yCabeza = 10;
short sContador = 0;
char cFruta = 'O';
char cCabeza = 'X';
char cCuerpo;
const char xMargen = '|';
const char yMargen = '-';
short sPuntuacion;


short sDireccion = 0; // 1 Arriba, 2 Abajo, 3 izquierda, 4 Derecha
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

void fMovimiento(char cTablero[iFilas][iColumnas], bool* pGameOver) {
	if (IsWPressed()) {
		if (xCabeza - 1 < 0 || cTablero[xCabeza - 1][yCabeza] == xMargen) {
			cout << "Game Over!!!\n";
			*pGameOver = true;
		}
		else {
			xCabeza--;
			sDireccion = 1;
		}
	}
	else if (IsSPressed()) {
		if (xCabeza + 1 >= iFilas || cTablero[xCabeza + 1][yCabeza] == xMargen) {
			cout << "Game Over!!!\n";
			*pGameOver = true;
		}
		else {
			xCabeza++;
			sDireccion = 2;
		}
	}
	else if (IsAPressed()) {
		if (yCabeza - 1 < 0 || cTablero[xCabeza][yCabeza - 1] == yMargen) {
			cout << "Game Over!!!\n";
			*pGameOver = true;
		}
		else {
			yCabeza--;
			sDireccion = 3;
		}
	}
	else if (IsDPressed()) {
		if (yCabeza + 1 >= iColumnas || cTablero[xCabeza][yCabeza + 1] == yMargen) {
			cout << "Game Over!!!\n";
			*pGameOver = true;
		}
		else {
			yCabeza++;
			sDireccion = 4;
		}
	}
	else
	{
		switch (sDireccion)
		{
		case 1:
			if (xCabeza - 1 < 0 || cTablero[xCabeza - 1][yCabeza] == xMargen) {
				cout << "Game Over!!!\n";
				*pGameOver = true;
			}
			else {
				xCabeza--;
			}
			break;
		case 2:
			if (xCabeza + 1 >= iFilas || cTablero[xCabeza + 1][yCabeza] == xMargen) {
				cout << "Game Over!!!\n";
				*pGameOver = true;
			}
			else {
				xCabeza++;
			}
			break;
		case 3:
			if (yCabeza - 1 < 0 || cTablero[xCabeza][yCabeza - 1] == yMargen) {
				cout << "Game Over!!!\n";
				*pGameOver = true;
			}
			else {
				yCabeza--;
			}
			break;
		case 4:
			if (yCabeza + 1 >= iColumnas || cTablero[xCabeza][yCabeza + 1] == yMargen) {
				cout << "Game Over!!!\n";
				*pGameOver = true;
			}
			else {
				yCabeza++;
			}
			break;
		}
	}
}





