#include<iostream>
#include<fstream>
#include<cstring>
#include "../biblioteka_vrijeme_linux.cc"
using namespace std;

struct inventar{
    int sifra;
    char naziv[50];
    int cijena;
    int prostorija;
};

struct inventar_lista{
    int sifra;
    char naziv[50];
    int cijena;
    int prostorija;
    inventar_lista* sljedeci;
};

char datoteka[] = "inventar.dat";

//provjera statusa datoteke i liste
void status_datoteke(inventar_lista *glava){
    fstream dat(datoteka, ios::in | ios::binary);

    if(!dat){
        cout << "\n1. Datoteka ne postoji\n";
        cout << "2. Velicina datoteke na disku: 0\n";
    }else{
        cout << "\n1. Datoteka postoji\n";
        dat.seekg(0, ios::end);
        cout << "2. Velicina datoteke na disku: " << dat.tellg() << "\n";
    }
    dat.close(); dat.clear();

    if(glava == NULL){
        cout << "3. Glava liste ne postoji\n";
    }else{
        cout << "3. Glava liste postoji\n";
    }

    if(glava && glava->sljedeci == NULL){
        cout << "4. Vezana lista je prazna\n";
    }else if(glava){
        cout << "4. Vezana lista nije prazna\n";
    }
    cout << "\n";
}

//kreiranje datoteke i alokacija vezane liste
void kreiraj(inventar_lista *&glava){
    fstream dat(datoteka, ios::in);

    if(dat){
        char izbor;
        cout << "Datoteka vec postoji, zelite li kreirati novu[d/n]: ";
        cin >> izbor;
        if(izbor == 'd'){
            remove(datoteka);
        }else if(izbor == 'n'){
            cout << "Ne kreiram novu datoteku...\n\n";
            return;
        }
    }
    dat.close(); dat.clear();

    dat.open(datoteka, ios::out | ios::binary);
    dat.close(); dat.clear();
    glava = new inventar_lista;
    glava->sljedeci = NULL;
    cout << "Nova datoteka i vezana lista uspješno kreirani\n\n";
}

void unos(){
    inventar element;

    cout << "\nUnesite sifru: "; cin >> element.sifra;
    cin.ignore();
    cout << "Unesite naziv: "; cin.getline(element.naziv, 50);
    cout << "Unesite cijenu: "; cin >> element.cijena;
    cout << "Unesite broj prostorije: "; cin >> element.prostorija;

    fstream dat(datoteka, ios::app | ios::binary);
    dat.write((char*)&element, sizeof(inventar));
    dat.close(); dat.clear();
}

void dealociraj(inventar_lista *glava){
    inventar_lista *tekuci = glava->sljedeci;
    inventar_lista *prethodni;

    while(tekuci){
        prethodni = tekuci;
        tekuci = tekuci->sljedeci;
        delete prethodni;
    }
    glava->sljedeci = NULL;
}

void kopiranje(inventar_lista *glava){
    fstream dat(datoteka, ios::in | ios::binary);
    if(!dat){
        cout << "\nKopiranje nije moguce - datoteka ne postoji!\n\n";
        return;
    }

    dealociraj(glava);
    inventar element;
    inventar_lista *novi = NULL;
    inventar_lista *zadnji = glava;

    while(dat.read((char*)&element, sizeof(inventar))){
        novi = new inventar_lista; //inicijaliziraj novi element
        //upisi podatke u novi element
        novi->sifra = element.sifra;
        strcpy(novi->naziv, element.naziv);
        novi->cijena = element.cijena;
        novi->prostorija = element.prostorija;
        //postavi novi kao element nakon trenutnog zadnjeg, te onda postavi zadnji kao taj element
        novi->sljedeci = NULL;
        zadnji->sljedeci = novi;
        zadnji = novi;
    }
    dat.close(); dat.clear();
    cout << "\nZapisi kopirani\n\n";
}

void ispis(inventar_lista *glava){
    inventar_lista *tekuci = glava->sljedeci;

    while(tekuci){
        cout << "\nSifra: " << tekuci->sifra;
        cout << "\nNaziv: " << tekuci->naziv;
        cout << "\nCijena: " << tekuci->cijena;
        cout << "\nProstorija: " << tekuci->prostorija << "\n\n";
        tekuci = tekuci->sljedeci;
    }
    if(glava->sljedeci = NULL){
        cout << "\nIspis nije moguc - lista je prazna\n\n";
    }
}

int main(){
    int izbor;
    inventar_lista *glava = NULL;

    do{
        cout << "---IZBORNIK---\n";
        cout << "   0. Status\n";
        cout << "   1. Kreiranje i alokacija\n";
        cout << "   2. Rucni unos\n";
        cout << "   3. Kopiranje\n";
        cout << "   4. Ispis\n";
        cout << "   9. Izlaz\n";
        cout << "Izbor: "; cin >> izbor;

        switch(izbor){
            case 0:
                status_datoteke(glava); break;
            case 1:
                kreiraj(glava); break;
            case 2:
                unos(); break;
            case 3:
                kopiranje(glava); break;
            case 4:
                ispis(glava); break;
            case 9:
                break;
            default:
                cout << "\nPogresan unos!\n\n";
        }
    }while(izbor != 9);
}
