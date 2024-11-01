#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    int suma = 0;

    if (a < b || a < c){
        suma += a;
    }
    if ( b < a || b < c){
        suma += b;
    }
    if (c < a || c < b){
        suma += c;
    }

    cout << suma << endl;

    system("pause");
    return 0;
}