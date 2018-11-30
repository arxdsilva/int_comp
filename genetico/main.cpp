#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <iomanip>

int steps = 0;
int endX, endY = 0;
int population, generations = 0;
int const size = 300;
int randomNum();
void printMaze(int maze[][size]);
void printInfos();
void initMaze(int maze[][size]);
void addObstacles(int maze[][size]);
void generateMaze(int maze[][size]);
string mountGene(int , int);
std::vector<string> inputRandomNodes(std::vector<string>, int [][size]);

int main() {
    int maze[size][size];
    printInfos();
    // cout << "entre com a populacao: ";
    // cin >> population;
    // cout << "entre com o numero de geracoes: ";
    // cin >> generations;
    initMaze(maze);
    // printMaze(maze);
    generateMaze(maze);
    std::vector<string> genes;
    string firstGene = mountGene(0,0);
    genes.push_back(firstGene);
    genes = inputRandomNodes(genes, maze);
    string lastGene = mountGene(endX, endY);
    genes.push_back(lastGene);
    return 0;
}

std::vector<string> inputRandomNodes(std::vector<string> genes, int maze[][size]) {
    int x, y, i = 0;
    while(i < 5){
        x = randomNum();
        y = randomNum();
        if ((maze[x][y] == 3) || (maze[x][y] == 1) || (maze[x][y] == 9)) {
            continue;
        }
        maze[x][y] = 9;
        i++;
        string gene = mountGene(x,y);
        genes.push_back(gene);
    }
    return genes;
}

string mountGene(int x, int y) {
    std::string xString = std::to_string(x);
    std::string yString = std::to_string(y);
    if (xString.size() < 3) {
        xString = std::string(3-xString.size(), '0').append(xString);
    }
    if (yString.size() < 3) {
        yString = std::string(3-yString.size(), '0').append(yString);
    }
    return xString + yString;
}

void printInfos() {
    cout << ">>     Algoritmo genetico      <<\n";
    cout << ">>                             <<\n";
    cout << ">>     x-over: ponto           <<\n";
    cout << ">>     %% x-over: 70%%         <<\n";
    cout << ">>     mutacao: classica       <<\n";
    cout << ">>     %% mutacao: 5%%         <<\n";
    cout << ">>                             <<\n";
    cout << ">>     init aleatorio          <<\n";
    cout << ">>     elitismo                <<\n";
    cout << ">>     torneio                 <<\n";
    cout << ">>     cromossomo: xxxyyy      <<\n\n";
}

void generateMaze(int maze[][size]) {
    cout << "exemplo de labirinto com coordenadas x e y:\n";
    cout << "       0       1   ..  299\n";
    cout << "0      x       x   ..  299\n";
    cout << "1      x       x   ..  299\n";
    cout << "..     ..      ..         \n";
    cout << "299    299     299        \n";
    cout << "\nforneca a coordenada (x) do final do labirinto:";
    cin >> endX;
    cout << "\nforneca a coordenada (y) do final do labirinto:";
    cin >> endY;
    maze[0][0] = 1;
    maze[endX][endY] = 3;
    addObstacles(maze);
}

void initMaze(int maze[][size]) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            maze[i][j] = 0;
        }
    }
}

int randomNum() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 299); // define the range
    return distr(eng);
}

void addObstacles(int maze[][size]) {
    int x, y, i = 0;
    while (i < 15) {
        x = randomNum();
        y = randomNum();
        if (maze[x][y] != 1 && maze[x][y] != 3) {
            maze[x][y] = 9;
            i++;
        }
    }
}

void printMaze(int maze[][size]) {
    for ( int i = 0; i < size; i++ ) {
        cout << i << ": ";
        for ( int j = 0; j < size; j++ ) {
            cout << " | " << maze[i][j];
        }
        cout << "\n";
    }
    return;
}