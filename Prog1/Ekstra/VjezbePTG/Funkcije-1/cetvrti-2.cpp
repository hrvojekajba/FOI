#include<iostream>

char znak(int var){
    return char(var);
}

int znak(char var){
    return var;
}

int main(){
    char znak_unos;
    int broj_unos;

    std::cout << "Unesite cijelobrojnu vrijednost: ";
    std::cin >> broj_unos;

    std::cout << "Unesite znakovnu vrijednost: ";
    std::cin >> znak_unos;

    std::cout << "Znakovna vrijednost broja: " << znak(broj_unos) << "\n";
    std::cout << "Brojevna vrijednost znaka: " << znak(znak_unos) << "\n";

    return 0;
}