#include<iostream>

int main(){
    int intPolje[5];
    char charPolje[5];

    for (int i = 0; i < 5; i++){
        intPolje[i] = 2 + rand() % 7;

        if ((rand() % 2) == 0){
            charPolje[i] = '+';
        }else{
            charPolje[i] = '-';
        }
        std::cout << intPolje[i] << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < 5; i++){
        if (charPolje[i] == '+'){
            intPolje[i] += 1;
        }
        else{
            intPolje[i] -= 1;
        }
        std::cout << intPolje[i] << " ";
    }
    return 0;
}