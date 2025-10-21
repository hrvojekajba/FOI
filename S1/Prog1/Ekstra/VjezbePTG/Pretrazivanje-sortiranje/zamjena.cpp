#include <iostream>

int main(){
    int N, A[100];

    do{
        std::cout << "N = ";
        std::cin >> N;
    }while(N > 100);

    for (int i = 0; i < N; i++){
        std::cout << "A[" << i << "]: ";
        std::cin >> A[i];
    }

    for (int i = N-1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (A[j] > A[i]){
                int pom = A[j];
                A[j] = A[i];
                A[i] = pom;
            }
        }
    }

    for (int i = 0; i < N; i++){
        std::cout << A[i] << " ";
    }
    
    std::cout << "\n";
    return 0;
}