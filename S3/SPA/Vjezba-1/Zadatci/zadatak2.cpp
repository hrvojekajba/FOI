#include <iostream>
#include "Headers/listapp.h"

int main() {
    list<int> lista;
    int n, x;

    std::cout << "\nUnesite stupanj n: ";
    std::cin >> n;

    std::cout << "Unesite koeficijente: ";
    for (int i = 0; i < n+1; i++) {
        int koeficijent;
        std::cin >> koeficijent;
        lista.Insert(lista.End(), koeficijent);
    }

    std::cout << "Unesite x: ";
    std::cin >> x;

    int rezultat = lista.Retrieve(lista.First()); int mnozenja = 0;
    for (list<int>::element i = lista.Next(lista.First()); i != lista.End(); i = lista.Next(i)) {
        rezultat = rezultat * x + lista.Retrieve(i);
        mnozenja++;
    }

    std::cout << "\n\nRezultat: " << rezultat << "\n";
    std::cout << "Broj mnozenja: " << mnozenja << "\n";

    return 0;
}
