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








void main() {

    /*
    bool bGameOver = false;

    //While game is not over execute game loop
    while (!bGameOver) {

       // std::cout << "a" << std::endl;
        //Sleep main thread to control game speed execution
        //std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));
        
    }
    */
    fTablero(cTablero);
}
