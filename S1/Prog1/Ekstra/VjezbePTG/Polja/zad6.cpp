#include <iostream>
#include <cstdlib>

int main(){
    char rand_polje[20]{};
    int samoglasnici = 0, suglasnici = 0;

    for (int i = 0; i < 20; i++){
        rand_polje[i] = ('a' +rand() % 26);
    }
    for (int i = 0; i < 20; i++){
        std::cout << rand_polje[i] << " ";
        switch (rand_polje[i]){
            case 'a': samoglasnici++;break;
            case 'e': samoglasnici++;break;
            case 'i': samoglasnici++;break;
            case 'o': samoglasnici++;break;
            case 'u': samoglasnici++;break;
            default: suglasnici ++;
        }
    }
    std::cout << "\n";
    std::cout << "SAMOGLASNICI: " << samoglasnici << "\n";
    std::cout << "SUGLASINICI: " << suglasnici << "\n";
    return 0;
}