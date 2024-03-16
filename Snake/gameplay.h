#pragma once

#define iFilas 10
#define iColumnas 20
//Funcion para crear e imprimir el tablero
void fTablero(char cTablero[iFilas][iColumnas], short sPuntuacion);
void fMostrar_Tablero(char cTablero[iFilas][iColumnas]);
void fMovimiento(char cTablero[iFilas][iColumnas], bool* pGameOver, short sPuntuacion);
void fFruta(char cTablero[iFilas][iColumnas]);
void fSerpiente();






