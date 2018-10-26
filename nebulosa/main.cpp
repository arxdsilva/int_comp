#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

// struct Robot {
//     char LastCommand[1];
// }

void printGrid(int grid[][20]);
int getDestination();

int main() {
    int grid[20][20];
    for ( int i = 0; i < 20; i++ ) {
        for ( int j = 0; j < 20; j++ ) {
            grid[i][j] = 0;
        }
    }
    cout << "Gerando a grid: \n\n";
    printGrid(grid);
    int response = 0;
    response = getDestination();
    cout << response;
    return 0;
}

void printGrid(int grid[20][20]) {
    for ( int i = 0; i < 20; i++ ) {
        cout << i << ": ";
        for ( int j = 0; j < 20; j++ ) {
            cout << " | " << grid[i][j];
        }
        cout << "\n";
    }
    return;
}

int getDestination() {
    int response = 0;
    cout << "\nDentre os numeros [0-19], escolha a coordenada de saida do robo: ";
    cin >> response;
    return response;
}