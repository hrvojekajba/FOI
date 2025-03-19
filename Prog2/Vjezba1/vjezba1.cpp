#include <iostream>
#include<cstring>
#include <string>
#include <cmath>
#include "biblioteka_vrijeme.cc"
using namespace std;

void prvi(){
	cout << "\n---1. ZADATAK---\n";
	string *polje = new string[3] {"Sijecanj", "Veljaca", "Ozujak"};
	for (int i = 0; i < 3; i++){
		cout << "polje[" << i << "]: " << polje[i] << "\n";
	}
	cout << "---KRAJ---\n\n";
}

float povrsina_kruga(float r){
	abs(r);
	return r*r*3.14;
}

void drugi(){
	float r;
	cout << "\n---2. ZADATAK---\n";
	cout << "Unesite radijus kruga: "; cin >> r;
	cout << "Povrsina kruga je: " << povrsina_kruga(r) << "\n";
	cout << "---KRAJ---\n\n";
}

void treci(){
	cout << "\n---3. ZADATAK---\n";
	
	struct struktura{
		int sifra;
		char naziv[50];
		int godina;
	};
	struktura *var1 = new struktura;
	struktura *copyvar = new struktura;
	
	char ime_hladnjaka[50] = "Hladnjak21";
	strcpy(var1->naziv, ime_hladnjaka);
	
	var1->sifra = 1582;
	var1->godina = 2018;
	
	memcpy(copyvar, var1, sizeof(struktura));
	
	cout << "Kopirani podatci:\n" << "Sifra: " << copyvar->sifra << "\nNaziv: " << copyvar->naziv << "\nGodina proizvodnje: " << copyvar->godina;
	cout << "\n---KRAJ---\n\n";
}

void cetvrti(){
	cout << "\n---4. ZADATAK---\n";
	int a,b,c;
	do {
		vrijeme_pocetak();
		cout << "Unesite A: "; cin >> a;
		cout << "Unesite B: "; cin >> b;
		cout << "Unesite C: "; cin >> c;
		vrijeme_kraj();
		cout << "Vrijeme potrebno za unos stranica: " << vrijeme_proteklo() << "\n";
	}while ((a <= 0) || (b <= 0) || (c <= 0) || (a > b+c) || (b > a+c) || (c > a+b));
	
	float s =float(a+b+c)/2;
	float P = sqrt(s*(s-a)*(s-b)*(s-c));
	cout << "Povrsina trokuta je: " << P << "\n";
	
	cout << "\n---KRAJ---\n\n";
}

int main(){
	int izbor = 0;
	
	do{
		cout << "Izbornik:\n"; 
		cout << "  1. Polje\n" << "  2. Funkcija\n" << "  3. Struktura\n" << "  4. Mjerenje vremena\n" << "  9. Izlaz iz programa\n" << "Izbor: ";
		cin >> izbor;
		
		switch (izbor) {
			case 1: prvi(); break;
			case 2: drugi(); break;
			case 3: treci(); break;
			case 4: cetvrti(); break;
		}
	}while(izbor != 9);
	
	system("PAUSE");
	return 0;
}
