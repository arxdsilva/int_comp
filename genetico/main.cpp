#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <random>
#include <fstream>
#include <string>
#include <unistd.h>

int population, generations = 0;
int size = 300;
int maze[size][size];
void printInfos();
void initMaze();


int main() {
    printInfos();
    cout << "entre com a populacao: ";
    cin >> population;
    cout << "entre com o numero de geracoes: ";
    cin >> generations;
    initMaze();
    return 0;
}

void printInfos() {
    cout << ">> Algoritmo genetico  <<";
    cout << ">>                     <<";
    cout << ">> x-over: ponto       <<";
    cout << ">> %% x-over: 70%%     <<";
    cout << ">> mutacao: classica   <<";
    cout << ">> %% mutacao: 5%%     <<";
    cout << ">>                     <<";
    cout << ">> init aleatorio      <<";
    cout << ">> elitismo            <<";
    cout << ">> torneio             <<";
    cout << ">> cromossomo: xxxyyy  <<";
}

void generateMaze() {
    int startX, startY = 0;
    int endX, endY = 0;
    cout << "exemplo de labirinto com coordenadas x e y:\n";
    cout << "   0   1";
    cout << "0  x   x";
    cout << "1  x   x";
    cout << "\nforneca a coordenada (x) do final do labirinto:";
    cin >> endX;
    cout << "\nforneca a coordenada (y) do final do labirinto:";
    cin >> endY;
}

void initMaze() {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            maze[i][j] = 0;
        }
    }
}