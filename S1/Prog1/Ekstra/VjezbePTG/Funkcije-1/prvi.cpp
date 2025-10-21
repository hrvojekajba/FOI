#include<iostream>

struct{
    int prvi;
    int drugi;
    int treci;
}var;

void potprogram(){
    std::cout << "Unesite prvu vrijednost: ";
    std::cin >> var.prvi;
    std::cout << "Unesite drugu vrijednost: ";
    std::cin >> var.drugi;
    std::cout << "Unesite trecu vrijednost: ";
    std::cin >> var.treci;

    std::cout << "Zbroj = " << var.prvi+var.drugi+var.treci << "\n";
    std::cout << "Umnozak = " << var.prvi*var.drugi*var.treci << "\n";
}

int main(){
    potprogram();
    potprogram();
    return 0;
}