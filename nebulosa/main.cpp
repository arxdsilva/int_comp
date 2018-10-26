#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <random>

// struct Robot {
//     char LastCommand[1];
//     int lastPosition[][];
// }

int const size = 10;
int const barriers = 3;
void printGrid(int grid[][size]);
void addObstacles(int grid[][size]);
int getDestination();
int seedObstacle();

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
        if (grid[x][y] == 0) {
            grid[x][y] = 7;
            i++;
            if ((grid[x-1][y] == 0) && ((x-1) > 0)) {
                grid[x-1][y] = 7;
            } else {
                grid[x+1][y] = 7;
            }
            if ((grid[x][y-1] == 0) && ((y-1)>0)) {
                grid[x][y-1] = 7;
            } else {
                grid[x][y+1] = 7;
            }
        }
        cout <<"\n"<< x << " >>>> " << y << "\n";
    }
    return;
}