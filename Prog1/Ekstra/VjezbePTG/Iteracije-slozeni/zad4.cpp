#include <iostream>

int main(){
    int maxUnos = 0;

    while (true){
        int unos;
        std::cout << "Unesite cijeli pozitivni broj: ";
        std::cin >> unos;

        if (unos > maxUnos){
            maxUnos = unos;
        }
        if (unos <= 0){
            break;
        }
    }

    std::cout << "Najveći uneseni broj: " << maxUnos << "\n";

    return 0;
}