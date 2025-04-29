#include<iostream>
#include<fstream>
using namespace std;

struct tpredmet{
    int rb_zapisa;
    int sifra;
    char naziv[50];
    char smjer[50];
    int broj_prijava;
};

struct tindeks{
    int sifra;
    int adresa;
};

fstream dat, ind;

void kreiranje(char maticna[], char indeksna[]){
    dat.open(maticna, ios::out);
    dat.close(); dat.clear();
    ind.open(indeksna, ios::out);
    ind.close(); ind.clear();
}

void rucni_unos(char maticna[], char indeksna[]){
    tpredmet element;
    tindeks indeks;
    int brojac_zapisa;

    dat.open(maticna, ios::in | ios::binary);
    if(!dat){ //provjerava ako datoteka maticna postoji
        brojac_zapisa = 0;
        dat.open(maticna, ios::out | ios::binary); //ako ne postoji stvara datoteku maticnu
        ind.open(indeksna, ios::out | ios::binary); //stvara i indeksnu
    }else{ //datoteka postoji
        dat.seekg(0, ios::end); //pokazivac citanja se postavlja na kraj datoteke
        brojac_zapisa = dat.tellg() / sizeof(tpredmet); //broj zapisa je adresa na kojoj je pokazivac citanja / velicinu predmeta
        dat.close(); dat.clear(); 
        dat.open(maticna, ios::out | ios::in | ios::ate | ios::binary);
        ind.open(indeksna, ios::out | ios::in | ios::ate | ios::binary);
    }
    
    brojac_zapisa++;
    cout << "\nZapis broja: " << brojac_zapisa << endl;
    element.rb_zapisa = brojac_zapisa;
    cout << "Sifra: "; cin >> element.sifra; cin.ignore();
    cout << "Naziv predmeta: "; cin.getline(element.naziv, 50);
    cout << "Smjer: "; cin.getline(element.smjer, 50);
    cout << "Broj prijava: "; cin >> element.broj_prijava;

    indeks.sifra = element.sifra;
    indeks.adresa = (int)dat.tellp(); //adresa je int vrijednost adrese na koju pokazuje pokazivac za pisanje
    dat.write((char*)&element, sizeof(tpredmet));
    ind.write((char*)&indeks, sizeof(tindeks));
    dat.close(); dat.clear();
    ind.close(); ind.clear();
}

int main(){
    int izbor = 0;
    char maticna[50] = "predmet.dat";
    char indeksna[50] = "predmet.ind";

    do{
        cout << "Izbornik: " << endl;
        cout << "   1. Kreiranje maticne i indeksne datoteke\n";
        cout << "   2. Rucni unos podataka u maticnu i indeksnu datoteku\n";
        cout << "   3. Pretrazivanje indeksirane datoteke prema primarnom kljucu\n";
        cout << "   4. Ispis sadrzaja maticne datoteke uz pomoc indeksirane datoteke\n";
        cout << "   9. Izlaz iz programa\n";
        cout << "Izbor: "; cin >> izbor;

        switch(izbor){
            case 1:
                char izbor;
                cout << "\nZelite li sami zadati ime datoteka[Y/N]: "; cin >> izbor;
                if(izbor == 'Y'){
                    cin.ignore();
                    cout << "Unesite ime maticne datoteke: "; cin.getline(maticna, 50);
                    cout << "Unesite ime indeksne datoteke: "; cin.getline(indeksna, 50);
                    kreiranje(maticna, indeksna);
                }else{
                    kreiranje(maticna, indeksna);
                }
            case 2:
                rucni_unos(maticna, indeksna);
        }
    }while(izbor != 9);
}