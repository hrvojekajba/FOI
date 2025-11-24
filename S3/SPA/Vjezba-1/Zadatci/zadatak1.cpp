#include <iostream>
#include "Headers/lista.h"

int main() {
    list<int> lista; int n;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        lista.Insert(lista.End(), rand() % 21);
    }

    for (list<int>::element i = lista.First(); i != lista.End(); i = lista.Next(i)) {
        std::cout << lista.Retrieve(i) << " ";
    }
    std::cout << "\n";

    for (list<int>::element i = lista.First(); i != lista.End(); i = lista.Next(i)) {
        for (list<int>::element j = lista.Next(i); j != lista.End();) {
            if (lista.Retrieve(i) == lista.Retrieve(j))
                lista.Delete(j);
            else
                j = lista.Next(j);
        }
    }

    for (list<int>::element i = lista.First(); i != lista.End(); i = lista.Next(i)) {
        std::cout << lista.Retrieve(i) << " ";
    }
    std::cout << "\n\n";

    return 0;
}
