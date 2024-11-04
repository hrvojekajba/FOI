#include <iostream>

int main(){
    int unos;

    while (true){
        std::cout << "Unesite pozitivni cijeli broj";
        std::cin >> unos;

        if (unos > 0){
            break;
        }
        else{
            continue;
        }
    }
    

}