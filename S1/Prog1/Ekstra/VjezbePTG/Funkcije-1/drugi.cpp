#include<iostream>

char globalVar = 'a';

void potprogram(){
    int unos;
    std::cout << "Unesite brojevnu vrijednost od 1-25: ";
    std::cin >> unos;

    globalVar += unos;

    std::cout << "Brojna vrijednost: " << int(globalVar) << "\nZnakovna vrijednost: " << globalVar << "\n";
}

int main(){
    std::cout << "Vrijednost od globalVar: " << globalVar << "\n";
    potprogram();

    globalVar = 'A';
    std::cout << "Vrijednost od globalVar: " << globalVar << "\n";
    potprogram();

    return 0;
}