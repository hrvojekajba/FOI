#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class cstavka{
    private:
        int sifra;
        int godina;
        float cijena;
        char proizvodac[50];
        cstavka *sljedeci;

    public:
        cstavka(){
            if(this->sljedeci == nullptr){
                cout << "\nAlociram objekt\n";
            }
            this->sifra = 0;
            this->godina = 0;
            this->cijena = 0;
            strcpy(this->proizvodac, "");
            this->sljedeci = nullptr;
        }

        ~cstavka(){
            cout << "Dealociram element: " << this->sifra << endl;
        }

        void unos(){
            cstavka *zadnji = this;

            while(zadnji->sljedeci){
                zadnji = sljedeci;
            }

            cstavka *novi = new cstavka;
            cout << "\nSifra: "; cin >> novi->sifra;
            cout << "Godina: "; cin >> novi->godina;
            cout << "Cijena: "; cin >> novi->cijena; cin.ignore();
            cout << "Proizvodac: "; cin.getline(novi->proizvodac, 50);
            novi->sljedeci = nullptr;

            zadnji->sljedeci = novi;
        }

        void ispis(){
            cstavka *tekuci = this->sljedeci;

            while(tekuci){
                cout << "\n---Element---\n";
                cout << "Sifra: " << tekuci->sifra << endl;
                cout << "Godina: " << tekuci->godina << endl;
                cout << "Cijena: " << tekuci->cijena << endl;
                cout << "Proizvodac: " << tekuci->proizvodac << endl;
                cout << "Sljedeci: " << tekuci->sljedeci << endl;
                cout << "-------------\n";
                tekuci = tekuci->sljedeci;
            }
        }

        void dealokacija(){
            cstavka *prethodni = this;
            cstavka *tekuci = this->sljedeci;

            while(tekuci){
                if(prethodni != this){
                    delete prethodni;
                }
                prethodni = tekuci;
                tekuci = tekuci->sljedeci;
            }
            delete prethodni;
            this->sljedeci = nullptr;
        }

        bool postoji_sljedeci(){
            if(this->sljedeci == NULL){
                return false;
            }
            return true;
        }
};

int main(){
    int izbor = 0, broj_elemenata = 0, indeks = -1;

    cstavka *glava = NULL;
    cstavka *polje = NULL;

    do{
        cout << "\n---Izbornik---\n";
        cout << "   1. Alokacija jednog elementa, unos u listu\n";
        cout << "   2. Ispis liste, upit za dealokaciju\n";
        cout << "   3. Alokacija polja vezanih lista, unos u odabrani element\n";
        cout << "   4. Ispis elementa odabrane liste, upit o dealokaciji\n";
        cout << "   9. Izlaz iz programa\n";
        cout << "Izbor: "; cin >> izbor;

        switch(izbor){
            case 1:
                cout << endl;
                if(!glava){
                    glava = new cstavka;
                }
                glava->unos();
                break;
            case 2:
                cout << endl;
                if(!glava){
                    cout << "Glava liste nije alocirana, ispis nije moguc\n"; break;
                }
                if(!glava->postoji_sljedeci()){
                    cout << "Lista je prazna, ispis nije moguc\n"; break;
                }

                cout << "Ispis svih elemenata liste:\n";
                glava->ispis();

                char odabir;
                cout << "\nZelite li dealocirati listu[d/n]: "; cin >> odabir;

                if(odabir == 'd' || odabir == 'D'){
                    glava->dealokacija();
                }
                break;
            case 3:
                cout << endl;
                if(!polje){
                    do{
                        cout << "\nBroj elemenata polja: "; cin >> broj_elemenata;
                    }while(broj_elemenata <= 0);
                    polje = new cstavka[broj_elemenata];
                }
                do{
                     cout << "Unos elementa na indeks[0 - " << broj_elemenata-1 << "]: "; cin >> indeks;
                }while(indeks < 0 || indeks >= broj_elemenata);

                polje[indeks].unos();
                break;
            case 4:
                cout << endl;
                if(!polje){
                    cout << "Polje nije alocirano, ispis nije moguc\n"; break;
                }
                do{
                    cout << "Ispis elementa na indeksu[0 - " << broj_elemenata-1 << "]: "; cin >> indeks;
                }while(indeks < 0 || indeks >= broj_elemenata);

                if(!polje[indeks].postoji_sljedeci()){
                    cout << "Lista na tom indeksu je prazna. ispis nije moguc\n";
                    break;
                }
                polje[indeks].ispis();
                break;
            case 9:
                break;
            default:
                cout << "\nPogresan unos...\n\n"; break;
        }
    }while(izbor != 9);

    return 0;
}