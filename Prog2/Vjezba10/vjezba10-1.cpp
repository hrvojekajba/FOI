#include<iostream>
#include<cstring>

using namespace std;

//element_kategorija -- element liste
class element_kategorija {
    public:
        int sifra_kategorija;
        char naziv[50];
        static int broj_autora;

        element_kategorija(){
            cout << "Alociram 'element_kategorija'\n";
            this->sifra_kategorija = -1;
            strcpy(this->naziv, "");
        }

        void unos(){
            cout << "\nSifra: "; cin >> this->sifra_kategorija; cin.ignore();
            cout << "Naziv"; cin.getline(this->naziv, 50);
        }

        void ispis(){
            cout << "Sifra: " << this->sifra_kategorija << endl;
            cout << "Naziv: " << this->naziv << endl;
            cout << endl;
        }
};

int element_kategorija::broj_autora = 0;

//lista_kategorija -- klasa koja definira listu
class lista_kategorija {
    public:
        element_kategorija kategorija;
        lista_kategorija *sljedeci;

        lista_kategorija(){
            cout << "Alociram 'lista_kategorija'\n";
            this->sljedeci = NULL;
        }
};

//element_autori -- element liste
class element_autori {
    public:
        int sifra_autor;
        int sifra_kategorija;
        char maticni_broj_autora[10];

        element_autori(){
            cout << "Alociram element 'element_autori'\n";
            this->sifra_autor = -1;
            this->sifra_kategorija = -1;
            strcpy(this->maticni_broj_autora, "");
        }

        void unos(){
            cout << "Sifra autora: "; cin >> this->sifra_autor;
            cout << "Sifra kategorije: "; cin >> this->sifra_kategorija; cin.ignore();
            cout << "Maticni broj autora: "; cin.getline(this->maticni_broj_autora, 10);
        }

        void ispis(){
            cout << "Sifra autora: " << this->sifra_autor << endl;
            cout << "Sifra kategorije: " << this->sifra_kategorija << endl;
            cout << "Maticni broj autora: " << this->maticni_broj_autora << endl;
        }
};

//lista_autori -- klasa koja deklarira listu
class lista_autori {
    public:
        element_autori *autor;
        lista_autori *sljedeci;

        lista_autori(){
            cout << "Alociram 'lista_autori'\n";
            this->sljedeci = NULL;
            this->autor = new element_autori;
        }

        ~lista_autori(){
            delete autor;
        }
};

void unos_nove_kategorije(lista_kategorija *glava){
    lista_kategorija *zadnji = glava;
    while(zadnji->sljedeci) zadnji = zadnji->sljedeci;

    lista_kategorija *novi = new lista_kategorija;
    novi->kategorija.unos();
    zadnji->sljedeci = novi;
}

void ispis_svih_kategorija(lista_kategorija *glava){
    cout << "\nIspis svih kategorija\n";

    if(glava->sljedeci = NULL) cout << "\nLista je prazna, ispis nije moguc\n\n"; return;

    lista_kategorija *ispis = glava->sljedeci;
    while(ispis){
        ispis->kategorija.ispis();
        ispis = ispis->sljedeci;
    }
}

void unos_novog_autora(lista_autori *glava){
    lista_autori *zadnji = glava;
    while(zadnji->sljedeci) zadnji = zadnji->sljedeci;

    lista_autori *novi = new lista_autori;
    novi->autor->unos();
    zadnji->sljedeci = novi;
}

void ispis_svih_autora(lista_autori *glava){
    cout << "\nIspis svih autora\n";

    if(glava->sljedeci = NULL) cout << "\nLista je prazna, ispis nije moguc\n\n"; return;

    lista_autori *ispis = glava->sljedeci;
    while(ispis){
        ispis->autor->ispis();
        ispis = ispis->sljedeci;
    }
}

void ispis_autora_zadane_kategorije(lista_kategorija *glava_kategorije, lista_autori *glava_autori){
    cout << "\nIspis autora zadane kategorije\n";

    if(glava_kategorije->sljedeci == NULL || glava_autori->sljedeci == NULL){
        cout << "\nJedna ili obije liste su prazne, ispis nije moguc\n\n"; return;
    }

    int sifra_kategorije = -1;
    cout << "\nSifra trazene kategorije: "; cin >> sifra_kategorije;

    bool pronadeno = false;
    lista_kategorija *pretraga = glava_kategorije->sljedeci;
    while(pretraga){
        if(pretraga->kategorija.sifra_kategorija == sifra_kategorije) pronadeno = true; break;
        pretraga = pretraga->sljedeci;
    }

    if(!pronadeno) cout << "\nKategorija s tom sifrom nije pronadena\n\n"; return;

    cout << "\nPronadena kategorija:\n";
    pretraga->kategorija.ispis();

    cout << "\nIspis autora pronadene kategorije:\n";
    lista_autori *ispis = glava_autori->sljedeci;
    while(ispis){
        if(ispis->autor->sifra_kategorija == pretraga->kategorija.sifra_kategorija) ispis->autor->ispis();
        ispis = ispis->sljedeci;
    }
}

int main(){
    int izbor = 0;
    lista_kategorija *glava_kategorije = new lista_kategorija;
    lista_autori *glava_autor = new lista_autori;

    do{
        cout << "\nIzbornik:\n";
        cout << "   1. Unos nove kategorije\n";
        cout << "   2. Unos novog autora\n";
        cout << "   3. Ispis obje liste\n";
        cout << "   4. Ispis svih autora zadane kategorije\n";
        cout << "   9. Izlaz iz programa\n";
        cout << "Izbor: "; cin >> izbor;

        switch(izbor){
            case 1:
                unos_nove_kategorije(glava_kategorije);
                break;
            case 2:
                unos_novog_autora(glava_autor);
                break;
            case 3:
                ispis_svih_kategorija(glava_kategorije);
                ispis_svih_autora(glava_autor);
                break;
            case 4:
                ispis_autora_zadane_kategorije(glava_kategorije, glava_autor);
                break;
            case 9:
                break;
            default:
                cout << "\nPogresan unos...\n\n";
                break;
        }
    }while(izbor != 9);

    return 0;
}