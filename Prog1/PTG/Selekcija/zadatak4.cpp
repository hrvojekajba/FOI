#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float a,b;
    cin >> a >> b;
    double D = 0;

    if (a < 0 || b < 0){
        cout << "Krivo unesene stranice\n";
    }
    else{
        D = sqrt(pow(a, 2) + pow(b,2));
        cout << D << endl;
    }
    
    system("pause");
    return 0;
}