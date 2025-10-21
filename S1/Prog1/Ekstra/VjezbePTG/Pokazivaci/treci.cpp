#include <iostream>

int main(){
    int N;

    std::cout << "Unesite duljinu polja: ";
    std::cin >> N;

    char *polje = new char[N];

    for (int i = 0; i < N; i++){
        if (i < N/2){
            *(polje + i) = char(97 + rand() % 26);
        }
        else{
            *(polje + i) = char(65 + rand() % 26);
        }
    }

    for (int i = 0; i < N; i++){
        std::cout << *(polje+i);
    }
    std::cout << "\n";

    return 0;
}