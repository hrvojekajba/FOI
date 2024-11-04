#include <iostream>

int main(){
    int i = 0;
    int suma = 0;
    while (i <= 100){
        if (i % 2 == 0){
            suma += i;
        }
        i++;
    }
    std::cout << suma << "\n";
    return 0;
}