#include<iostream>

struct stablo{
    int broj;
    stablo *lijevo;
    stablo *desno;
};

void unos(stablo *glava){
    int broj;
    std::cout << "\nUnesite broj koji zelite dodati stablu: "; std::cin >> broj;
    stablo *novi;
    stablo *zadnji = glava;
    bool dalje = true;

    do{ //loop se iterira sve dok dalje nije jednak false, tj sve dok se ne doda novi cvor
        if (broj > zadnji->broj){ //provjerava ako je unos veci od broja u trenutnom cvoru
            if (zadnji->desno != nullptr){ //provjerava ako postoji stavka na desnoj strani cvora
                zadnji = zadnji->desno; //ako ne postoji stavka, prelazimo u desnu stranu cvora
            }
            else{ //ako postoji desni podcvor
                novi = new stablo; //inicijaliziraj novu stavku
                zadnji->desno = novi; //zadaj desni podcvor od zadnji na novi
                novi->broj = broj; //zadaj unos u stavku
                //postavi i lijevo i desno na null jer je novi zadnji podcvor
                novi->lijevo = nullptr; 
                novi->desno = nullptr;
                //dalje false jer smo napravili podcvor
                dalje = false;
            }
        }
        else{ //ako je broj <= zadnji->broj
            if (zadnji->lijevo != nullptr){ //provjerava ako postoji stavka na lijevoj strani
                zadnji = zadnji->lijevo; //ako ne postoji stavka, prelazimo na lijevu stranu
            }
            else{ //dodajemo novi cvor ako ne postoji 
                novi = new stablo;
                zadnji->lijevo = novi;
                novi->broj = broj;
                novi->lijevo = nullptr;
                novi->desno = nullptr;
                dalje = false;
            }
        }
    }while(dalje);
}

void ispis_uzlazno(stablo *glava){
    static stablo *korijen = glava; //pokazivac se zbog static inicijalizira SAMO NA PRVOM POZIVU FUNKCIJE

    if (glava == nullptr) return;
    ispis_uzlazno(glava->lijevo); //rekurzivni poziv koji ide na lijevi cvor

    if (glava != korijen) std::cout << glava->broj << ", ";
    ispis_uzlazno(glava->desno); //rekurzivni poziv koji ide na desni cvor
}

int main(){
    int izbor;
    stablo *gl_stablo = new stablo;
    gl_stablo->lijevo = nullptr;
    gl_stablo->desno = nullptr;

    do{
        std::cout << "\nIzbornik: \n";
        std::cout << "  1. Unos cvora u stablo\n";
        std::cout << "  2. Ispis stabla\n";
        std::cout << "  9. Izlaz iz programa\n";
        std::cout << "Unos: "; std::cin >> izbor;

        switch(izbor){
            case 1: unos(gl_stablo); break;
            case 2: ispis_uzlazno(gl_stablo); break;
            case 9: break;
            default: std::cout << "\nPogresan unos...\n";
        }
    }while(izbor != 9);
}