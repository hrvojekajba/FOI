//PRVI

#include<iostream>

struct pravokutnik{
    int a;
    int b;
}var;

void potprogram(pravokutnik var){
    std::cout << "Opseg: " << (2*var.a) + (2*var.b) << "\n";
    std::cout << "Povrsina: " << var.a*var.b << "\n";
}

int main(){
    std::cout << "Unesite stranicu a: ";
    std::cin >> var.a;

    std::cout << "Unesite stranicu b: ";
    std::cin >> var.b;

    potprogram(var);

    return 0;
}