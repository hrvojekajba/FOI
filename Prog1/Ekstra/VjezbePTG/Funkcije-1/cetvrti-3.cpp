#include<iostream>

int potprogram(int var){
    static int minimum = 1000000;
    if (var < minimum){
        minimum = var;
    }
    return minimum;
}

int main(){
    int input;
    int N;
    std::cout << "Koliko brojeva zelite unijeti? ";
    std::cin >> N;
    
    for (int i = 0; i < N; i++){
        std::cout << "Unesite broj " << i+1 <<": ";
        std::cin >> input;
        std::cout << "Najmanji uneseni broj: " << potprogram(input) << "\n";
    }

    return 0;
}