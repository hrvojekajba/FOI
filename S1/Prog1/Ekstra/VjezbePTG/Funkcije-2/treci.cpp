//TRECI

#include<iostream>

int potprogram(char* znak, bool logicka){
    if (logicka == true){
        if (*znak < 97){
            std::cout << "Slovo je vec veliko.";
            return 0;
        }else{
            return *znak - 32;
        }
    }else{
        if (*znak >= 97){
            std::cout << "Slovo je vec malo.";
            return 0;
        }else{
            return *znak + 32;
        }
    }
}

int main(){
    char unos_slovo;
    std::cin >> unos_slovo;

    bool unos_logika;
    std::cin >> unos_logika;

    std::cout << char(potprogram(&unos_slovo, unos_logika)) << "\n";

    return 0;
}