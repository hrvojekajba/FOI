#include<iostream>
#include <cmath>

using namespace std;

int main(){
    int N, A, B = 0, min = 0;
    cout << "Unesite pozitivni cijeli broj: ";
    cin >> N;

    for (int I = 1; I <= N; I++){
        cout << "Unesite broj A_" << I << ": ";
        cin >> A;
        
        if (abs(A-B) < min || min == 0){
            min = abs(A-B);
        }
        B = A;
    }

    cout << min << endl;
    system("break");
    return 0;
}