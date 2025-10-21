#include<iostream>
#include<fstream>
#include<cmath>
#include"../biblioteka_vrijeme_linux.cc"

using namespace std;

struct element{
    int redni_broj;
    int sifra;
    char naziv[50];
    char proizvodac[50];
    int godina;
};

int global_prosti = 0;

bool prosti_broj(int velicina_datoteke){
    for(int i = 2; i < sqrt(velicina_datoteke); i++){
        if(velicina_datoteke % i == 0) return false;
    }
    return true;
}

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
        if(prost == true) return i;
    }
    return 0;
}

void kreiraj_datoteku(char datoteka[], int velicina_datoteke){
    global_prosti = prvi_manji_prosti(velicina_datoteke);
    cout << "\nPrvi manji prosti broj od velicine datoteke: " << global_prosti << endl;

    element temp;
    temp.sifra = 0;
    temp.proizvodac[0] = '\0';
    temp.naziv[0] = '\0';
    temp.godina = 0;
    fstream dat(datoteka, ios::out | ios::binary);

    for(int i = 0; i < velicina_datoteke; i++){
        temp.redni_broj = i;
        dat.write((char*)&temp, sizeof(element));
    }
    dat.close();
    dat.clear();
}

void unos_zapisa(char datoteka[], int velicina_datoteke){
    element novi;
    cin.ignore();
    cout << "\nNaziv proizvoda: "; cin.getline(novi.naziv, 50); 
    cout << "Naziv proizvodaca: "; cin.getline(novi.proizvodac, 50); 
    cout << "Godina proizvodnje: "; cin >> novi.godina;
    do{
        cout << "Sifra (mora biti veca od 0): "; cin >> novi.sifra;
    }while(novi.sifra <= 0);

    int redni_broj = novi.sifra % global_prosti;
    cout << "Redni broj zapisa: " << redni_broj << endl;
    cout << "Adresa zapisa: " << redni_broj * sizeof(element) << endl;

    element temp;
    fstream dat(datoteka, ios::in | ios::out | ios::binary);

    dat.seekg(redni_broj * sizeof(element));

    do{
        dat.read((char*)&temp, sizeof(element));
    }while(temp.sifra > 0);

    redni_broj = (dat.tellg() / sizeof(element)) - 1;

    dat.seekp(redni_broj * sizeof(element));

    novi.redni_broj = temp.redni_broj;
    dat.write((char*)&novi, sizeof(element));
    dat.close();
    dat.clear();
}

void ispis(char datoteka[]){
    int broj_praznih = 0;
    int broj_zapisa = 0;
    element zapis;
    fstream dat(datoteka, ios::in | ios::binary);

    while(true){
        dat.read((char*)&zapis, sizeof(element));
        if(dat.eof()) break;
        if(zapis.sifra > 0){
            cout << "\n----------";
            cout << "\nRedni broj: " << zapis.redni_broj << endl;
            cout << "Adresa: " << zapis.redni_broj * sizeof(element) << endl;
            cout << "Sifra: " << zapis.sifra << endl;
            cout << "Naziv proizvoda: " << zapis.naziv << endl;
            cout << "Proizvodac: " << zapis.proizvodac << endl;
            cout << "Godina proizvodnje: " << zapis.godina << endl;
            cout << "----------\n";
            broj_zapisa++;
        }else{
            broj_praznih++;
        }
    }
    dat.close();
    dat.clear();
    cout << "\nBroj popunjenih zapisa: " << broj_zapisa << endl;
    cout << "Broj praznih zapisa: " << broj_praznih << endl;
}

int main(){
    int izbor, velicina_datoteke;
    char datoteka[12] = "podatci.dat";

    do{
        cout << "\n---Izbornik---\n";
        cout << "   1. Kreiranje datoteke praznih zapisa i racunanje prostog broja\n";
        cout << "   2. Unos podataka u datoteku (uvazavajuci duplikate)\n";
        cout << "   3. Pretrazivanje relativne datoteke uz prepoznavanje duplikata\n";
        cout << "   4. Ispis svih nepraznih zapisa i statistika\n";
        cout << "   9. Izlaz iz programa\n";
        cout << "Izbor: "; cin >> izbor;

        switch(izbor){
            case 1:
                cout << "\n";
                do{
                    cout << "Unesite velicinu datoteke koju zelite kreirati: "; cin >> velicina_datoteke;
                }while(velicina_datoteke < 10 || velicina_datoteke > 100 || prosti_broj(velicina_datoteke));
                kreiraj_datoteku(datoteka, velicina_datoteke);
                break;
            case 2:
                cout << "\nUnos podataka u datoteku...";
                unos_zapisa(datoteka, velicina_datoteke);
                break;
            case 4:
                cout << "\nIspis svih zapisa...";
                ispis(datoteka);
                break;
            case 9: break;
            default: cout << "\nPogresan unos...\n";
        }
    }while(izbor != 9);
    return 0;
}