#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

// struct Robot {
//     char LastCommand[1];
// }

int const size = 20;
void printGrid(int grid[][size]);
int getDestination();

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
    grid[response][size] = 1;
    cout << "Nova grid com a saida: \n";
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