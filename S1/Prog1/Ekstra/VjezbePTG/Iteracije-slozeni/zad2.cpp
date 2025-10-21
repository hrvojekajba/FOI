#include <iostream>

int main(){
    char slovo;
    std::cout << "Unesite veliko slovo: ";
    std::cin >> slovo;

    char A = 65;

    while(A <= slovo){
        std::cout << A << "\n";
        A++;
    }

    return 0;
}