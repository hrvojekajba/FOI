//CETVRTI

#include<iostream>

void potprogram(int int_polje[], char char_polje[], int velicina_polja){
    for(int i = 0; i < velicina_polja; i++){
        if (char_polje[i] == '+'){
            int_polje[i] += 1;
        }else if (char_polje[i] == '-'){
            int_polje[i] -= 1;
        }
    }
}

int main(){
    int N;
    std::cout << "Unesite velicinu polja: ";
    std::cin >> N;

    int* char_polje = new int[N];
    int* int_polje = new int[N];

    for(int i = 0; i < N; i++){
        char_polje[N] = rand();
    }
}