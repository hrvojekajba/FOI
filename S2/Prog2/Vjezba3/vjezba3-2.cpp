#include<iostream>
#include<cstring>
#include "../biblioteka_vrijeme_linux.cc"

//struktura liste
struct lista{
    int sifra;
    char naziv[30];
    char proizvodac[30];
    int cijena;
    double vrijeme_unosa;
    lista *sljedeci = nullptr;
    lista *prethodni = nullptr;
};

//struktura stabla
struct stablo{
    int sifra;
    char naziv[30];
    char proizvodac[30];
    int cijena;
    double vrijeme_unosa;
    stablo *lijevi;
    stablo *desno;
};

void dodaj_kraj(lista *glava){
    lista *novi = new lista; //inicijaliziraj novi
    lista *zadnji = glava; //inicijaliziraj zadnji kao glavu liste
    lista *tekuci = glava->sljedeci; //inicijaliziraj tekuci -- treba ti za ispis

    std::cout << "\n";
    while(tekuci){ // iteriraj i ispisuj do kraja liste
        std::cout << "Sifra proizvoda: " << tekuci->sifra << "\n";
        tekuci = tekuci->sljedeci;
    }

    while(zadnji->sljedeci) zadnji = zadnji->sljedeci; //iteriraj zadnjeg do kraja liste

    zadnji->sljedeci = novi; //postavi zadnji->sljedeci na novi unos
    novi->prethodni = zadnji; //postavi novi->prethodni na prijasnji zadnji
    novi->sljedeci = nullptr; //novi->sljedeci na nullptr jer je zadnja stavka od sad

    //unos
    vrijeme_pocetak();
    std::cout << "Unesite sifru proizvoda: "; std::cin >> novi->sifra; std::cin.ignore();
    std::cout << "Unesite ime proizvoda: "; std::cin.getline(novi->naziv, 30);
    std::cout << "Unesite ime proizvodaca: "; std::cin.getline(novi->proizvodac, 30);
    std::cout << "Unesite cijenu proizvoda: "; std::cin >> novi->cijena;
    vrijeme_kraj;
    novi->vrijeme_unosa = vrijeme_proteklo() / 1000;
    std::cout << "\n";
}

void dodaj_pocetak(lista *glava){
    if (glava->sljedeci == nullptr){ //provjeri ako je lista prazna, ako je idi na dodaj_kraj()
        std::cout << "\nLista je prazna, dodajem na kraj...\n";
        dodaj_kraj(glava);
    }
    lista *novi = new lista; //inicijaliziraj novi
    lista *sljedeci = glava->sljedeci; //postavi sljedeci kao prvi tekuci element (prvi element s podatcima)

    novi->prethodni = glava; //postavi prethodni od novi na glavu
    novi->sljedeci = sljedeci; //postavi sljedeci od novi na sljedeci (tekuci)

    glava->sljedeci = novi; //glava->sljedeci na novi
    sljedeci->prethodni = novi; //sljedeci(tekuci)->prethodni na novi -- NOVI POSTAJE PRVI TEKUCI ELEMENT

    //unos
    vrijeme_pocetak();
    std::cout << "\n---Unos pocetak---";
    std::cout << "\nUnesite sifru proizvoda: "; std::cin >> novi->sifra; std::cin.ignore();
    std::cout << "Unesite ime proizvoda: "; std::cin >> novi->naziv; 
    std::cout << "Unesite ime proizvodaca: "; std::cin >> novi->proizvodac;
    std::cout << "Unesite cijenu proizvoda: "; std::cin >> novi->cijena;
    vrijeme_kraj();
    novi->vrijeme_unosa = vrijeme_proteklo() / 1000;
    std::cout << "------------------\n";

    //ispis od kraja
    lista *zadnji = glava;
    while(zadnji->sljedeci != nullptr) zadnji = zadnji->sljedeci; //prvo iteriras do kraja
    while(zadnji->prethodni != nullptr){ //i onda vise manje ides unatrag do glave opet
        std::cout << "\n---Ispis od kraja---";
        std::cout << "\nSifra proizvoda: " << zadnji->sifra << "\n";
        std::cout << "Ime proizvoda: " << zadnji->naziv << "\n";
        std::cout << "Ime proizvodaca: " << zadnji->proizvodac << "\n";
        std::cout << "Cijena proizvoda: " << zadnji->cijena << "\n";
        std::cout << "Vrijeme unosa: " << zadnji->vrijeme_unosa << "\n";
        std::cout << "--------------------\n";
        zadnji = zadnji->prethodni;
    }
    std::cout << "\n";
}

void brisanje(lista *glava){
    int unos;
    std::cout << "\nUnesite sifru elementa kojeg zelite izbrisati: "; std::cin >> unos; //unos sifre koju zelimo izbrisat

    lista *prethodni = glava; //prethodni na onaj prije brisi
    lista *brisi = glava->sljedeci; //brisi inicijaliziras na prvi tekuci element
    bool brisanje = false; //bool var s kojom pratimo brisanje

    while(brisi){ //iteriraj kroz listu
        if (brisi->sifra == unos){ //ako pronades stavku
            prethodni->sljedeci = brisi->sljedeci; //prethodni->sljedeci ide na brisi->sljedeci, tj ide na stavku nakon brisi
            brisi->sljedeci->prethodni = brisi->prethodni; 
            /*
            ok, ovo je jako jebeno retardirano, ali pazi sad ovo
            uzmes brisi->sljedeci->prethodni KOJI JE ZAPRAVO ->prethodni OD STAVKE NAKON BRISI (KUIS)
            i onda ga zadas na brisi->prethodni, tj stavku prije brisi
            */
            delete brisi; //boom brisi
            brisanje = true; //brisanje je true
            break; //kraj loopa, izbrisal si ono kaj trazis
        }
        prethodni = prethodni->sljedeci; //dalje iteriraj kroz loop ak if() nije ostvaren
        brisi = brisi->sljedeci;
    }
    //mali if statement koji ispise ak je element izbrisan ili ak ga nemre nac
    if(brisanje){
        std::cout << "Element izbrisan\n\n";
    }else{
        std::cout << "Ne mogu pronaci element\n\n";
    }
}

//TODO: napravi kopiranje
void kopiraj(lista *gl_lista, stablo *gl_stablo){
    lista *tekuci_lista = gl_lista->sljedeci; //inicijaliziraj prvi podatkovni element liste (prvi element koji mozes kopirati)

    while(tekuci_lista){ //iteriraj kroz sve elemente liste
        stablo *novi = new stablo; //novi cvor stabla
        //kopiranje podataka u novi cvor
        novi->sifra = tekuci_lista->sifra;
        novi->cijena = tekuci_lista->cijena;
        novi->vrijeme_unosa = tekuci_lista->vrijeme_unosa;
        std::strcpy(novi->naziv, tekuci_lista->naziv);
        std::strcpy(novi->proizvodac, tekuci_lista->proizvodac);
        novi->desno = nullptr;
        novi->lijevi = nullptr;

        stablo *zadnji = gl_stablo; //vrh stabla
        bool dalje = true; //pomocna bool var

        do{ //radi ovaj loop sve dok se ne upise cvor
            if (novi->sifra > zadnji->sifra){ //ako je sifra veca od trenutne sifre, ides DESNO
                if(zadnji->desno != nullptr){ //ako desno nije prazno, iteriraj dalje
                    zadnji = zadnji->desno;
                }
                else{
                    zadnji->desno = novi; //ako desno je prazno, upisi cvor i stavi dalje false
                    dalje = false;
                }
            }
            else{ //ako je sifra manja od trenutnog cvora ides LIJEVO
                if(zadnji->lijevi != nullptr){
                    zadnji = zadnji->lijevi; //ako lijevo nije prazno, iteriraj dalje
                }
                else{ //ako lijevo JE prazno, dodaj element i stavi dalje na false
                    zadnji->lijevi = novi;
                    dalje = false;
                }
            }
        }while(dalje);
        tekuci_lista = tekuci_lista->sljedeci; //iteriraj na sljedeci element liste
    }
}

void ispisi_elemente_stabla(stablo *glava){
    std::cout << "\nNaziv: " << glava->naziv << "\n";
    std::cout << "Proizvodac: " << glava->proizvodac << "\n";
    std::cout << "Cijena: " << glava->cijena << "\n";
    std::cout << "Sifra: " << glava->sifra << "\n\n";
}

void ispisi_stablo(stablo *glava){
    static stablo *korijen = glava; //staticni inicijaliziraj korijen

    if(glava == nullptr) return; //ako je glava nullptr, tj stablo je prazno, breakaj func

    ispisi_stablo(glava->lijevi); //rekurzivni poziv na lijevi (manju) stranu stabla -- vise manje ides sve dok lijevoga nema vise

    if(glava != korijen) ispisi_elemente_stabla(glava); //ako glava, tj vrijednost prosljedena funkciji nije korijen (prvi element stabla) pisi
    ispisi_stablo(glava->desno); //rekurzivni poziv na desno -- polagano ides na desno od skroz lijevo
}

int main(){
    int izbor = 0;
    lista *gl_lista = new lista;
    gl_lista->prethodni = nullptr;
    gl_lista->sljedeci = nullptr;
    
    stablo *gl_stablo = new stablo;
    gl_stablo->lijevi = nullptr;
    gl_stablo->desno = nullptr;

    do{
        std::cout << "Izbornik: \n";
        std::cout << "  1. Dodavanje elementa na kraj vezane liste\n";
        std::cout << "  2. Dodavanje elementa na pocetak vezane liste\n";
        std::cout << "  3. Brisanje elementa sa vezane liste\n";
        std::cout << "  4. Binarno stablo\n";
        std::cout << "  9. Izlaz iz programa\n";
        std::cout << "Izbor: "; std::cin >> izbor;

        switch(izbor){
            case 1: dodaj_kraj(gl_lista); break;
            case 2: dodaj_pocetak(gl_lista); break;
            case 3: brisanje(gl_lista); break;
            case 4: kopiraj(gl_lista, gl_stablo); ispisi_stablo(gl_stablo); break;
            case 9: break;
            default: std::cout << "\nPogresan unos...\n";
        }
    }while(izbor != 9);
}