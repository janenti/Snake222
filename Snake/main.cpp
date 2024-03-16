#define FRAME_RATE 50

#include <iostream>
#include <thread>
#include <chrono>
#include <vector> 
#include "gameplay.h"
#include "keyboard.h"
#include <cstdlib>
#include <ctime>

//Variables
using namespace std;
#define iFilas 10
#define iColumnas 20
char cTablero[iFilas][iColumnas];
bool bGameOver = false;
bool* pGameover = &bGameOver;
short sPuntuacion = 0;

int main() {
    //While game is not over execute game loop
    //Push de la cabeza(La primera posicion esta hardcodeada)
    void fSerpiente();
    while (!bGameOver) { 

        system("cls"); 
        fTablero(cTablero, sPuntuacion); 
        fFruta(cTablero);
        fMovimiento(cTablero, pGameover, sPuntuacion);
        fMostrar_Tablero(cTablero);  
        sPuntuacion++;
        //Sleep main thread to control game speed execution
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));  
    }
    return 0;
}
