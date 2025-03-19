#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<iomanip>
#include "biblioteka_vrijeme.cc"
using namespace std;

void prvi(){
    cout << "\n---PRVI---\n";
    string *polje = new string [3] {"ventilator", "radni stol", "olovka"};
    for (int i = 0; i < 3; i++){
        cout << "polje[" << i << "]: " << polje[i] << "\n";
    }
    cout << "----------\n\n";
}

float povrsina_pravokutnog(int a, int b){
    return float(a*b)/2;
}

void drugi(){
    cout << "\n---DRUGI---\n";
    int a,b;
    do{
        cout << "Unesite stranicu A: "; cin >> a;
        cout << "Unesite stranicu B: "; cin >> b;
    }while(a <= 0 || b <= 0);
    cout << "Povrsina trokuta je: " << povrsina_pravokutnog(a, b) << "\n";
    cout << "-----------\n\n";
}

void treci(){
    cout <<"\n---TRECI---\n";

    struct struktura{
        int maticni;
        char prezime[30];
        char ime[15];
        int godina;
    };

    struktura *pocetni_var = new struktura;
    struktura *copy_var = new struktura;

    cout << "Unesite maticni broj studenta: "; cin >> pocetni_var->maticni;
    cout << "Unesite prezime studenta: "; cin >> pocetni_var->prezime;
    cout << "Unesite ime studenta: "; cin >> pocetni_var->ime;
    cout << "Unesite godinu upisa studenta: "; cin >> pocetni_var->godina;

    memcpy(copy_var, pocetni_var, sizeof(struktura));
    cout << "\nPrekopirani podatci:" << "\n 1. Maticni broj: " << copy_var->maticni <<"\n 2. Prezime: " << copy_var->prezime <<
    "\n 3. Ime: " << copy_var->ime << "\n 4. Godina upisa: " << copy_var->godina << "\n";
    delete pocetni_var;
    delete copy_var;
    cout << "-----------\n\n";
}

void cetvrti(){
    cout << "\n---CETVRTI---\n";
    int a,b,c;
    do{
        vrijeme_pocetak;
        cout << "Unesite A: "; cin >> a;
        cout << "Unesite B: "; cin >> b;
        cout << "Unesite C: "; cin >> c;
        vrijeme_kraj;
    }while((a <= 0) || (b <= 0) || (c <= 0) || (a > b+c) || (b > a+c) || (c > a+b));
    cout << "Vrijeme unosa stranica trokuta je: " << vrijeme_proteklo << "\n";

    float s = float(a+b+c)/2;
    float p = sqrt(s*(s-a)*(s-b)*(s-c));

    cout << "Povrsina trokuta je: " << fixed << setprecision(2) << p << "\n";

    cout << "-------------\n\n";
}

int main(){
    int izbor = 0;
    do{
        cout << "Izbornik:\n" << "  1. Polje\n" << "  2. Funkcija\n" << "  3. Struktura\n" << "  4. Mjerenje vremena\n" 
        << "  9. Izlazak iz programa\n" << "Izbor: "; cin >> izbor;

        switch (izbor){
            case 1: prvi(); break;
            case 2: drugi(); break;
            case 3: treci(); break;
            case 4: cetvrti(); break;
            case 9: break;
            default: cout << "Krivi unos!\n";
        }
    }while(izbor != 9);

    return 0;
}