#include<iostream>
#include<cstring>

int main(){
    struct slog{
        char ime[30];
        char prezime[30];
    };

    slog *pok = new slog;
    slog var;

    std::cout << "Unesite ime 1: ";
    std::cin.getline((*pok).ime, 30);
    std::cout << "Unesite prezime 1: ";
    std::cin.getline((*pok).prezime, 30);

    std::cout << "Unesite ime 2: ";
    std::cin.getline(var.ime, 30);
    std::cout << "Unesite prezime 2: ";
    std::cin.getline(var.prezime, 30);

    int pokLen = strlen((*pok).ime) + strlen((*pok).prezime);
    int varLen = strlen(var.ime) + strlen(var.prezime);

    if (pokLen > varLen){
        std::cout << (*pok).ime << " " << (*pok).prezime << "\n";
    }
    else if (varLen > pokLen){
        std::cout << var.ime << " " << var.prezime << "\n";
    }
    else{
        std::cout << "Jednako dugi.\n";
        std::cout << (*pok).ime << " " << (*pok).prezime << "\n";
        std::cout << var.ime << " " << var.prezime << "\n";
    }

    return 0;
}