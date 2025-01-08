#include<iostream>

unsigned int rezultati[50];

unsigned int fibo(unsigned int N){
    if(N == 0 || N == 1) return 1;
    if(rezultati[N] > 0) return rezultati[N];
    rezultati[N] = fibo(N-1) + fibo(N-2);
    return rezultati[N];
}

int main(){
    std::cout << fibo(10) << "\n";
    std::cout << fibo(15) << "\n";

    return 0;
}