#include <cstring>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "biblioteka_vrijeme.cc"

void prvi(){
    double suma = 0;
    double *polje = new double [4] {3.56, 7.17, 5.12, 4.21};
    for (int i = 0; i < 4; i++){
        std::cout << "  polje[" << i << "]: " << polje[i] << "\n";
        suma += polje[i];
    }
    std::cout << "Suma: " << suma << "\n";
}

double drugi (int a, int b){
    a = abs(a);
    b = abs(b);
    return (double(a)*double(b))/2;
}

void treci(){
    struct struktura {
        int god;
        char ime[50];
    };

    struktura var = {20, "Hrvoje"};
    struktura copyvar;
    memcpy(&copyvar, &var, sizeof(var));

    std::cout << copyvar.god << " " << copyvar.ime << "\n";
}

void cetvrti(){
    int a,b,c;
    do{
        vrijeme_pocetak();
        std::cout << "A: "; std::cin >> a;
        std::cout << "B: "; std::cin >> b;
        std::cout << "C: "; std::cin >> c;
        vrijeme_kraj();
        std::cout << "Vrijeme unosa stranica: " << vrijeme_proteklo() / 100 << "\n";
    }while(a <= 0 || b <= 0 || c <= 0 || (a + b) <= c || (b + c) <= a || (c + a) <= b);
    float s = (a + b + c) / 2.0;
    std::cout << "S: " << s << "\n";
    float povrsina = sqrt(s*(s-a)*(s-b)*(s-c));
    std::cout << fixed << std::setprecision(2) << "Povrsina: " << povrsina << "\n";
}

int main(){
    int izbor = 0;
    do{
        std::cout << "Izbornik:\n";
        std::cout << "  1. Polje\n  2. Funkcija\n  3. Struktura\n  4. Mjerenje vremena\n  9. Izlaz iz programa\n";
        std::cout << "Unesite izbor: ";
        std::cin >> izbor;
        switch (izbor){
            case 1: prvi(); break;
            case 2:
                int a;
                std::cout << "A: "; std::cin >> a;
                int b;
                std::cout << "B: "; std::cin >> b;
                std::cout << "Povrsina trokuta: " << drugi(a,b) << "\n";
                break;
            case 3: treci(); break;
            case 4: cetvrti(); break;
        }
    }while (izbor != 9);
    return 0;
}
