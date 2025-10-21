#include <iostream>
#include <cmath>
#include"../biblioteka_vrijeme_linux.cc"
using namespace std;

//deklaracija klase i njezinih podfunckija po uputama
class ctrokut{
    private:
        float s;
    public:
        static int broj_unesenih;
        int sif_trokuta;
        float a, b, c;
        float povrsina_trokuta(){
            if(a+b > c && a+c > b && b+c > a){
                s = (a+b+c)/2;
                float povrsina = sqrt(s*(s-a)*(s-b)*(s-c));
                return povrsina;
            }else{
                return -1;
            }
        }
        void unos_abc(){
            cout << "\nUnesite sifru trokuta: "; cin >> sif_trokuta;
            cout << "Unesite stranicu A: "; cin >> a;
            cout << "Unesite stranicu B: "; cin >> b;
            cout << "Unesite stranicu C: "; cin >> c;
            broj_unesenih++;
        }
        void ispis_abc(){
            cout << "\nSifra trokuta: " << sif_trokuta << endl;
            cout << "Stranica A: " << a << endl;
            cout << "Stranica B: " << b << endl;
            cout << "Stranica C: " << c << endl;
        }
};

//inicijalizacija brojaca za objekt
int ctrokut::broj_unesenih = 0;

int main(){
    int izbor = 0, broj_trokuta = 0;
    //inicijalizacija praznih objekata
    ctrokut *jedan_trokut = NULL;
    ctrokut *polje_trokuta = NULL;

    do{
        cout << "\nIzbornik:\n";
        cout << "   1. Dinamicka alokacija i unos podataka o trokutu\n";
        cout << "   2. Ispis podataka o trokutu\n";
        cout << "   3. Dinamicka alokacija polja trokuta i unos podataka o pojedinom trokutu u polju\n";
        cout << "   4. Ispis podataka o unesenim trokutima\n";
        cout << "   9. Izlaz iz programa\n";
        cout << "Izbor: "; cin >> izbor;

        switch(izbor){
            case 1:
                //provjerava ako objekt postoji - ako postoji samo unos, ako ne inicijalizacija i unos
                if(!jedan_trokut){
                    cout << "\nObjekt nije alociran - alociram ga\n";
                    jedan_trokut = new ctrokut;
                    jedan_trokut->unos_abc();
                }else{
                    cout << "\nObjekt vec postoji\n";
                    jedan_trokut->unos_abc();
                }
                break;
            case 2:
                //ispisuje sadrzaj objekta po uputama u zadatku
                if(jedan_trokut){
                    jedan_trokut->ispis_abc();
                    float povrsina = jedan_trokut->povrsina_trokuta();
                    if(povrsina == -1){
                        cout << "Stranice ne tvore trokut!\n";
                    }else{
                        cout << "Povrsina trokuta: " << povrsina << "\n";
                    }
                }else{
                    cout << "\nObjekt nije alociran - alociraje objekt i unesite podatke\n";
                }
                break;
            case 3:
                //ako polje nije inicijalizirano trazi velicinu dinamickog polja
                if(!polje_trokuta){
                    cout << "\nPolje trokuta nije inicijalizirano, koliko veliko polje zelite inicijalizirati? "; cin >> broj_trokuta;
                    polje_trokuta = new ctrokut[broj_trokuta];
                    //iterira kroz polje i trazi unos
                    for(int i = 0; i < broj_trokuta; i++){
                        cout << "\nTrokut " << i << ":\n";
                        polje_trokuta[i].unos_abc();
                    }
                }else{
                    cout << "\nPolje trokuta vec postoji!\n";
                }
                break;
            case 4:
                //ako polje postoji ide s ispisom
                if(polje_trokuta){
                    for(int i = 0; i < broj_trokuta; i++){
                        cout << "\nTrokut " << i << ":\n";
                        polje_trokuta[i].ispis_abc();
                        float povrsina = polje_trokuta[i].povrsina_trokuta();
                        if(povrsina == -1){
                            cout << "Stranice ne tvore trokut\n";
                        }else{
                            cout << "Povrsina trokuta: " << povrsina << endl;
                        }
                    }
                }else{
                    cout << "\nPolje trokuta nije inicijalizirano -- inicijalizirajte ga!\n\n";
                }
                break;
            case 9:
                break;
            default:
                cout << "\nPogresan unos...\n\n";
        }
    }while(izbor != 9);
    return 0;
}