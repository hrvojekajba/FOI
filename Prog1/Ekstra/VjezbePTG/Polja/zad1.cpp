#include <iostream>

int main(){
    float polje[5]{};

    for (int i = 0; i <= 4; i++){
        float unos;
        std::cout << "Unesite broj: ";
        std::cin >> unos;

        polje[i] = unos; 
    }
    for (int i = 4; i >= 0; i--){
        std::cout << polje[i] << "\n";
    }

    return 0;
}