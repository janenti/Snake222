#include <iostream>
#include "keyboard.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Para las dimensiones del tablero
#define iFilas 10
#define iColumnas 20
// Variables que muestran los diferentes elementos que hay en el tablero
char cFruta = 'O';
char cCabeza = 'X';
char cCuerpo = 'x';
char xMargen = '|';
char yMargen = '-';
// Posicion inicial de la cabeza
int xCabeza = 5;    
int yCabeza = 10;
// Para que se guarde la posicion de la fruta
int xFruta;
int yFruta;
// Contador de cuantos segmentos de cuerpo hay
short sContador = 0;
// Booleano para la generacion de las coordenadas de la fruta
bool bSemilla = false;
// Vectores para el cuerpo
vector<int> vSerpienteX;
vector<int> vSerpienteY;


// Funcion para el primer push del cuerpo
void fSerpiente() {

	vSerpienteX.push_back(xCabeza);
	vSerpienteY.push_back(yCabeza);
}

short sDireccion = 0; // 1 Arriba, 2 Abajo, 3 izquierda, 4 Derecha
// Funcion para crear e imprimir el tablero
void fTablero(char cTablero[iFilas][iColumnas], short sPuntuacion) {
	// Bucle para insertar los - y | al tablero, este bucle recorre todas las posiciones del array, si una posicion esta en la fila 0 o 19, este inserta un - en esa posicion, tambien si esa posicion esta en la columna 0 o 9 inserta un | y si no esta en ninguna de estas inserta un espacio en la posicion.
	for (short i = 0; i < iFilas; ++i)
	{
		for (short j = 0; j < iColumnas; ++j)
		{
			if (i == 0 || i == iFilas - 1)
				cTablero[i][j] = yMargen;
			else if (j == 0 || j == iColumnas - 1)
				cTablero[i][j] = xMargen;
			else
				cTablero[i][j] = ' ';
		}
	}
	
	cTablero[xFruta][yFruta] = cFruta;
	cout << "\nPuntuacion: " << sPuntuacion << endl;
}

void fFruta(char cTablero[iFilas][iColumnas]) {
	//Semilla de srand
	srand(static_cast<unsigned int>(std::time(nullptr))); 
	//Generar la posicion de la fruta
	while (bSemilla == false)
	{
		xFruta = rand() % 10;
		yFruta = rand() % 20;
		//Verifica que la casilla este vacia, si no lo esta se repite el bucle
		if (cTablero[xFruta][yFruta] == ' ')
		{
			cTablero[xFruta][yFruta] = cFruta;
			//el booleano declarado fuera de la funcion pasa a true asi que la funcion no hace nada hasta que se coma la fruta.
			bSemilla = true;
		}
	}
}


void fMovimiento(char cTablero[iFilas][iColumnas], bool* pGameOver, short sPuntuacion) {
	//Movimiento anterior

	//Movimiento de la cabeza
	if (IsWPressed()) {
		//Verificacion para que no se choque con los bordes ni la cabeza ni el cuerpo
		if (xCabeza - 1 < 0 || cTablero[xCabeza - 1][yCabeza] == xMargen || cTablero[xCabeza - 1][yCabeza] == cCuerpo) {
			cout << "Game Over!!!\n";
			//Para el game over lo hago con un puntero, en un momento no me funcionaba y lo solucione asi
			*pGameOver = true;
		}
		else {

			sDireccion = 1;
		}
	}
	else if (IsSPressed()) {
		if (xCabeza + 1 >= iFilas || cTablero[xCabeza + 1][yCabeza] == xMargen || cTablero[xCabeza + 1][yCabeza ] == cCuerpo) {
			cout << "Game Over!!!\n";
			*pGameOver = true;
		}
		else {
			xCabeza++;
			sDireccion = 2;
		}
	}
	else if (IsAPressed()) {
		if (yCabeza - 1 < 0 || cTablero[xCabeza][yCabeza - 1] == yMargen || cTablero[xCabeza][yCabeza - 1] == cCuerpo) {
			cout << "Game Over!!!\n";
			*pGameOver = true;
		}
		else {
			yCabeza--;
			sDireccion = 3;
		}
	}
	else if (IsDPressed()) {
		if (yCabeza + 1 >= iColumnas || cTablero[xCabeza][yCabeza + 1] == yMargen || cTablero[xCabeza][yCabeza + 1] == cCuerpo) {
			cout << "Game Over!!!\n";
			*pGameOver = true;
		}
		else {
			yCabeza++;
			sDireccion = 4;
		}
	}
	//Movimiento sin tocar las teclas(mira cual fue la ultima tecla pulsada, el codigo para el movimiento es identico al anterior menos la variable sDireccion que no es necesaria)
	else
	{
		//El codigo es el mismo que el de arriba
		switch (sDireccion)
		{
		case 1:
			if (xCabeza - 1 < 0 || cTablero[xCabeza - 1][yCabeza] == xMargen || cTablero[xCabeza - 1][yCabeza] == cCuerpo) {
				cout << "Game Over!!!\n";
				*pGameOver = true;
			}
			else {
				xCabeza--;
				sDireccion = 1;
			}
			break;
		case 2:
			if (xCabeza + 1 >= iFilas || cTablero[xCabeza + 1][yCabeza] == xMargen || cTablero[xCabeza + 1][yCabeza] == cCuerpo) {
				cout << "Game Over!!!\n";
				*pGameOver = true;
			}
			else {
				xCabeza++;
				sDireccion = 2;
			}
			break;
		case 3:
			if (yCabeza - 1 < 0 || cTablero[xCabeza][yCabeza - 1] == yMargen || cTablero[xCabeza][yCabeza - 1] == cCuerpo) {
				cout << "Game Over!!!\n";
				*pGameOver = true;
			}
			else {
				yCabeza--;
				sDireccion = 3;
			}
			break;
		case 4:
			if (yCabeza + 1 >= iColumnas || cTablero[xCabeza][yCabeza + 1] == yMargen || cTablero[xCabeza][yCabeza + 1] == cCuerpo) {
				cout << "Game Over!!!\n";
				*pGameOver = true;
			}
			else {
				yCabeza++;
				sDireccion = 4;
			}
			break;
		}
	}
	// Si se come una fruta, agregamos una nueva parte del cuerpo
	// No entiendo porque en la primera fruta que se come la serpiente esta no augmenta, pero cuando te comes mas si.
	if (cTablero[xCabeza][yCabeza] == cFruta) {
		vSerpienteX.push_back(xCabeza);
		vSerpienteY.push_back(yCabeza);
		sContador++;
		sPuntuacion + 15;
		bSemilla = false;
	}

	// Actualizamos la posicion del cuerpo de la serpiente
	for (short i = sContador - 1; i > 0; i--) {
		vSerpienteX[i] = vSerpienteX[i - 1];
		vSerpienteY[i] = vSerpienteY[i - 1];
	}

	// Guardamos la posicion anterior de la cabeza
	short xCabezaAnterior = xCabeza;
	short yCabezaAnterior = yCabeza;

	// Actualizamos la posicion de la cabeza porque sino se solapa con el cuerpo
	if (sContador > 0) {
		vSerpienteX[0] = xCabezaAnterior;
		vSerpienteY[0] = yCabezaAnterior;
	}

	// Actualizamos el tablero con la nueva posición de la cabeza y el cuerpo
	cTablero[xCabezaAnterior][yCabezaAnterior] = cCabeza;
	for (short i = 1; i < sContador; ++i) {
		cTablero[vSerpienteX[i]][vSerpienteY[i]] = cCuerpo;
	}
}


	


	
void fMostrar_Tablero(char cTablero[iFilas][iColumnas]) {
	// Bucle para mostrar el tablero
	for (int i = 0; i < iFilas; ++i)
	{
		for (int j = 0; j < iColumnas; ++j)
		{
			cout << cTablero[i][j];
		}
		cout << endl;
	}
}





