#include <iostream>
#include <string>

struct Node{
    int sifra;
    char ime_prezime[25];
    char naziv_rada[50];
    Node *next = nullptr;
};

void unos(Node *head){
    Node *nov_unos, *zadnji; //inicijalizacija nove stavke vezane liste, zadnji je pomocna var
    zadnji = head; //alokacija zadnji na glavu vezane liste

    while (zadnji->next != nullptr) zadnji = zadnji->next; //iteriraj kroz vez. listu dok ne dodes do kraja

    nov_unos = new Node; //alociraj memorijski prostor za nov_unos
    zadnji->next = nov_unos; //postavi pokazivac na "zadnji" prema nov_unos
    nov_unos->next = nullptr; //postavi nov_unos next na nullptr -- nov_unos postaje zadnja stavka

    std::cout << "Unesite sifru: "; std::cin >> nov_unos->sifra; std::cin.ignore();
    std::cout << "Unesite ime i prezime autora: "; std::cin.getline(nov_unos->ime_prezime, 25);
    std::cout << "Unesite naziv rada: "; std::cin.getline(nov_unos->naziv_rada, 50); 
    std::cout << std::endl;
    //unosi u nov_unos
}

void ispis(Node *head){
    Node *tekuci = head->next; //prvi podatkovni element liste
    while (tekuci != nullptr){ //iteriraj kroz sve elemente liste sve dok ne dodes to zadnjega
        std::cout << "--Element liste--\n";
        std::cout << "Sifra: " << tekuci->sifra << std::endl;
        std::cout << "Ime i prezime autora: " << tekuci->ime_prezime << std::endl;
        std::cout << "Naziv rada: " << tekuci->naziv_rada << std::endl << std::endl;
        tekuci = tekuci->next; //odi na sljedeci element liste nakon ispisa
    }
}

void trazi(Node *head){
    int trazena_sifra; 
    std::cout << "Unesite sifru stavke koju trazite: "; std::cin >> trazena_sifra; //trazimo unos sifre po kojoj trazimo
    Node *tekuci = head->next; //prvi podatkovni element liste
    while (tekuci != nullptr){ //iteracija kroz vezanu listu
        if (tekuci->sifra == trazena_sifra){ //trazi ako je sifra trenutne stavke ista sifri koju smo unjeli
            std::cout << "Sifra: " << tekuci->sifra << std::endl;
            std::cout << "Ime i prezime autora: " << tekuci->ime_prezime << std::endl;
            std::cout << "Naziv rada: " << tekuci->naziv_rada << std::endl << std::endl;
        }
        tekuci = tekuci->next; //ide na sljedecu stavku ako nije pronadeno
    }
}

void izbrisi(Node *head){
    int trazena_sifra;
    std::cout << "Unesite sifru stavke koju zelite izbrisati: "; std::cin >> trazena_sifra; //unos sifre ciju stavku treba izbrisati
    Node *tekuci = head->next; //prvi podatkovni element liste
    Node *prethodni = head; //element iza tekuceg
    while (tekuci != nullptr){ //iteriramo kroz vezanu listu
        if (tekuci->sifra == trazena_sifra){ 
            prethodni->next = tekuci->next; //postavljamo prethodnu stavku kao sljedecu
            delete tekuci; break; //brisemo trenutnu stavku
        }
        prethodni = tekuci; //ako ne pronademo stavku nastavimo iterirati
        tekuci = tekuci->next;
    }
}

int main(){
    Node *head = new Node;
    head->next = nullptr;
    int izbor = 0;
    do {
        std::cout << "Izbornik:\n";
        std::cout << "  1. Unos novog elementa vezane liste\n";
        std::cout << "  2. Ispis sadrzaja vezane liste\n";
        std::cout << "  3. Pretrazivanje vezane liste\n";
        std::cout << "  4. Brisanje elementa liste\n";
        std::cout << "  9. Izlaz iz programa\n";
        std::cout << "Izbor: "; std::cin >> izbor;
        std::cout << std::endl;

        switch (izbor){
            case 1: unos(head); break;
            case 2: ispis(head); break;
            case 3: trazi(head); break;
            case 4: izbrisi(head); break;
            case 9: break;
            default: std::cout << "Pogresan unos!\n";
        }
    } while (izbor != 9);
}