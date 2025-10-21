#include<iostream>
//definicija strukture vezane liste
struct lista {
    int maticni;
    char ime_prezime[35];
    int godina;
    lista *sljedeci;
}; 

void unos(lista *glava){
    lista *novi_unos, *zadnji; //deklaracija novog unosa i pokazivaca do zadnjeg
    zadnji = glava; //inicijalizacije pokazivaca na glavu

    while (zadnji->sljedeci != nullptr) zadnji = zadnji->sljedeci; //loop se vrti dok ne dodemo do zadnje stavke

    novi_unos = new lista; //inicijalizacija novog unosa
    zadnji->sljedeci = novi_unos;
    novi_unos->sljedeci = nullptr; //deklaracija da je novi unos zadnja stavka (zadnji pokazivac mora biti nullptr)
    //unos podataka
    std::cout << "\n";
    std::cout << "Unesite maticni broj: "; std::cin >> novi_unos->maticni; std::cin.ignore();
    std::cout << "Unesite ime i prezime: "; std::cin.getline(novi_unos->ime_prezime, 35);
    std::cout << "Unesite godinu upisa: "; std::cin >> novi_unos->godina;
    std::cout << "\n";
}

void ispis(lista *glava){
    lista *tekuci = glava->sljedeci; //inicijalizacija pokazivaca na prvu podatkovnu stavku (to je stavka nakon glave -- glava->sljedeci)
    int suma_maticni;
    while(tekuci != nullptr){ //vrti loop i ispisuj dok ne dodes do nullptr (zadnje stavke)
        std::cout << "\n---Element liste---\n";
        std::cout << "Maticni broj: " << tekuci->maticni << "\n"; suma_maticni += tekuci->maticni;
        std::cout << "Ime i prezime: " << tekuci->ime_prezime << "\n";
        std::cout << "Godina upisa: " << tekuci->godina << "\n";
        std::cout << "Vrijednost pokazivaca: " << tekuci->sljedeci << "\n\n";
        tekuci = tekuci->sljedeci;
    }
    std::cout << "Suma svih maticnih brojeva: " << suma_maticni << "\n";
}

void pretrazivanje(lista *glava){
    lista *tekuci = glava->sljedeci; //inicijalizacija prve podatkovne stavke
    int trazena_sifra;
    bool pronaden = false; //bool var nam treba da odredimo ako je doslo do pronalaska stavke ili ne (see line 56)
    std::cout << "Unesite maticni broj koji trazite: "; std::cin >> trazena_sifra;
    while (tekuci != nullptr){ //iteriraj kroz vezanu listu
        if (tekuci->maticni == trazena_sifra){ //ako pronademo ispisi
            pronaden = true;
            std::cout << "\n---Pronaden element---\n";
            std::cout << "Maticni broj: " << tekuci->maticni << "\n";
            std::cout << "Ime i prezime: " << tekuci->ime_prezime << "\n"; 
            std::cout << "Godina upisa: " << tekuci->godina << "\n\n";
        }
        tekuci = tekuci->sljedeci; //odi na sljedecu stavku (ovo spada pod while loop)
    }
    if (!pronaden) std::cout << "\nElement nije pronaden\n\n"; //ja sam line 56
}

void brisanje(lista *glava){
    lista *prethodni, *tekuci; //deklariraj tekuci (prva podatkovna stavka) i prethodni (stavka prije tekuceg)
    tekuci = glava->sljedeci; //prva podatkovna stavka
    prethodni = glava; //(stok i vjeverica) stavka iza tekuceg
    int trazena_sifra;
    bool izbrisano = false; //bool var nam treba da provjerimo ak smo izbrisali (see line 76)
    std::cout << "Unesite maticni broj stavke koju zelite izbrisati: "; std::cin >> trazena_sifra;
    while(tekuci != nullptr){ //iteriraj kroz listu
        if (tekuci->maticni == trazena_sifra){ 
            izbrisano = true;
            prethodni->sljedeci = tekuci->sljedeci; //postavi prethodni->sljedeci(tekuci) kao tekuci->sljedeci(onaj nakon tekuceg)
            delete tekuci; //boom tekuci
            std::cout << "\nElement izbrisan\n\n"; break;
        }
        //ako nije pronadena stavka, idi na sljedecu 
        prethodni = tekuci; 
        tekuci = tekuci->sljedeci; 
    }
    if (!izbrisano) std::cout << "\nElement nije pronaden\n\n"; //ja sam line 76
}

int main(){
    lista *glava = new lista;
    glava->sljedeci = nullptr;

    int izbor;

    do{
        std::cout << "Izbornik:\n";
        std::cout << " 1. Unos\n";
        std::cout << " 2. Ispis\n";
        std::cout << " 3. Pretrazivanje\n";
        std::cout << " 4. Brisanje\n";
        std::cout << " 9. Izlaz iz programa\n";
        std::cout << "Odabir: "; std::cin >> izbor;

        switch(izbor){
            case 1: unos(glava); break;
            case 2: ispis(glava); break;
            case 3: pretrazivanje(glava); break;
            case 4: brisanje(glava); break;
            case 9: std::cout << "Izlazim iz programa...\n"; break;
            default: std::cout << "Pogresan unos...\n"; break;
        }
    }while(izbor != 9);
}