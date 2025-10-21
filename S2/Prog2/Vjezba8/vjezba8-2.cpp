#include<iostream>
#include<cmath>
using namespace std;

class ctrokut{
    private:
        float s;
    public:
        int sifra_trokuta;
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
        void unos_atributa(){
            cout << "\nUnesite sifru trokuta: "; cin >> sifra_trokuta;
            cout << "Unesite stranicu A: "; cin >> a;
            cout << "Unesite stranicu B: "; cin >> b;
            cout << "Unesite stranicu C: "; cin >> c;
        }
        void ispis_atributa(){
            cout << "\nSifra trokuta: " << sifra_trokuta << endl;
            cout << "Stranica A: " << a << endl;
            cout << "Stranica B: " << b << endl;
            cout << "Stranica C: " << c << endl;
        }
};

void prvi(ctrokut *&trokut){
    if(!trokut){
        cout << "\nObjekt nije alociran - alociram ga\n";
        trokut = new ctrokut;
        trokut->unos_atributa();
    }else{
        cout << "\nObjekt je alociran - ne alociram ga\n";
        trokut->unos_atributa();
    }
}

void drugi(ctrokut *trokut){
    if(trokut){
        cout << "\nTrokut: ";
        trokut->ispis_atributa();
        float povrsina = trokut->povrsina_trokuta();
        if(povrsina == -1){
            cout << "\nStranice ne cine trokut -- ne ispisujem povrsinu\n";
        }else{
            cout << "\nPovrsina trokuta iznosi: " << povrsina << "\n";
        }
    }else{
        cout << "\nObjekt nije alociran -- ne mogu ispisati\n";
    }
}

void treci(ctrokut *&polje_trokuta, int &broj_trokuta){
    if(!polje_trokuta){
        cout << "\nPolje trokuta nije inicijalizirano - koliko veliko da bude: "; cin >> broj_trokuta;
        polje_trokuta = new ctrokut[broj_trokuta];
    }else{
        cout << "\nPolje trokuta je inicijalizirano -- ne inicijaliziram ponovno\n";
    }
    for(int i = 0; i < broj_trokuta; i++){
            cout << "\nTrokut " << i+1;
            polje_trokuta[i].unos_atributa();
    }
}

void cetvrti(ctrokut *polje_trokuta, int broj_trokuta){
    if(!polje_trokuta){
        cout << "\nNe mogu ispisati -- polje nije inicijalizirano\n\n";
    }else{
        for(int i = 0; i < broj_trokuta; i++){
            cout << "\nTrokut " << i+1;
            polje_trokuta[i].ispis_atributa();
            float povrsina = polje_trokuta[i].povrsina_trokuta();
            if(povrsina == -1){
                cout << "Stranice ne cine trokut -- ne mogu izracunati povrsinu\n";
            }else{
                cout << "\nPovrsina trokuta iznosi: " << povrsina << endl;
            }
        }
    }
}

int main(){
    int izbor = 0, broj_trokuta = 0;
    ctrokut *jedan_trokut = NULL;
    ctrokut *polje_trokuta = NULL;

    do{
        cout << "\n---Izbornik---\n";
        cout << "   1. Dinamicka alokacija objekta i unos podataka\n";
        cout << "   2. Ispis podataka o unesenom trokutu\n";
        cout << "   3. Dinamicka alokacija polja trokuta i unos podataka\n";
        cout << "   4. Ispis podataka unesenih trokuta\n";
        cout << "   9. Izlaz\n";
        cout << "Izbor: "; cin >> izbor;

        switch(izbor){
            case 1:
                prvi(jedan_trokut);
                break;
            case 2:
                drugi(jedan_trokut);
                break;
            case 3:
                treci(polje_trokuta, broj_trokuta);
                break;
            case 4:
                cetvrti(polje_trokuta, broj_trokuta);
                break;
            case 9:
                break;
            default:
                cout << "\nPogresan unos!\n\n"; break;
        }
    }while(izbor != 9);
}