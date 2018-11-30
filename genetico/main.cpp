#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <random>
#include <fstream>
#include <string>
#include <unistd.h>

int population, generations = 0;
void printInfos();

int main() {
    printInfos();
    cout << "entre com a populacao: ";
    cin >> population;
    cout << "entre com o numero de geracoes: ";
    cin >> generations;
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
