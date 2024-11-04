#include <iostream>

int main(){
    float polje[5]{};
    float max = 0, min = 1000.0;

    for (int i = 0; i <= 4; i++){
        float unos;
        std::cout << "Unesite broj: ";
        std::cin >> unos;

        polje[i] = unos; 
    }
    for (int i = 4; i >= 0; i--){
        std::cout << polje[i] << "\n";
        if (polje[i] < min){
            min = polje[i];
        }
        if (polje[i] > max){
            max = polje[i];
        }
    }

    std::cout << "Max: " << max << "\n" << "Min: " << min << std::endl;
    std::cout << "Max/Min: " << max/min << "\n";

    return 0;
}   