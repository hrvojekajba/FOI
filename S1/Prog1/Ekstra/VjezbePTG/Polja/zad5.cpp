#include <iostream>
#include <cstdlib>

int main(){
    int rand_polje[10] {};

    for (int i = 0; i < 10; i++){
        rand_polje[i] = ((-10) + rand() % 20);
    }
    for (int i = 0; i < 10; i++){
        std::cout << rand_polje[i] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < 10; i++){
        if (rand_polje[i] % 2 == 1 || rand_polje[i] % 2 == (-1)){
            std::cout << rand_polje[i] << " ";
        }
    }
    std::cout << "\n";
    return 0;
}