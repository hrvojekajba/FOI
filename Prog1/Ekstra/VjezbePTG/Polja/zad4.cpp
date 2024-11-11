#include <iostream>

int main(){
    char polje_abc[5] {'A','B','C','D','E'};

    for (int i = 0; i < 5; i++){
        std::cout << polje_abc[i];
    }
    std::cout << "\n";
    return 0;
}