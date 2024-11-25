#include<iostream>

int main(){
    struct slog{
        char niz[10];
        int samoglasnik = 0;
    }var[10];

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            var[i].niz[j] = char(97 + rand() % 25);
            switch(var[i].niz[j]){
                case 'a': var[i].samoglasnik++; break;
                case 'e': var[i].samoglasnik++; break;
                case 'i': var[i].samoglasnik++; break;
                case 'o': var[i].samoglasnik++; break;
                case 'u': var[i].samoglasnik++; break;
            }
        }
    }
    std::cout << "\n";

    int max_indeks;
    int max_samoglasnik = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            std::cout << var[i].niz[j] << " ";
        }
        std::cout << "Broj samoglasnika: " << var[i].samoglasnik << "\n";
        if (var[i].samoglasnik > max_samoglasnik){
            max_samoglasnik = var[i].samoglasnik;
            max_indeks = i;
        }
    }
    std::cout << "Element s najvecim brojem samoglasnika ima indeks: " << max_indeks << "\n";
    return 0;
}