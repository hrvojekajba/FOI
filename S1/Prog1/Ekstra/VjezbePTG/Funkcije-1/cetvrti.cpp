#include<iostream>

void potprogram(){
    static int i = 0;
    i -= 3;
    std::cout << "Vrijednost varijable: " << i << "\n";
}

int main(){
    int N;
    std::cout << "Koliko puta zelite pozvati funkciju? ";
    std::cin >> N;

    for (int i = 0; i < N; i++){
        potprogram();
    }

    return 0;
}