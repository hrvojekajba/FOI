#include <iostream>

using namespace std;

int main(){
    int unos, suma = 0;

    while (unos != 0){
        cout << "Unesite cijeli broj: ";
        cin >> unos;
        if (unos % 7 == 0){
            if (unos == 0){
                break;
            }
            suma += 1;
        }
    }

    cout << suma << endl;

    system("break");
    return 0;
}