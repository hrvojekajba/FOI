#include<iostream>
#include<cstring>

using namespace std;

class croba{
    private:
        int sifra;
        char proizvodac[50];
        float cijena;
        int godina;
        croba *sljedeci;
    public:
        croba(){
            cout << "\nAlociram element liste.\n";
            this->sifra = 0;
            strcpy(this->proizvodac, "");
            this->cijena = 0;
            this->godina = 0;
            this->sljedeci = NULL;
        }
        ~croba(){
            cout << "Dealociram: " << this->sifra << endl;
        }

        void unos(){
            croba *zadnji = this;
            while(zadnji->sljedeci) zadnji = sljedeci;

            croba *novi = new croba;
            cout << "\nUnesite sifru: "; cin >> novi->sifra; cin.ignore();
            cout << "Unesite proizvodaca: "; cin.getline(this->proizvodac, 50);
            cout << "Unesite cijenu: "; cin >> novi->cijena;
            cout << "Unesite godinu proizvodnje: "; cin >> novi->godina;
            novi->sljedeci = NULL;
            zadnji->sljedeci = novi;
        }

        void ispis(){
            croba *tekuci = this->sljedeci;

            while(tekuci){
                cout << "\nSifra: " << tekuci->sifra;
                cout << "\nProizvodac: " << tekuci->proizvodac;
                cout << "\nCijena: " << tekuci->cijena;
                cout << "\nGodina: " << tekuci->godina;
                cout << "\nSljedeci: " << tekuci->sljedeci << endl;
                tekuci = tekuci->sljedeci;
            }
        }

        void dealokacija(){
            croba *prethodni = this;
            croba *tekuci = this->sljedeci;

            while(tekuci){
                if(prethodni != this) delete prethodni;
                prethodni = tekuci;
                tekuci = tekuci->sljedeci;
            }
            delete prethodni;
            this->sljedeci = NULL;
        }

        bool postoji_element(){
            if(this->sljedeci == NULL) return false;
            return true;
        }
};

int main(){
    int izbor = 0, velicina_polja = -1, indeks = -1;
    croba *glava = NULL;
    croba *polje = NULL;

    do{
        cout << "Izbornik:\n";
        cout << "   1. Alokacija glave i unos elementa\n";
        cout << "   2. Ispis elementa i upit o dealokaciji\n";
        cout << "   3. Alokacija polja i upis odredene liste\n";
        cout << "   4. Ispis odredene liste i dealokacija odredene liste\n";
        cout << "   9. Izlaz\n";
        cout << "Izbor: "; cin >> izbor;

        switch(izbor){
            case 1:
                if(!glava){
                    glava = new croba;
                }
                glava->unos();
                break;
            case 2:
                if(!glava){
                    cout << "\nNe mogu ispisati, vezana lista nije alocirana!\n\n";
                    break;
                }
                if(!glava->postoji_element()){
                    cout << "\nNe mogu ispisati, vezana liste nema sadrzaj!\n\n";
                    break;
                }

                cout << "\nIspis vezane liste:\n";
                glava->ispis();

                char odabir;
                cout << "\nZelite li dealocirati vezanu listu [d/n]: "; cin >> odabir;

                if(odabir == 'd' || odabir == 'D'){
                    cout << "Dealociram listu\n";
                    glava->dealokacija();
                }
                break;
            case 3:
                if(!polje){
                    do{
                        cout << "\nKoliko veliko polje zelite inicijalizirati? "; cin >> velicina_polja;
                    }while(velicina_polja <= 0);
                    polje = new croba[velicina_polja];
                }

                do{
                    cout << "\nNa kojem indeksu zelite upisati sadrzaj u vezanu listu [0 - " << velicina_polja-1 << "]: ";
                    cin >> indeks;
                }while(indeks < 0 || indeks >= velicina_polja);

                polje[indeks].unos();
                break;
            case 4:
                if(!polje){
                    cout << "\nNe mogu ispisati, polje nije inicijalizirano\n";
                    break;
                }

                do{
                    cout << "\nNa kojem indeksu zelite ispisati sadrzaj vezane liste [0 - " << velicina_polja-1 << "]: ";
                    cin >> indeks;
                }while(indeks < 0 || indeks >= velicina_polja);

                if(!polje[indeks].postoji_element()){
                    cout << "\nNe mogu ispisati sadrzaj, vezana lista na tom indeksu je prazna\n";
                    break;
                }
                polje[indeks].ispis();
                break;
            case 9:
                break;
            default:
                cout << "\nPogresan unos...\n";
                break;
        }
    }while(izbor != 9);
}