#include <iostream>

int main(){
    int A[100], N, K;

    std::cout << "Unesite velicinu polja: ";
    std::cin >> N;

    int i = 0;

    for (i = 0; i < N; i++){
        std::cout << "Unesite vrijednost A[" << i << "]: ";
        std::cin >> A[i]; 
    }

    std::cout << "Unesite vrijednost K: ";
    std::cin >> K;

    for (i = 0; i < N; i++){
        if (A[i] == K){
            break;
        }
    }

    if (i < N){
        std::cout << "Trazena vrijednost nalazi se na indeksu " << i << "\n";
    }
    else{
        std::cout << "Trazena vrijednost ne nalazi se u polju\n";
    }
    return 0;
}