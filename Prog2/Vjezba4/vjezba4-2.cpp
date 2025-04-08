#include<iostream>
#include<fstream>
#include "../biblioteka_vrijeme_linux.cc"
using namespace std;

struct element{
    int maticni;
    char prez_ime[50];
    int godina;
    int broj_polozenih;
    double vrijeme_unosa;
};

void unos(){
    fstream datoteka("podatci.dat", ios::app | ios::binary);
    element stavka;
    //koristi static -- zapamti se vrijednost cak i kad se izade iz funkcije
    static double aritmeticka = 0; 
    static int n = 0;

    cout << "\n---UNOS---\n";
    vrijeme_pocetak();
    cout << "Unesite maticni broj studenta: "; cin >> stavka.maticni; cin.ignore();
    cout << "Unesite ime i prezime studenta: "; cin.getline(stavka.prez_ime, 50);
    cout << "Unesite godinu upisa: "; cin >> stavka.godina; aritmeticka += stavka.godina;
    cout << "Unesite broj polozenih ispita: "; cin >> stavka.broj_polozenih;
    cout << "----------\n";
    vrijeme_kraj();
    stavka.vrijeme_unosa = vrijeme_proteklo();
    datoteka.write((char*)&stavka, sizeof(stavka));
    n++;
    
    cout << "Aritmeticka sredina godina upisa: " << aritmeticka/n << "\n\n";
    
    datoteka.close();
    datoteka.clear();
}

bool provjera(int sifra){
    fstream datoteka("podatci.dat", ios::in | ios::binary);
    element stavka;

    while(true){ //iterira kroz datoteku sve dok ne nade trazeni element, ili dode do kraja
        datoteka.read((char*)&stavka, sizeof(stavka));
        if(datoteka.eof()) break;
        if(stavka.maticni == sifra){
            datoteka.close();
            datoteka.clear();
            return false;
        }
    }
    datoteka.close();
    datoteka.clear();
    return true;
}

void provjera_unos(){
    fstream datoteka("podatci.dat", ios::app | ios::binary);
    element stavka;

    cout << "\n---UNOS SIFRE---\n";
    vrijeme_pocetak();
    cout << "Unesite sifru studenta: "; cin >> stavka.maticni; cin.ignore();
    cout << "----------------\n";
    if(provjera(stavka.maticni)){
        cout << "Unesite ime i prezime studenta: "; cin.getline(stavka.prez_ime, 50);
        cout << "Unesite godinu upisa: "; cin >> stavka.godina;
        cout << "Unesite broj polozenih ispita: "; cin >> stavka.broj_polozenih;
        vrijeme_kraj();
        stavka.vrijeme_unosa = vrijeme_proteklo();
        cout << "----------------\n\n";
        datoteka.write((char*)&stavka, sizeof(stavka));
    }else{
        vrijeme_kraj();
        cout << "Vec postoji element s tom sifrom, izlazim iz unosa...\n";
        cout << "----------------\n\n";
        datoteka.close();
        datoteka.clear();   
        return;
    }
    
    datoteka.close();
    datoteka.clear();
}

void ispis(){
    fstream datoteka("podatci.dat", ios::in | ios::binary);
    element stavka;
    double aritmeticka_vrijeme = 0;
    int n = 0;

    cout << endl;
    while(true){
        datoteka.read((char*)&stavka, sizeof(stavka));
        if(datoteka.eof()) break;
        cout << "---ELEMENT---\n";
        cout << "Maticni broj studenta: " << stavka.maticni << endl;
        cout << "Ime i prezime studenta: " << stavka.prez_ime << endl;
        cout << "Godina upisa: " << stavka.godina << endl;
        cout << "Broj polozenih ispita: " << stavka.broj_polozenih << endl;
        cout << "Vrijeme unosa stavke: " << stavka.vrijeme_unosa/1000 << "s" << endl;
        aritmeticka_vrijeme += stavka.vrijeme_unosa;
        n++;
        cout << "-------------\n";
    }
    cout << "Aritmeticka sredina vremena unosa: " << (aritmeticka_vrijeme/n)/1000 << "s" << endl;
    cout << endl;
    datoteka.close();
    datoteka.clear();
}

void pretrazivanje(){
    fstream datoteka("podatci.dat", ios::in | ios::binary);
    element stavka;
    int redni = 0;
    bool pronaden = false;

    int sifra;
    cout << "\nUnesite maticni broj studenta kojeg trazite: "; cin >> sifra;

    while(true){
        datoteka.read((char*)&stavka, sizeof(stavka));
        if(datoteka.eof()) break;
        if(stavka.maticni == sifra){
            cout << "---ELEMENT---\n";
            cout << "Maticni broj studenta: " << stavka.maticni << endl;
            cout << "Ime i prezime studenta: " << stavka.prez_ime << endl;
            cout << "Godina upisa: " << stavka.godina << endl;
            cout << "Broj polozenih ispita: " << stavka.broj_polozenih << endl;
            cout << "Vrijeme unosa stavke: " << stavka.vrijeme_unosa/1000 << "s" << endl;
            cout << "Redni broj stavke: " << redni << endl;
            cout << "-------------\n\n";
            pronaden = true; //ako ga je pronaslo, postavi pronaden ko true
        }
        redni++; //prati na kojoj si stavci
    }
    if(pronaden){
        datoteka.close();
        datoteka.clear();
    }else{
        cout << "Element nije pronaden\nBroj elemenata u listi: " << redni << endl; //ako nije pronaden ispise ukupan broj stavaka
        datoteka.close();
        datoteka.clear();
    }
}

int main(){
    int izbor = 0;
    do{
        cout << "\nIzbornik:\n"; 
        cout << "   1. Unos podataka u datoteku\n";
        cout << "   2. Unos uz provjeru jedinstvenosti primarnog kljuca\n";
        cout << "   3. Ispis sadrzaja cijele datoteke\n";
        cout << "   4. Pretrazivanje\n";
        cout << "   9. Izlaz iz programa\n";
        cout << "Unos: "; cin >> izbor;

        switch(izbor){
            case 1: unos(); break;
            case 2: provjera_unos(); break;
            case 3: ispis(); break;
            case 4: pretrazivanje(); break;
            case 9: break;
            default: cout << "\nPogresan unos\n";
        }
    }while(izbor != 9);
}