#include<iostream>

int potprogram(int prvi, int drugi){
    int randBroj;
    if (prvi > drugi){
        randBroj = drugi + rand() % (prvi-drugi);
    }else{
        randBroj = prvi + rand() % (drugi-prvi);
    }
    return randBroj;
}

int main(){
    int prvi;
    std::cout << "Unesite prvi broj: ";
    std::cin >> prvi;

    int drugi;
    std::cout << "Unesite drugi broj: ";
    std::cin >> drugi;

    std::cout << "Povratna vrijednost potprograma: " << potprogram(prvi, drugi) << "\n";

    return 0;
}