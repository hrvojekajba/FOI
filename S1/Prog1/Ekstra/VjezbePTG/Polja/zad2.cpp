#include <iostream>

int main(){
    char polje[4] {'a', 'b', 'c', 'd'};

    for (int i = 0; i < 4; i++){
        std::cout << polje[i];
    }
    std::cout << "\n";
    return 0;
}