#include<iostream>
#include<cstdlib>

int main(){
    char polje[10]{};

    for (int i = 0; i < 10; i++){
        polje[i] = 'A' + rand() % 26;
        std::cout << polje[i];
    }
    std::cout << "\n";
    for (int i = 0; i < 10; i++){
        polje[i] += 32;
        std::cout << polje[i];    
    }
    std::cout << "\n";
    for (int i = 0; i < 10; i++){
        std::cout << int(polje[i]) << " ";
    }
    std::cout << "\n";
    return 0;
}