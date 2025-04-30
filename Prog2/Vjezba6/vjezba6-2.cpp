#include<iostream>
#include<fstream>
using namespace std;

struct telement{
    int redni_broj;
    int sifra;
    char ime[50];
};

struct tindeks{
    int sifra;
    int adresa;
};

void kreiraj(char maticna[], char indeksna[]){
    fstream dat(maticna, ios::out);
    dat.close(); dat.clear();
    fstream ind(indeksna, ios::out);
    ind.close(); ind.clear();
}

void rucni_upis(char maticna[], char indeksna[]){
    telement element;
    tindeks indeks;
    int redni_broj;

    fstream dat(maticna, ios::out | ios::in | ios::ate | ios::binary);
    fstream ind(indeksna, ios::out | ios::in | ios::ate | ios::binary);
    dat.seekg(0, ios::end);
    redni_broj = dat.tellg() / sizeof(telement);
    redni_broj++;



    cout << "\nRedni broj zapisa: " << redni_broj << endl;
    element.redni_broj = redni_broj;
    cout << "Unesite sifru: "; cin >> element.sifra; cin.ignore();
    cout << "Unesite ime osobe: "; cin.getline(element.ime, 50);
    cout << "\n";

    indeks.sifra = element.sifra;
    indeks.adresa = (int)dat.tellp();
    dat.write((char*)&element, sizeof(telement));
    ind.write((char*)&indeks, sizeof(tindeks));
    dat.close(); dat.clear();
    ind.close(); ind.clear();
}

void ispis(char maticni[], char indeksni[]){
    int broj_zapisa = 0;
    telement element;
    tindeks indeks;
    fstream dat(maticni, ios::in | ios::binary);
    fstream ind(indeksni, ios::in | ios::binary);

    while(true){
        ind.read((char*)&indeks, sizeof(tindeks));
        if(ind.eof()) break;
        cout << "\n---ELEMENT---\n";
        cout << "Sifra: " << indeks.sifra << endl;
        cout << "Adresa: " << indeks.adresa << endl;
        dat.seekg(indeks.adresa);
        dat.read((char*)&element, sizeof(telement));
        cout << "Redni broj zapisa: " << element.redni_broj << endl;
        cout << "Ime osobe: " << element.ime << endl;
        cout << "-------------\n\n";
        broj_zapisa++;
    }
    cout << "Broj zapisa u datoteci: " << broj_zapisa << "\n\n";

    dat.close(); dat.clear();
    ind.close(); ind.clear();
}

int main(){
    int izbor = 0;
    char maticni[50] = "podatci.dat";
    char indeksni[50] = "indeks.dat";

    do{
        cout << "Izbornik:\n";
        cout << "   1. Kreiranje datoteke\n";
        cout << "   2. Rucni upis\n";
        cout << "   3. Pretrazivanje\n";
        cout << "   4. Ispis\n";
        cout << "   9. Izlaz iz programa\n";
        cout << "Izbor: "; cin >> izbor;

        switch(izbor){
            case 1:
                char mjenjanje;
                cout << "\nZelite li promjeniti nazive datoteka(Y/N): "; cin >> mjenjanje;
                if(mjenjanje == 'Y'){
                    cin.ignore();
                    cout << "\nUnesite novi naziv za maticnu datoteku: "; cin.getline(maticni, 50);
                    cout << "Unesite novi naziv za indeksnu datoteku: "; cin.getline(indeksni, 50);
                    kreiraj(maticni, indeksni);
                }else{
                    kreiraj(maticni, indeksni); 
                }
                cout << "\nDatoteka kreirana\n\n"; break;
            case 2:
                rucni_upis(maticni, indeksni);
                break;
            case 3:
                break;
            case 4:
                ispis(maticni, indeksni);
                break;
            case 9:
                break;
            default:
                cout << "\nPogresan unos...\n\n";
        }
    }while(izbor != 9);
}