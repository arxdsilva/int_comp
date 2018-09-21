#include <iostream>
using namespace std;


int ask(char const[]);
void printAnimalList();
void printFruitsList();
void brain();
char const* animalTree();
char const* fruitsTree();


int main() {
    cout << "Escolha um item das duas listas abaixo, tentaremos advinhar qual foi:\n\n";
    printAnimalList();
    printFruitsList();
    brain();
    return 0;
}

int ask(char const question[]) {
    int response = 0;
    cout << question;
    cin >> response;
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
    char const *animalOrFruitQuestion = "se movimenta ativamente durante sua vida?? [0,1] | onde 0 = falso e 1 = verdadeiro";
    char const *finalResp = "";
    int resp = ask(animalOrFruitQuestion);
    if (resp == 1) {
        finalResp = animalTree();
    } else {
        finalResp = fruitsTree();
    }
    cout << "O animal/fruto escolhido eh:\n";
    cout << finalResp;
    return;
}

char const* animalTree() {
    char const *resp = "";
    int consoleResp = 0;
    if (ask("nada durante toda sua vida? [0,1] \n") == 1) {
        if (ask("possui guelras? [0,1] \n") == 1) {
            resp = "tubarao\n";
            return resp;
        }
        if (ask("caca em grupo? [0,1] \n") == 1) {
            resp = "orca\n";
            return resp;
        }
        if (ask("Pode ser encontrado em rios? [0,1] \n") == 1) {
            resp = "lontra\n";
            return resp;
        }
        resp = "baleia\n";
        return resp;
    }
    if (ask("possui asas? [0,1] \n") == 1) {
        if (ask("voa? [0,1] \n") == 1) {
            resp = "urubu\n";
            return resp;
        }
        if (ask("pode ser considerado animal domestico? [0,1] \n") == 1) {
            resp = "galinha\n";
            return resp;
        }
        resp = "avestruz\n";
        return resp;
    }
    if (ask("possui escamas? [0,1] \n") == 1) {
        if (ask("vive na floresta? [0,1] \n") == 1) {
            resp = "cascavel\n";
            return resp;
        }
        if (ask("Possui dentes superiores e inferiores alinhados?? [0,1] \n") == 1) {
            resp = "crocodilo\n";
            return resp;
        }
        resp = "jacare\n";
        return resp;
    }
    if (ask("possui esqueleto? [0,1] \n") == 1) {
        if (ask("possui polegar opositor? [0,1] \n") == 1) {
            resp = "chipanze\n";
            return resp;
        }
        if (ask("herbivoro? [0,1] \n") == 1) {
            if (ask("Encontrado na oceania? [0,1] \n") == 1) {
                if (ask("quadrupede? [0,1] \n") == 1) {
                    resp = "panda\n";
                    return resp;
                }
                resp = "canguru\n";
                return resp;
            }
            if (ask("se alimenta de folhas das partes altas das arvores? [0,1] \n") == 1) {
                if (ask("Possui presas proeminentes? [0,1] \n") == 1) {
                    resp = "elefante\n";
                    return resp;
                }
                resp = "girafa\n";
                return resp;
            }
            if (ask("possui corcova? [0,1] \n") == 1) {
                resp = "camelo\n";
                return resp;
            }
            if (ask("tem chifre? [0,1] \n") == 1) {
                resp = "boi\n";
                return resp;
            }
            resp = "porco\n";
            return resp;
        }
        if (ask("animal domestico? [0,1] \n") == 1) {
            if (ask("tem focinho alongado? [0,1] \n") == 1) {
                resp = "cao\n";
                return resp;
            }
            resp = "gato\n";
            return resp;
        }
        if (ask("convive em bando? [0,1] \n") == 1) {
            if (ask("tem juba? [0,1] \n") == 1) {
                resp = "leao\n";
                return resp;
            }
            resp = "lobo\n";
            return resp;
        }
        if (ask("hiberna? [0,1] \n") == 1) {
            resp = "urso\n";
            return resp;
        }
        if (ask("habita as americas? [0,1] \n") == 1) {
            resp = "onca\n";
            return resp;
        }
        resp = "leopardo\n";
        return resp;
    }
    if (ask("tem asas? [0,1] \n") == 1) {
        if (ask("convive em uma sociedade organizada? [0,1] \n") == 1) {
            resp = "abelha\n";
            return resp;
        }
        if (ask("costuma se alimentar de sangue humano? [0,1] \n") == 1) {
            resp = "mosca\n";
            return resp;
        }
        resp = "barata\n";
        return resp;
    }
    resp = "pulga\n";
    return resp;
}

char const* fruitsTree() {
    char const *resp = "";
    if (ask("casca e comestivel? [0,1] \n") == 1) {
        if (ask("e considerada uma fruta vermelha? [0,1] \n") == 1) {
            // lala
        }
        if (ask("possui somente 1 semente? [0,1] \n") == 1) {
            if (ask("sua casca e verde? [0,1] \n") == 1) {
                resp = "abacate\n";
                return resp;
            }
            resp = "araticum\n";
            return resp;
        }
    }
    if (ask("possui liquido livre dentro? [0,1] \n") == 1) {
        resp = "coco\n";
        return resp;
    }
    if (ask("casca possui coloracao vermelha? [0,1] \n") == 1) {
        resp = "cacau\n";
        return resp;
    }
    if (ask("De suas sementes é possível a fabricação de chocolate e doces? [0,1] \n") == 1) {
        resp = "cupuacu\n";
        return resp;
    }
    resp = "inga\n";
    return resp;
}