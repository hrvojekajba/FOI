#include<iostream>

int main(){
    char polje[12];
    
    for (int i = 0; i < 12; i++){
        polje[i] = 97 + (rand() % 26);
        std::cout << polje[i] << " ";
    }
    std::cout << "\n";

    bool zamjena = true;
    for (int i = 12-1; zamjena && i > 0; i--){
        zamjena = false;
        for(int j = 0; j < i; j++){
            int k = j+1;
            if (polje[j] > polje[k]){
                std::swap(polje[j], polje[k]);
                zamjena = true;
            }
        }
    }

    for (int i = 0; i < 12; i++){
        std::cout << polje[i] << " ";
    }
    std::cout << "\n";

    return 0;
}