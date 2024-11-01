#include <iostream>

int main(){

    int broj_korisnik, broj_racunalo, broj_ukupan;
    int bodovi_korisnik = 0, bodovi_racunalo = 0;
    char izbor_korisnik, izbor_racunalo;

    while (true){

        if (bodovi_korisnik >= 3 || bodovi_racunalo >= 3){
            break;
        }

        broj_racunalo = rand() % 6;
        std::cout << "(P)ar ili (N)epar? ";
        std::cin >> izbor_korisnik;

        if (izbor_korisnik == 'P'){
            izbor_racunalo = 'N';
        }
        else{
            izbor_racunalo = 'P';
        }

        std::cout << "Unesite broj od 1 do 5: ";
        std::cin >> broj_korisnik;

        broj_ukupan = broj_korisnik + broj_racunalo;

        if (broj_ukupan % 2 == 0 && izbor_korisnik == 'P'){
            bodovi_korisnik++;
            std::cout << "Korisnik: " << bodovi_korisnik << "\n";
            std::cout << "Racunalo: " << bodovi_racunalo << "\n";
        }
        else if (broj_ukupan % 2 == 1 && izbor_korisnik == 'P'){
            bodovi_racunalo++;
            std::cout << "Korisnik: " << bodovi_korisnik << "\n";
            std::cout << "Racunalo: " << bodovi_racunalo << "\n";
        }
        else if (broj_ukupan % 2 == 0 && izbor_korisnik == 'N'){
            bodovi_racunalo++;
            std::cout << "Korisnik: " << bodovi_korisnik << "\n";
            std::cout << "Racunalo: " << bodovi_racunalo << "\n";
        }
        else{
            bodovi_korisnik++;
            std::cout << "Korisnik: " << bodovi_korisnik << "\n";
            std::cout << "Racunalo: " << bodovi_racunalo << "\n";
        }
    }
    
    if (bodovi_korisnik > bodovi_racunalo){
        std::cout << "-----------------------------------\n";
        std::cout << "Pobjednik je korisnik\n";
        std::cout << "Korisnik: " << bodovi_korisnik << "\n";
        std::cout << "Racunalo: " << bodovi_racunalo << "\n";
        std::cout << "-----------------------------------\n";
    }
    else{
        std::cout << "-----------------------------------\n";
        std::cout << "Pobjednik je racunalo\n";
        std::cout << "Korisnik: " << bodovi_korisnik << "\n";
        std::cout << "Racunalo: " << bodovi_racunalo << "\n";
        std::cout << "-----------------------------------\n";
    }
    return 0;
}