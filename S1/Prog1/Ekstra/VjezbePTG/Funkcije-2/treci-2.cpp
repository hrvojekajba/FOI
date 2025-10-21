//TRECI-2

#include<iostream>

int potprogram(int* prvi, int* drugi){
    int pomocna;
    pomocna = *prvi;
    *prvi = *drugi;
    *drugi = pomocna;

    return 0;
}

int main(){
    int a,b;
    std::cout << "Unesite a: ";
    std::cin >> a;
    std::cout << "Unesite b: ";
    std::cin >> b;

    potprogram(&a, &b);

    std::cout << "a: " << a << "\nb: " << b << "\n";
    return 0;
}