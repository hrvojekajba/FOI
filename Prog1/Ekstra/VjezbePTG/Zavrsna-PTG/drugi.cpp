#include <iostream>

struct slog{
    int polje[7];
    int X;
}var;

int main(){

    for (int i = 0; i < 7; i++){
        var.polje[i] = rand() % 11;
    }

    std::cout << "Unesite cijelobrojnu vrijednost X: ";
    std::cin >> var.X;

    std::cout << "Elementi polja manji od X: ";
    for (int i = 0; i < 7; i++){
        if(var.polje[i] < var.X){
            std::cout << var.polje[i] << " ";
        }
    }
    std::cout << "\n";

    std::cout << "Elementi polja veci ili jednaki vrijednosti X: ";
    for (int i = 0; i < 7; i++){
        if(var.polje[i] >= var.X){
            std::cout << var.polje[i] << " ";
        }
    }
    std::cout << "\n";

    return 0;
}