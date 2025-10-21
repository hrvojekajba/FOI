#include <iostream>

int main(){
    int N, A[100];

    do{
        std::cout << "N = ";
        std::cin >> N;
    }while(N > 100);

    for (int i = 0; i < N; i++){
        std::cout << "A[i" << i << "]: ";
        std::cin >> A[i];
    }

    bool zamjena = true;
    for (int i = N-1; zamjena && i > 0; i--){
        zamjena = false;
        for (int j = 0; j < i; j++){
            int k = j + 1;
            if (A[j] > A[k]){
                int pom = A[j];
                A[j] = A[k];
                A[k] = pom;
                zamjena = true;
            }
        }
    }

    for (int i = 0; i < N; i++){
        std::cout << A[i] << " ";
    }
    
    std::cout << "\n";
    return 0;
}