#include<iostream>
#include<string>

struct lista {
    int maticni;
    char ime_prezime[35];
    int godina;
    lista *sljedeci;
};

void unos(lista *glava){
    lista *novi_unos, *zadnji;
    zadnji = glava;

    while (zadnji->sljedeci != nullptr) zadnji = zadnji->sljedeci;

    novi_unos = new lista;
    zadnji->sljedeci = novi_unos;
    novi_unos->sljedeci = nullptr;

    std::cout << "\n";
    std::cout << "Unesite maticni broj: "; std::cin >> novi_unos->maticni; std::cin.ignore();
    std::cout << "Unesite ime i prezime: "; std::cin.getline(novi_unos->ime_prezime, 35);
    std::cout << "Unesite godinu upisa: "; std::cin >> novi_unos->godina;
    std::cout << "\n";
}

void ispis(lista *glava){
    lista *tekuci = glava->sljedeci;
    while(tekuci != nullptr){
        std::cout << "\n---Element liste---\n";
        std::cout << "Maticni broj: " << tekuci->maticni << "\n";
        std::cout << "Ime i prezime: " << tekuci->ime_prezime << "\n";
        std::cout << "Godina upisa: " << tekuci->godina << "\n\n";
        tekuci = tekuci->sljedeci;
    }
}

void pretrazivanje(lista *glava){
    lista *tekuci = glava->sljedeci;
    int trazena_sifra;
    std::cout << "Unesite maticni broj koji trazite: "; std::cin >> trazena_sifra;
    while (tekuci != nullptr){
        if (tekuci->maticni == trazena_sifra){
            std::cout << "\n---Pronaden element---\n";
            std::cout << "Maticni broj: " << tekuci->maticni << "\n";
            std::cout << "Ime i prezime: " << tekuci->ime_prezime << "\n"; 
            std::cout << "Godina upisa: " << tekuci->godina << "\n\n";
        }
        tekuci = tekuci->sljedeci;
    }
}

void brisanje(lista *glava){
    lista *prethodni, *tekuci;
    tekuci = glava->sljedeci;
    prethodni = glava;
    int trazena_sifra;
    std::cout << "Unesite maticni broj stavke koju zelite izbrisati: "; std::cin >> trazena_sifra;
    while(tekuci != nullptr){
        if (tekuci->maticni == trazena_sifra){
            prethodni->sljedeci = tekuci->sljedeci;
            delete tekuci; 
            std::cout << "Element izbrisan\n"; break;
        }
        prethodni = tekuci;
        tekuci = tekuci->sljedeci;
    }
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