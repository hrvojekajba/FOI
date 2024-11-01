#include<iostream>
#include<string>

using namespace std;

int main(){
    int N, a, b;
    string baza_4;

    cout << "Unesite pozitivni cijeli broj: ";
    cin >> N;

    for (int I = N; N > 0; --I){
        b = N % 2; //Druga znamenka
        N /= 2;
        
        a = N % 2; //Prva znamenka
        N /= 2;

        if (a == 0 && b == 0){
            baza_4 += '0';
        }
        if (a == 0 && b == 1){
            baza_4 += '1';
        }
        if (a == 1 && b == 0){
            baza_4 += '2';
        }
        if (a == 1 && b == 1){
            baza_4 += '3';
        }
    }

    for (int i = baza_4.length() - 1; i >= 0; --i){
        cout << baza_4[i];
    }
    cout << endl;
    system("break");
    return 0;
}