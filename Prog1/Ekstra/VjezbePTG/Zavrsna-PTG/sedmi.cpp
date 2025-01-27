#include<iostream>

int main(){
    char polje[101] = {0};

    std::cout << "Unesite recenicu (moze imati najvise 100 znakova): ";
    std::cin.getline(polje, 100);

    for (int i = 65; i < 91; i++){
        int broj_slova = 0;
        for (int j = 0; j < 101; j++){
            if (polje[j] == char(i) || polje[j] == char(i+32)) broj_slova++;
        }
        if (broj_slova == 0){
            continue;
        }else{
            std::cout << char(i) << " = " << broj_slova << " ";
        }
    }

    std::cout << "\n";

    return 0;
}