#include <iostream>

int main(){
    int izbor;

    while (true){
        std::cout << "ODABIR:\n 1. Zbrajane\n 2. Oduzimanje\n 3. Izlaz iz programa\n";
        std::cin >> izbor;

        if (izbor == 1 || izbor == 2){
            int a;
            std::cout << "Unesite prvi broj: ";
            std::cin >> a;

            int b;
            std::cout << "Unesite drugi broj: ";
            std::cin >> b;

            if (izbor == 1){
                std::cout << "Rezultat: " << a + b << "\n";
            }
            else{
                std::cout << "Rezultat: " << a - b << "\n";
            }
        }
        else{
            break;
        }
    }
    return 0;
}