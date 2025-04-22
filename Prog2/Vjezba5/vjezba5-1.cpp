#include<iostream>
#include<cmath>
#include<fstream>
#include"../biblioteka_vrijeme_linux.cc"

using namespace std;

struct element{
    int redni_broj;
    int sifra;
    char ime_prez[50];
    char naslov[50];
};

int global_prosti = 0;

//provjerava ako je velicina datoteke prosti broj -- NE SMIJE BITI PROSTI BROJ
bool provjera_velicine(int velicina_datoteke){
    if(velicina_datoteke <= 1) return false;
    for(int i = 2; i < sqrt(velicina_datoteke); i++){
        if(velicina_datoteke % i == 0) return false;
    }
    return true;
}

//pronalazi prvi prosti broj manji od velicine datoteke (po broju zapisa)
int prvi_manji_prosti(int velicina_datoteke){
    bool prost;
    for(int i = velicina_datoteke - 1; i > 1; i--){
        prost = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                prost = false;
                break;
            }
        }
        if(prost) return i;
    }
    return 0;
}

void kreiraj_datoteku(char datoteka[], int velicina_datoteke){
    global_prosti = prvi_manji_prosti(velicina_datoteke);
    cout << "\nPrvi manji prosti broj: " << global_prosti << "\n";

    element temp;
    temp.sifra = 0;
    temp.ime_prez[0] = '\0';
    temp.naslov[0] = '\0';

    fstream dat(datoteka, ios::out | ios::binary);
    //u datoteku upisujemo placeholder values, vise manje prazno dok ne pocinjemo puniti
    for(int i = 0; i < velicina_datoteke; i++){
        temp.redni_broj = 1;
        dat.write((char*)&temp, sizeof(element));
    }
    dat.close();
    dat.clear();
}

void unos_podataka(char datoteka[]){
    element novi;

    //unos podataka u struct var novi
    cout << "Ime i prezime: "; cin.getline(novi.ime_prez, 50); cin.ignore();
    cout << "Naslov rada: "; cin.getline(novi.naslov, 50);
    //unos sifre -- ponavlja se sve dok se ne unese valjana sifra
    do{
        cout << "Sifra (mora biti > 0): "; cin >> novi.sifra;
    }while(novi.sifra <= 0);

    //pronalazi se redni broj zapisa prema svojoj sifri
    int redni_broj_zapisa = novi.sifra % global_prosti;

    //inicijalizira se temp element i datoteka se otvara
    element temp;
    fstream dat(datoteka, ios::in | ios::out | ios::binary);

    //pokazivac citanja se postavlja na poziciju elementa novi
    dat.seekg(redni_broj_zapisa * sizeof(element));
    
    //cita kroz datoteku dok ne dode do praznoga zapisa
    do{
        dat.read((char*)&temp, sizeof(element));
    }while(temp.sifra > 0);
    //nakon ovoga temp je postavljen na prazni zapis??

    //redni broj zapisa se postavlja kao (pozicija pokazivaca za citanje / velicinu elementa) - 1
    //tellg vraca "broj" na kojem se nalazi pokazivac za citanje
    redni_broj_zapisa = (dat.tellg() / sizeof(element)) - 1;

    //seekp postavlja pokazivac na poziciju u kojoj se treba upisati element novi
    dat.seekp(redni_broj_zapisa * sizeof(element));
    //redni broj od novi se postavlja na redni broj koji smo odredili pomocu temp
    novi.redni_broj = temp.redni_broj;
    //upis u datoteku
    dat.write((char*)&novi, sizeof(element));
    dat.close();
    dat.clear();
}

void pretrazivanje(char datoteka[], int trazena_sifra){
    element zapis;
    fstream dat(datoteka, ios::in | ios::binary);
    bool ispis = false;

    while(true){
        dat.read((char*)&zapis, sizeof(element));
        if(dat.eof()) break;
        if(zapis.sifra == trazena_sifra){
            int zadnja_sifra;
            ispis = true;

            if(zadnja_sifra == zapis.sifra) cout << "\nZapis ima jednaku sifru kao prosli zapis\n";
            zadnja_sifra = zapis.sifra;

            cout << "\nSifra: " << zapis.sifra;
            cout << "\nIme i prezime: " << zapis.ime_prez;
            cout << "\nNaslov rada: " << zapis.naslov << "\n";
        }
    }
    dat.close();
    dat.clear();

    if(ispis == false){
        cout << "\nZapis s tom sifrom nije pronaden!\n\n";
    }
}

void ispis_svih(char datoteka[]){
    int broj_praznih = 0;
    element zapis;
    fstream dat(datoteka, ios::in | ios::binary);

    while(true){
        dat.read((char*)&zapis, sizeof(element));
        if(dat.eof()) break;

        if(zapis.sifra > 0){
            cout << "\nSifra: " << zapis.sifra;
            cout << "\nIme i prezime: " << zapis.ime_prez;
            cout << "\nNaslov rada: " << zapis.naslov << "\n";
        }else{
            broj_praznih++;
        }
    }
    dat.close();
    dat.clear();

    cout << "\nBroj praznih zapisa: " << broj_praznih << "\n";
}

int main(){
    char datoteka[12] = "podatci.dat";
    int velicina_datoteke, trazena_sifra, izbor;

    do{
        cout << "\nIzbornik:\n";
        cout << "   1. Kreiranje prazne datoteke i racunanje prostog broja\n";
        cout << "   2. Unos podataka u datoteku (uz provjeru duplikata)\n";
        cout << "   3. Pretrazivanje datoteke uz prepoznavanje duplikata\n";
        cout << "   4. Ispis svih zapisa iz datoteke\n";
        cout << "Izbor: "; cin >> izbor;

        switch(izbor){
            case 1: 
                cout << "\n";
                do{
                    cout << "Velicina datoteke (u broju zapisa): "; cin >> velicina_datoteke;
                }while(provjera_velicine(velicina_datoteke) || velicina_datoteke < 10); //ako je velicina prosti broj ili manja od 10, pisi ponovo
                kreiraj_datoteku(datoteka, velicina_datoteke);
                cout << "Datoteka kreirana\n";
                break;
            case 2: 
                cout << "\nUnos podataka u datoteku...\n";
                unos_podataka(datoteka);
                break;
            case 3:
                cout << "\nPretrazivanje zapisa\n";
                cout << "Trazena sifra: "; cin >> trazena_sifra;
                pretrazivanje(datoteka, trazena_sifra);
                break;
            case 4:
                cout << "\nIspis svih zapisa:\n";
                ispis_svih(datoteka); 
                break;
            case 9: break;
            default: cout << "\nPogresan unos\n";
        }
    }while(izbor != 9);

    return 0;
}