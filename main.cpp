#include <iostream>
using namespace std;


int ask(char const[]);
void printAnimalList();
void printFruitsList();
void brain();


int main() {
    cout << "Escolha um item das duas listas abaixo, tentaremos advinhar qual foi:\n\n";
    printAnimalList();
    printFruitsList();
    // char const *pointer_to_nonconst = "string literal";
    // ask(pointer_to_nonconst);
    return 0;
}

int ask(char const question[]) {
    int response = 0;
    cout << question;
    cin >> response;
    cout << response;
    return response;
}

void printAnimalList() {
    cout << "lista de animais\n";
    char list[] = "1.abelha\n2.barata\n3.camelo\n4.baleia\n5.boi\n6.burro\n7.cao\n8.avestruz\n9.canguru\n10.cascavel\n11.chipanze\n12.crocodilo\n13.elefante\n14.galinha\n15.gato\n16.girafa\n17.jacare\n18.leao\n19.leopardo\n20.lobo\n21.lontra\n22.mosca\n23.onca\n24.orca\n25.porco\n26.pulga\n27.tubarao\n28.urubu\n29.urso\n30.panda\n";
    cout << list;
}

void printFruitsList() {
    cout << "\nlista de frutos\n";
    char list[] = "1.abacate\n2.abacaxi\n3.acerola\n4.amora\n5.araticum\n6.bacaba\n7.banana\n8.biriba\n9.cacau\n10.caja\n11.caqui\n12.carambola\n13.cereja\n14.cidra\n15.coco\n16.cupuacu\n17.figo\n18.framboesa\n19.goiaba\n20.groselha\n21.inga\n22.jabuticaba\n23.jaca\n24.jambo\n25.jenipapo\n26.kiwi\n27.laranja\n28.limao\n29.maca\n30.acai\n";
    cout << list;
}

void brain(){
    
    
    return;
}