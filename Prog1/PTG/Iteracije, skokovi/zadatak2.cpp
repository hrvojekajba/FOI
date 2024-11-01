#include <iostream>

using namespace std;

int main(){
    int N,A;
    int sumaPos = 0, sumaNeg = 0;

    cout << "Unesite pozitivni cijeli broj: ";
    cin >> N;

    for (int I = 1; I <= N; I++){
        cout << "Unesite broj A_" << I << ": ";
        cin >> A;

        if (A > 0){
            sumaPos += A;
        }
        if (A < 0){
            sumaNeg += A;
        }
    }

    cout << sumaNeg << "\n";
    cout << sumaPos << "\n";

    system("break");
    return 0;
}