#include <iostream>
using namespace std;

struct element{
	int maticni_broj;
	char ime_prez[50];
	int godina;
	element *sljedeci = nullptr;
};

void unos(element *glava){
	element *zadnji;
	zadnji = glava;
	
	while (zadnji->sljedeci != nullptr) zadnji = zadnji->sljedeci;
	
	element *novi = new element;
	zadnji->sljedeci = novi;
	novi->sljedeci = nullptr;
	
	cout << "\nUnesite maticni broj studenta: "; cin >> novi->maticni_broj; cin.ignore();
	cout << "Unesite ime i prezime studenta: "; cin.getline(novi->ime_prez, 50);
	cout << "Unesite godinu upisa studenta: "; cin >> novi->godina;
	cout << "\n";
}

void ispis(element *glava){
	element *tekuci = glava->sljedeci;
	int suma_maticnog = 0;
	
	if (glava->sljedeci == nullptr) cout << "\nNe mogu ispisati, vezana lista je prazna\n\n";
	else{
		while(tekuci != nullptr){
			cout << "\n--Element--\n";
			cout << "Maticni broj studenta: " << tekuci->maticni_broj << "\n"; suma_maticnog += tekuci->maticni_broj;
			cout << "Ime i prezime studenta: " << tekuci->ime_prez << "\n";
			cout << "Godina upisa: " << tekuci->godina << "\n";
			cout << "Vrijednost pokazivaca na sljedeci element: " << tekuci->sljedeci << "\n";
			cout << "-----------\n";
			cout << "\n";
			tekuci = tekuci->sljedeci;
		}
		cout << "----------------------\n";
		cout << "Suma maticnih brojeva: " << suma_maticnog << "\n";
		cout << "----------------------\n\n";
	}
}

void pretrazivanje(element *glava){
	element *tekuci = glava->sljedeci;
	bool pronadeno = false;
	int trazeni_maticni;
	cout << "\nUnesite maticni broj studenta kojeg trazite: "; cin >> trazeni_maticni;
	
	while(tekuci != nullptr){
		if (tekuci->maticni_broj == trazeni_maticni){
			pronadeno = true;
			cout << "\n--Pronaden element--\n";
			cout << "Maticni broj studenta: " << tekuci->maticni_broj << "\n";
			cout << "Ime i prezime studenta: " << tekuci->ime_prez << "\n";
			cout << "Godina upisa: " << tekuci->godina << "\n";
			cout << "--------------------\n\n";
		}
		tekuci = tekuci->sljedeci;
	}
	if (!pronadeno) cout << "\nNije pronadena stavka s tim maticnim brojem\n\n";
}

void izbrisi(element *glava){
	element *prethodni = glava;
	element *tekuci = glava->sljedeci; 
	int trazeni_maticni;
	bool izbrisano = false;
	
	cout << "\nUnesite maticni broj studenta ciju stavku zelite izbrisati: "; cin >> trazeni_maticni;
	
	while (tekuci != nullptr) {
		if (tekuci->maticni_broj == trazeni_maticni){
			izbrisano = true;
			prethodni->sljedeci = tekuci->sljedeci;
			delete tekuci; break;
		}
		prethodni = tekuci;
		tekuci = tekuci->sljedeci;
	}
	if (izbrisano) cout << "\nStavka izbrisana\n\n";
	else cout << "\nNije pronadena stavka s tim maticnim brojem\n\n"; 
}

int main(){
	element *glava = new element;
	int izbor;
	do{
		cout << "Izbornik:\n";
		cout << "  1. Unos novog elementa vezane liste\n";
		cout << "  2. Ispis sadrzaja vezane liste\n";
		cout << "  3. Pretrazivanje vezane liste\n";
		cout << "  4. Brisanje elementa vezane liste\n";
		cout << "  9. Izlaz iz programa\n";
		cout << "Izbor: "; cin >> izbor;
		
		switch (izbor){
			case 1: unos(glava); break;
			case 2: ispis(glava); break;
			case 3: pretrazivanje(glava); break;
			case 4: izbrisi(glava); break;
			case 9: break;
			default: std::cout << "\nPogresan unos\n"; break;
		}
	}while(izbor != 9);

	return 0;
}
