//TODO: nadodaj ostale funkcije

#include <iostream>

struct tstudent {
    int mat_br;
    char prez_ime[50];
    int god_stu;
    tstudent *sljedeci;
};

void sortiraj(tstudent *lista){
    tstudent *prethodni, *tekuci, *iduci;
    int indikator;
    do{
        indikator = 0;
        tekuci = lista->sljedeci;
        prethodni = lista;
        while(tekuci->sljedeci){
            iduci = tekuci->sljedeci;
            if (tekuci->mat_br > iduci->mat_br){
                prethodni->sljedeci = iduci;
                tekuci->sljedeci = iduci->sljedeci;
                iduci->sljedeci = tekuci;
                indikator = 1;
            }
            prethodni = prethodni->sljedeci;
            tekuci = prethodni->sljedeci;
        }
    }while(indikator == 1);
}

int main(){
    tstudent *lista = new tstudent;
}