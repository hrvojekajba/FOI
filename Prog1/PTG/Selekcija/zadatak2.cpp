#include <iostream>

using namespace std;

int main(){
    int ocjena;
    cin >> ocjena;

    switch (ocjena){
        case 1: cout << "nedovoljan\n"; break;
        case 2: cout << "dovoljan\n"; break;
        case 3: cout << "dobar\n"; break;
        case 4: cout << "vrlo dobar\n"; break;
        case 5: cout << "izvrstan\n"; break;
        default: cout << "Krivo unesena ocjena\n";
    }

    system("pause");
    return 0;
}