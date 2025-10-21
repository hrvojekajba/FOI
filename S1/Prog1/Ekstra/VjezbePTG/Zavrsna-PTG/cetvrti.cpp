#include<iostream>

const float pi = 3.14;

int Izracun(int a){
    return a*a*a;
}

float Izracun(float r){
    return (4/3)*pi*r*r*r;
}

int main(){
    int a;
    float r;

    std::cout << "Unesite duzinu stranice kocke (a): ";
    std::cin >> a;

    std::cout << "Unesite duzinu radijusa kugle (r): ";
    std::cin >> r;

    std::cout << "Volumen kocke: " << Izracun(a) << "\n";
    std::cout << "Volumen kugle: " << Izracun(r) << "\n";

    return 0;
}