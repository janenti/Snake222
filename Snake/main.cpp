#define FRAME_RATE 150

#include <iostream>
#include <thread>
#include <chrono>
#include "gameplay.h"
#include "keyboard.h"
using namespace std;
#define iFilas 10
#define iColumnas 20
char cTablero[iFilas][iColumnas];
short sScore = 0; 

void main() {
    //fSerpiente(cTablero);
    bool bGameOver = false;

    fMostrar_Tablero(cTablero); 
    //While game is not over execute game loop
    
    while (!bGameOver) {

        system("cls");
        fTablero(cTablero); 
        fMovimiento(cTablero, bGameOver);
        fMostrar_Tablero(cTablero);  
        //Sleep main thread to control game speed execution
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));  
    }
}
