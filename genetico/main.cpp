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

struct Xsome {
    std::vector<string> Vals;
    int steps;
};

int steps = 0;
int endX, endY = 0;
int stateX, stateY = 0;
int population, generations = 0;
int const size = 300;
int randomNum(int, int);
void printInfos();
void initMaze(int maze[][size]);
void addObstacles(int maze[][size]);
void clearMaze(int maze[][size]);
string mountGene(int , int);
std::vector<string> inputRandomNodes(std::vector<string>, int [][size]);
Xsome evaluateXsome(std::vector<string>, int [][size]);
void walkRight(int [][size], int, int);
void walkLeft(int [][size], int, int);
void walkUp(int [][size], int, int);
void walkDown(int [][size], int, int);
Xsome betterXsome(std::vector<Xsome>);
Xsome randFromGeneration(std::vector<Xsome>);
Xsome newXsome(int [][size]);
void xOver(Xsome, Xsome, int [][size]);
void setupMazeFromXsome(std::vector<string>, int [][size]);
void mutate(Xsome, int [][size]);
string randGene(int [][size]);


void main() {
    int maze[size][size];
    printInfos();
    cout << "entre com a populacao: \n";
    cin >> population;
    cout << "entre com o numero de geracoes: \n";
    cin >> generations;
    initMaze(maze);
    std::vector<Xsome> nextGenList;
    for(int i = 0; i < generations; i++){
        std::vector<Xsome> generationList;
        std::vector<Xsome> tournamentList;
        if (i == 0) {
            for(int k = 0; k < population; k++){
                clearMaze(maze);
                Xsome xs = newXsome(maze);
                generationList.push_back(xs);
            }
        } else {
            for(int i = 0; i < nextGenList.size(); i++){
                generationList.push_back(nextGenList[i]);
            }
            for(int i = nextGenList.size()-1; i < population; i++){
                clearMaze(maze);
                Xsome xs = newXsome(maze);
                generationList.push_back(xs);
            }            
        }
        Xsome better = betterXsome(generationList);
        cout << ">>         Generation          <<";
        for(int i = 0; i < better.Vals.size(); i++){
            cout << ">>     Xsome:"<< better.better.Vals[i] << "            <<";
        }
        cout << ">>     eval: " << better.steps << "         <<";
        nextGenList.push_back(better);        
        for(int i = 0; i < 2; i++){
            Xsome xs = randFromGeneration(generationList);
            tournamentList.push_back(xs);
        }
        std::vector<Xsome> xOverList;
        xOver(tournamentList[0], tournamentList[1], maze);
        mutate(tournamentList[0], maze);
        mutate(tournamentList[1], maze);
        nextGenList.push_back(tournamentList[0]);
        nextGenList.push_back(tournamentList[1]);
    }
}

void mutate(Xsome xs, int maze[][size]) {
    double mutationRate = 0.05;
    for(int i = 1; i < xs.Vals.size()-1; i++){
        double mutation = randomNum(0, 100)/100;
        if (mutation < mutationRate) {
            string newGene = randGene(maze);
            xs.Vals[i] = newGene; 
        }
    }
    setupMazeFromXsome(xs.Vals, maze);
    xs = evaluateXsome(xs.Vals, maze);
}

string randGene(int maze[][size]) {
    int x, y, i = 0;
    while (i == 0) {
        x = randomNum(0, size -1);
        y = randomNum(0, size -1);
        if ((maze[x][y] == 3) || (maze[x][y] == 1) || (maze[x][y] == 9)) {
            continue;
        }
        i++;
    }
    return mountGene(x,y);
}

void xOver(Xsome c1, Xsome c2, int maze[][size]) {
    double xRate = 0.7;
    double xOverResult = randomNum(0, 100)/100;
    int xOverPoint = randomNum(1,5);
    Xsome newC1 = {};
    Xsome newC2 = {};
    if (xOverResult < xRate) {
        for(int i = 0; i < xOverPoint; i++){
            newC1.push_back(c1.Vals[i]);
            newC2.push_back(c2.Vals[i]);
        }
        for(int i = xOverPoint; i < c1.Vals.size(); i++){
            newC1.push_back(c2.Vals[i]);
            newC2.push_back(c1.Vals[i]);
        }
        setupMazeFromXsome(newC1.Vals, maze);
        c1 = evaluateXsome(newC1.Vals, maze);
        setupMazeFromXsome(newC2.Vals, maze);
        c2 = evaluateXsome(newC2.Vals, maze);
    }
}

void setupMazeFromXsome(std::vector<string> list, int maze[][size]) {
    clearMaze(maze);
    for(int i = 1; i < 6; i++){
        string coordStr = list[i];
        int x = atoi(coordStr.substr(0,3).c_str());
        int y = atoi(coordStr.substr(3,6).c_str());
        maze[x][y] = 3;
    }
}

Xsome randFromGeneration(std::vector<Xsome> list) {
    std::vector<Xsome> chosen;
    int rand1 = 0;
    int rand2 = 0;
    while (rand1 == rand2) {
        int rand1 = randomNum(0, list.size()-1);
        int rand2 = randomNum(0, list.size()-1);
    }
    chosen.push_back(list[rand1]);
    chosen.push_back(list[rand2]);
    Xsome xs = betterXsome(chosen);
    return xs;
}

Xsome betterXsome(std::vector<Xsome> Xsomes) {
    Xsome xs = {};
    for(int i = 0; i < Xsomes.size(); i++){
        if (i == 0) {
            xs = Xsomes[i];
            continue;
        }
        if (xs.steps > Xsomes[i].steps) {
            xs = Xsomes[i];
        }
    }
    return xs;
}

Xsome newXsome(int maze[][size]) {
    std::vector<string> genes;
    string firstGene = mountGene(0,0);
    genes.push_back(firstGene);
    genes = inputRandomNodes(genes, maze);
    string lastGene = mountGene(endX, endY);
    genes.push_back(lastGene);
    Xsome x = evaluateXsome(genes, maze);
    return xs;
}

Xsome evaluateXsome(std::vector<string> genes, int maze[][size]){
    int stateXC = 0;
    int stateYC = 0;
    bool keepGoing = true;
    int stepz = 0;
    for(int i = 1; i < genes.size(); i++){
        string destString = genes[i];
        int destX, destY = 0;
        destX = atoi(destString.substr(0,3).c_str());
        destY = atoi(destString.substr(3,6).c_str());
        while (maze[destX][destY] == 3) {
            if ((stateXC < destX) && (stateXC+1 < size) && (maze[stateXC+1][stateYC] != 4)) {
                walkRight(maze, stateXC, stateXY);
                stateXC += 1;
                stepz++;
            } else if ((stateYC < destY) && (stateYC+1 < size) && (maze[stateXC][stateYC+1] != 4)) {
                maze[stateXC][stateYC] = 0;
                maze[stateXC][stateYC+1] = 1;
                stateYC += 1;
                stepz++;
            } else if ((stateXC > destX) && (stateXC-1 >= 0) && (maze[stateXC-1][stateYC] != 4)) {
                maze[stateXC][stateYC] = 0;
                maze[stateXC-1][stateYC] = 1;
                stateXC -= 1;
                stepz++;
            } else if ((stateYC-1 >= 0) && (maze[stateXC][stateYC+1] != 4)) {
            // } else {    
                maze[stateXC][stateYC] = 0;
                maze[stateXC][stateYC-1] = 1;
                stateYC -= 1;
                stepz++;
            }
        }
    }
    Xsome s = {genes, stepz};
    return s;
}

void walkRight(int maze[][size], int x, int y) {
    maze[x][y] = 0;
    maze[x+1][y] = 1;
}

void walkLeft(int maze[][size], int x, int y) {
    maze[x][y] = 0;
    maze[x-1][y] = 1;
}


void walkDown(int maze[][size], int x, int y) {
    maze[x][y] = 0;
    maze[x][y+1] = 1;
}

void walkUp(int maze[][size], int x, int y) {
    maze[x][y] = 0;
    maze[x][y-1] = 1;
}

std::vector<string> inputRandomNodes(std::vector<string> genes, int maze[][size]) {
    int x, y, i = 0;
    while(i < 5){
        x = randomNum(0, size -1);
        y = randomNum(0, size -1);
        if ((maze[x][y] == 3) || (maze[x][y] == 1) || (maze[x][y] == 9)) {
            continue;
        }
        maze[x][y] = 3;
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
    cout << ">>     % x-over: 70%           <<\n";
    cout << ">>     mutacao: classica       <<\n";
    cout << ">>     % mutacao: 5%           <<\n";
    cout << ">>                             <<\n";
    cout << ">>     init aleatorio          <<\n";
    cout << ">>     elitismo                <<\n";
    cout << ">>     torneio                 <<\n";
    cout << ">>     cromossomo: xxxyyy      <<\n\n";
}

void clearMaze(int maze[][size]) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            maze[i][j] = 0;
        }
    }
    maze[0][0] = 1;
    maze[endX][endY] = 9;
    addObstacles(maze);
}

void initMaze(int maze[][size]) {
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
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            maze[i][j] = 0;
        }
    }
    maze[0][0] = 1;
    maze[endX][endY] = 9;
    addObstacles(maze);
}

int randomNum(int start, int end) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(start, end); // define the range
    return distr(eng);
}

void addObstacles(int maze[][size]) {
    int x, y, i = 0;
    while (i < 15) {
        x = randomNum(0, size -1);
        y = randomNum(0, size -1);
        if (maze[x][y] != 1 && maze[x][y] != 3) {
            maze[x][y] = 4;
            i++;
        }
    }
}
