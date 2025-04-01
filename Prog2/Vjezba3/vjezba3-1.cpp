#include <iostream>

// deklaracija strukture vezane liste
struct element {
    int broj;
    element *sljedeci;
    element *prethodni;
};

void dodaj_kraj(element *glava) {
    element *novi, *zadnji; // deklariramo novi (element koji se dodaje) i zadnji (element kojim dolazimo do zadnje stavke)
    zadnji = glava;         // zadnji postavljamo na glavu liste

    while (zadnji->sljedeci)
        zadnji = zadnji->sljedeci; // iteriramo dok ne dodemo do kraja liste

    novi = new element;       // inicijaliziramo novi kao prazni element
    novi->prethodni = zadnji; // novi prethodni postavljamo kao zadnji (element kojim smo iterirali)
    novi->sljedeci = nullptr; // novi sljedeci postavljamo na nullptr (posto je pravi zadnji element)
    zadnji->sljedeci = novi;  // zadnji sljedeci postavljamo na novi

    std::cout << "\nUnesite broj: ";
    std::cin >> novi->broj;
    std::cout << "\n"; // unos
}

void dodaj_pocetak(element *glava) {
    if (!glava->sljedeci) { // provjerava ako je lista prazna, ako je prazna MORAS DODATI NA KRAJ
        std::cout << "\nLista je prazna, dodajem na kraj...\n";
        dodaj_kraj(glava);
        return;
    }
    element *novi, *sljedeci; // Deklaracija novi(element koji dodajemo) i sljedeci (element koji je nakon novi)

    sljedeci = glava->sljedeci; // sljedeci inicijaliziramo kao onaj koji je odmah nakon glave
    novi = new element;         // inicijaliziramo novi kao prazni element

    novi->prethodni = glava;   // postavlajmo glavu kao element prije novi
    novi->sljedeci = sljedeci; // postavljamo sljedeci (prijasnji element nakon glave) kao sljedeci nakon novi

    glava->sljedeci = novi;     // postavljamo glava->sljedeci na novi
    sljedeci->prethodni = novi; // sljedeci->prethodni postaje novi, time je sljedeci koji je prije bio nakon glave, sada nakon novog

    std::cout << "\nUnesite broj: ";
    std::cin >> novi->broj;
    std::cout << "\n"; // unos
}

void brisanje(element *glava) {
    int unos;
    std::cout << "\nUnesite broj koji zelite izbrisati: ";
    std::cin >> unos; // pitaj za unos

    element *prethodni, *brisi; // deklaracija prethodni i brisi

    prethodni = glava;       // prethodni inicijaliziraj na glavu
    brisi = glava->sljedeci; // brisi inicijaliziraj na stavku nakon glave
    bool brisanje = false;   // deklaracija varijable kojom pratimo brisanje

    while (brisi) {
        if (brisi->broj == unos) {
            prethodni->sljedeci = brisi->sljedeci;
            brisi->sljedeci->prethodni = brisi->prethodni;
            /* jako glupo napravljeno, ali kaj se desava je to da ides u
            brisi->sljedeci->prethodni (tj ides u stavku nakon brisi (brisi->sljedeci)
            i onda ides u ->prethodni OD TE STAVKE) i onda taj pokazivac
             postavljas na istu vrijednost koju je imal brisi->prethodni*/
            delete brisi;
            brisanje = true;
            break; // FIX: Moras stavit break jer ti loop provjerava <brisi> a zbrisal si ga 2 linije gore
        }
        prethodni = prethodni->sljedeci;
        brisi = brisi->sljedeci;
    }
    if (brisanje == false) {
        std::cout << "Nije moguce izbrisati element, taj broj ne postoji u listi.\n\n";
    } else {
        std::cout << "Element izbrisan\n\n";
    }
}

void ispis(element *glava) {
    std::cout << "\n";
    element *tekuci = glava->sljedeci;
    while (tekuci) {
        std::cout << "Stavka: " << tekuci->broj << "\n";
        tekuci = tekuci->sljedeci;
    }
    std::cout << "\n";
}

int main() {
    int izbor;
    element *glava = new element;
    glava->prethodni = nullptr;
    glava->sljedeci = nullptr;

    do {
        std::cout << "Izbornik:\n";
        std::cout << "  1. Dodavanje elementa na kraj\n";
        std::cout << "  2. Dodavanje elementa na pocetak\n";
        std::cout << "  3. Brisanje elementa s liste\n";
        std::cout << "  4. Ispis elemenata\n";
        std::cout << "  9. Izlaz iz programa\n";
        std::cout << "Izbor: ";
        std::cin >> izbor;

        switch (izbor) {
        case 1:
            dodaj_kraj(glava);
            break;
        case 2:
            dodaj_pocetak(glava);
            break;
        case 3:
            brisanje(glava);
            break;
        case 4:
            ispis(glava);
            break;
        case 9:
            break;
        }
    } while (izbor != 9);
}
