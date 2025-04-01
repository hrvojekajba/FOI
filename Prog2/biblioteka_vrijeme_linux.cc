#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

high_resolution_clock::time_point vrijeme1, vrijeme2;
duration<double, milli> razlika;

void vrijeme_pocetak() {
    vrijeme1 = high_resolution_clock::now();
}

void vrijeme_kraj() {
    vrijeme2 = high_resolution_clock::now();
}

double vrijeme_proteklo() {
    razlika = duration_cast<duration<double, milli>>(vrijeme2 - vrijeme1);
    return razlika.count();
}

//unos znakovnog niza
void unos(char* znakovni_niz) {
    cin.getline(znakovni_niz, 150);
    if (cin.gcount() == 1)
        cin.getline(znakovni_niz, 150);
}
