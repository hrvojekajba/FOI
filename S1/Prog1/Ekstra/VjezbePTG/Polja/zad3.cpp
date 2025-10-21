#include <iostream>
#include <vector>

int main(){
    int M, F_current;
    
    std::cout << "Unesite M: ";
    std::cin >> M;

    int F_niz[M] {1,1};

    for (int i = 0; i <= M; i++){
        if (i == 0 || i == 1){
            continue;
        }
        else{
            F_current = F_niz[i-1] + F_niz[i-2];
            F_niz[i] = F_current;
        }
    }
    for (int i = 0; i < M; i++){
        std::cout << F_niz[i] << "\n";
    }
    return 0;
}