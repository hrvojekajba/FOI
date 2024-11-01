#include<iostream>

using namespace std;

int main(){
    int N, rezultat = 2;
    cout << "Unesite cijeli pozitivni broj: ";
    cin >> N;

    if (N < 0 || N > 31){
        cout << "Unesli ste krivi broj.\n";
    }

    for (int I = 1; I < N; I += 1){
        rezultat *= 2;
    }

    cout << rezultat - 1 << endl;

    system("break");
    return 0;
}