#include <iostream>

using namespace std;

int main(){

    int a,b,c;
    cin >> a >> b >> c;

    if (a == b || a == c || b == c){
        cout << "Da\n";
    }
    else{
        cout << "Ne\n";
    }

    system("pause");
    return 0;
}
