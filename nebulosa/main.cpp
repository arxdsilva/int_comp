#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <random>
#include <fstream>
#include <string>
#include <unistd.h>

// #include <json.hpp>

// struct Robot {
//     char LastCommand[1];
//     int lastPosition[][];
// }
unsigned int microseconds =100000;
int const size = 40;
int const barriers = 5;
void printGrid(int grid[][size]);
void addObstacles(int grid[][size]);
int getDestination();
int seedObstacle();
void startRobot(int grid[][size], int);

int main() {
    int grid[size][size];
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            grid[i][j] = 0;
        }
    }
    cout << "Gerando a grid: \n\n";
    printGrid(grid);
    int response = 0;
    response = getDestination();
    cout << "Local escolhido: [" << response << "][40] escolhido.\n";
    grid[response][size-1] = 1;
    cout << "Nova grid com a saida: \n";
    printGrid(grid);
    addObstacles(grid);
    printGrid(grid);
    cout << "Inicializando robo na posicao [0,0]\n";
    startRobot(grid, response);
    return 0;
}

void printGrid(int grid[size][size]) {
    for ( int i = 0; i < size; i++ ) {
        cout << i << ": ";
        for ( int j = 0; j < size; j++ ) {
            cout << " | " << grid[i][j];
        }
        cout << "\n";
    }
    return;
}

int getDestination() {
    int response = 0;
    cout << "\nDentre os numeros [0-19] (coordenada y), escolha a coordenada de saida do robo: ";
    cin >> response;
    if ((response >= 20) || (response < 0)){
        response = getDestination();
    }
    return response;
}

int seedObstacle() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, size); // define the range
    return distr(eng);
}

void addObstacles(int grid[][size]) {
    int x= 0;
    int y= 0;
    int i= 0;
    while (i<barriers){
        x = seedObstacle();
        y = seedObstacle();
        if ((grid[x][y] == 0) && (grid[x-1][y]==0) && (grid[x+1][y]==0) && (grid[x][y+1]==0) && (grid[x][y-1]==0) && (x != 0)&& (y != 0)) {
            grid[x][y] = 7;
            i++;
            if ((grid[x-1][y] == 0) && (x > 0)) {
                grid[x-1][y] = 7;
            } else {
                grid[x+1][y] = 7;
            }
            if ((grid[x][y-1] == 0) && (y > 0)) {
                grid[x][y-1] = 7;
            } else {
                grid[x][y+1] = 7;
            }
        }
        cout <<"\n"<< x << "," << y;
    }
    return;
}

    // std::ifstream i("states.json");
    // json states;
    // i >> states;
void startRobot(int grid[][size], int finalY) {
    int posX = 0;
    int posY = 0;
    int posXNew = 0;
    int posYNew = 0;
    grid[posX][posY] = 3;
    printGrid(grid);
    std::string lastMove = "D";
    while(grid[finalY][size-1] != 3){
        if (posY < 5) {
            if ((grid[posX][posY+1] == 0) && (lastMove != "E")) {
                posYNew = posY + 1;
                lastMove = "D";
            } else if ((grid[posX+1][posY] == 0))  {
                posXNew = posX + 1;
                lastMove = "S";
            } else if ((grid[posX][posY-1] == 0)) {
                posYNew = posY -1;
                lastMove = "E";
            }
            grid[posX][posY] = 0;
            grid[posXNew][posYNew] = 3;
            posX = posXNew;
            posY = posYNew;
            usleep(microseconds);
            cout << "Andando...\n\n";
            printGrid(grid);
        } else {
            if (((grid[posX][posY+1] == 0) || (grid[posX][posY+1] == 1)) && (lastMove != "E") && (posY+1 < size)) {
                posYNew = posY + 1;
                lastMove = "D";
            } else if (((grid[posX+1][posY] == 0) || ((grid[posX+1][posY] == 1))) && (lastMove != "N")) {
                posXNew = posX + 1;
                lastMove = "S";
            } else if (((grid[posX][posY-1] == 0) || (grid[posX][posY-1] == 1))) {
                posYNew = posY -1;
                lastMove = "E";
            } else if ((grid[posX-1][posY] == 0) || (grid[posX-1][posY] == 1)) {
                posYNew = posY -1;
                lastMove = "N";
            }
            cout << "\n>>>>>>>>>>>" << (grid[posX-1][posY] == 0) << " | " << grid[posX-1][posY] << "\n";
            grid[posX][posY] = 0;
            grid[posXNew][posYNew] = 3;
            posX = posXNew;
            posY = posYNew;
            usleep(microseconds);
            cout << "Andando... CLOSE " << lastMove << " \n\n";
            printGrid(grid);
        }
    }
    return;
}