#include<iostream>
#include<fstream>
#include "../biblioteka_vrijeme_i_binarno_pretrazivanje_linux.cc"
using namespace std;

struct tpredmet{
    int rb_zapisa;
    int sifra;
    char naziv[50];
    char smjer[50];
    int broj_prijava;
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
        //otvara datoteke u potrebnim modovima
        dat.open(maticna, ios::out | ios::in | ios::ate | ios::binary); 
        ind.open(indeksna, ios::out | ios::in | ios::ate | ios::binary);
    }
    
    //unos informacija u maticnu datoteku
    brojac_zapisa++;
    cout << "\nZapis broja: " << brojac_zapisa << endl;
    element.rb_zapisa = brojac_zapisa;
    cout << "Sifra: "; cin >> element.sifra; cin.ignore();
    cout << "Naziv predmeta: "; cin.getline(element.naziv, 50);
    cout << "Smjer: "; cin.getline(element.smjer, 50);
    cout << "Broj prijava: "; cin >> element.broj_prijava;

    //unos informacija u indeksnu datoteku
    indeks.sifra = element.sifra;
    indeks.adresa = (int)dat.tellp(); //adresa je int vrijednost adrese na koju pokazuje pokazivac za pisanje
    dat.write((char*)&element, sizeof(tpredmet));
    ind.write((char*)&indeks, sizeof(tindeks));
    dat.close(); dat.clear();
    ind.close(); ind.clear();
}

void ispis(char maticna[], char indeksna[]){ //funkcija za ispis pomocu indeksne datoteke
    int broj_zapisa = 0;
    tpredmet element;
    tindeks indeks;
    dat.open(maticna, ios::in | ios::binary);
    ind.open(indeksna, ios::in | ios::binary);

    while(true){
        ind.read((char*)&indeks, sizeof(tindeks)); //procita indeksnu datoteku
        if(ind.eof()) break; //ako je kraj - break loop
        else{
            cout << "\n---Element---\n";
            cout << "Sifra u indeksnoj datoteci: " << indeks.sifra << endl;
            cout << "Adresa u indeksnoj datoteci: " << indeks.adresa << endl;
            dat.seekg(indeks.adresa); //postavlja pokazivac za citanje na adresu koja je zapisana u indeksnoj
            //ispisuje ostale podatke iz maticne datoteke
            dat.read((char*)&element, sizeof(tpredmet));
            cout << "Redni broj zapisa: " << element.rb_zapisa << endl;
            cout << "Naziv predmeta: " << element.naziv << endl;
            cout << "Smjer predmeta: " << element.smjer << endl;
            cout << "Broj prijavljenih: " << element.broj_prijava << endl;
            cout << "-------------\n";
            broj_zapisa++;
        }
    }
    cout << "\nBroj zapisa u datoteci: " << broj_zapisa << endl << endl;
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
                    cout << endl;
                    kreiranje(maticna, indeksna);
                }else{
                    kreiranje(maticna, indeksna);
                    cout << endl;
                }
                break;
            case 2:
                rucni_unos(maticna, indeksna);
                break;
            case 3:
                break;
            case 4:
                ispis(maticna, indeksna);
                break;
            case 9:
                break;
            default:
                cout << "\nPogresan unos\n";
        }
    }while(izbor != 9);
}