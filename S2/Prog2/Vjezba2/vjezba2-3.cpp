#include<iostream>

struct element {
    int broj_god;
    char ime_prez[35];
    element *sljedeci;
};

void unos(element *glava){
    element *zadnji, *nov_unos;
    zadnji = glava;
    while (zadnji->sljedeci != nullptr) zadnji = zadnji->sljedeci;

    nov_unos = new element;
    zadnji->sljedeci = nov_unos;

    std::cout << "\nUnesite broj godina osobe: "; std::cin >> nov_unos->broj_god; std::cin.ignore();
    std::cout << "Unesite ime i prezime osobe: "; std::cin.getline(nov_unos->ime_prez, 35); 
    nov_unos->sljedeci = nullptr;
    std::cout << "\n";
}

void ispis(element *glava){
    element *tekuci = glava->sljedeci;
    while(tekuci != nullptr){
        std::cout << "\n--Element--\n";
        std::cout << "Broj godina osobe: " << tekuci->broj_god << "\n";
        std::cout << "Ime i prezime osobe: " << tekuci->ime_prez << "\n";
        std::cout << "Vrijednost pokazivaca: " << tekuci->sljedeci << "\n";
        tekuci = tekuci->sljedeci;
    }
    std::cout << "\n";
}

void pretrazivanje(element *glava){
    element *tekuci = glava->sljedeci;
    bool pronaden = false;
    int godine;
    std::cout << "\nUnesite koliko je stara osoba koju trazite: "; std::cin >> godine;

    while(tekuci != nullptr){
        if (tekuci->broj_god == godine){
            std::cout << "\n--Pronaden--\n";
            std::cout << "Broj godina osobe: " << tekuci->broj_god << "\n";
            std::cout << "Ime i prezime osobe: " << tekuci->ime_prez << "\n\n";
            pronaden = true; 
        }
        tekuci = tekuci->sljedeci;
    }
    if (!pronaden) std::cout << "\nElement nije pronaden\n\n";
}

void brisanje(element *glava){
    element *prethodni, *tekuci;
    prethodni = glava;
    tekuci = glava->sljedeci;
    bool izbrisan = false;
    int godine;
    std::cout << "\nUnesite koliko je stara osoba koju zelite izbrisati: "; std::cin >> godine;
    while (tekuci != nullptr){
        if (tekuci->broj_god == godine){
            izbrisan = true;
            prethodni->sljedeci = tekuci->sljedeci;
            delete tekuci;
        }
        prethodni = tekuci;
        tekuci = tekuci->sljedeci;
    }
    if (izbrisan){
        std::cout << "\n--Element izbrisan--\n\n";
    }else{
        std::cout << "\n--Element nije pronaden--\n\n";
    }
}

int main(){
    element *glava = new element;
    glava->sljedeci = nullptr;
    int izbor;
    do{
        std::cout << "Izbornik:\n";
        std::cout << "  1. Unos\n";
        std::cout << "  2. Ispis\n";
        std::cout << "  3. Pretrazivanje\n";
        std::cout << "  4. Brisanje\n";
        std::cout << "  9. Izlaz iz programa\n";
        std::cout << "Izbor: "; std::cin >> izbor;

        switch (izbor){
            case 1: unos(glava); break;
            case 2: ispis(glava); break;
            case 3: pretrazivanje(glava); break;
            case 4: brisanje(glava); break;
            case 9: break;
            default: std::cout << "\nPogresan unos\n\n";
        }
    }while(izbor != 9);

    return 0;
}