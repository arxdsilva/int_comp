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
int seedObstacle();
void addObstacles();

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
    int endX, endY = 0;
    cout << "exemplo de labirinto com coordenadas x e y:\n";
    cout << "       0       1   ..  299";
    cout << "0      x       x   ..  299";
    cout << "1      x       x   ..  299";
    cout << "..     ..      ..         ";
    cout << "299    299     299        ";
    cout << "\nforneca a coordenada (x) do final do labirinto:";
    cin >> endX;
    cout << "\nforneca a coordenada (y) do final do labirinto:";
    cin >> endY;
    maze[0][0] = 1;
    maze[endX][endY] = 3;
}

void initMaze() {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            maze[i][j] = 0;
        }
    }
}

int seedObstacle() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 299); // define the range
    return distr(eng);
}

void addObstacles() {
    int x, y, i = 0;
    while (i < 15) {
        x = seedObstacle();
        y = seedObstacle();
        if (maze[x][y] != 1 && maze[x][y] != 3) {
            maze[x][y] = 9;
            i++;
        }
    }
}