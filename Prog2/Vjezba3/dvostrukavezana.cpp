#include<iostream>

struct element{
    int broj;
    element *sljedeci;
    element *prethodni;
};

void unos(element *glava){
    element *novi, *zadnji;
    zadnji = glava;
    
    while (zadnji->sljedeci){
        zadnji = zadnji->sljedeci;
    }
    novi = new element;

    novi->prethodni = zadnji;
    novi->sljedeci = nullptr;
    zadnji->sljedeci = novi;

    std::cout << "Unesite broj: "; std::cin >> novi->broj;
}

int main(){
    element *glava = new element;
    glava->sljedeci = nullptr;
    glava->prethodni = nullptr;
    int izbor = 0;
    do {
        std::cout << "Izbornik:\n";
        std::cout << "  1. Unos novog elementa vezane liste\n";
        /*std::cout << "  2. Ispis sadrzaja vezane liste\n";
        std::cout << "  3. Pretrazivanje vezane liste\n";
        std::cout << "  4. Brisanje elementa liste\n";
        std::cout << "  9. Izlaz iz programa\n";*/
        std::cout << "Izbor: "; std::cin >> izbor;
        std::cout << std::endl;

        switch (izbor){
            case 1: unos(glava); break;
            case 2: /*ispis(glava);*/ break;
            case 3: /*trazi(glava);*/ break;
            case 4: /*izbrisi(glava);*/ break;
            case 9: break;
            default: std::cout << "Pogresan unos!\n";
        }
    } while (izbor != 9);
}