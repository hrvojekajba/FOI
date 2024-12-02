#include<iostream>

int main(){
    int *pokInt = new int;

    while(true){
        std::cout << "Unesite troznamenkasti cijeli broj: ";
        std::cin >> *pokInt;

        int brZnamenki = 0;
        int *pokPom = new int;
        *pokPom = *pokInt;

        while (*pokPom){
            *pokPom /= 10;
            brZnamenki++;
        }

        if (brZnamenki == 3){
            break;
        }
    }

    int znamenka3 = *pokInt % 10;
    int znamenka2 = ((*pokInt % 100) - znamenka3) / 10;
    int znamenka1 = *pokInt / 100;

    std::cout << znamenka1 << "+" << znamenka2 << "+" << znamenka3 << "=" <<
    znamenka1+znamenka2+znamenka3 << "\n";

    return 0;
}

