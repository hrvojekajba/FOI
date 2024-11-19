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

    for (int i = 1; i < N; i++){
        int j = i - 1;
        int pom = A[i];
        while ((j >= 0) && (A[j] > pom)){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = pom;
    }

    for (int i = 0; i < N; i++){
        std::cout << A[i] << " ";
    }
    
    std::cout << "\n";
    return 0;
}