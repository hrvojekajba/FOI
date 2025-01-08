//DRUGI

#include<iostream>

void potprogram(char arg = 'Z'){
    for(char i = arg; i >= 'A'; i--){
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main(){
    char unos;
    std::cout << "Unesite veliko slovo engleske abecede: ";
    std::cin >> unos;

    potprogram(unos);
    potprogram();

    return 0;
}