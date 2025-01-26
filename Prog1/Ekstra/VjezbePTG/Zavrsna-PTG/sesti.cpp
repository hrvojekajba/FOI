#include<iostream>

int main(){
    int intPolje[30];

    for (int i = 0; i < 30; i++){
        intPolje[i] = 10 + rand() % 90;
        std::cout << intPolje[i] << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < 30; i++){
        if (i == 30) break;
        else{
            std::cout << intPolje[i] + intPolje[i+1] << " ";
        }
    }
    std::cout << "\n";
    
    return 0;
}