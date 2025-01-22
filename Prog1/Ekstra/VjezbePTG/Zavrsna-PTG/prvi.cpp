#include<iostream>

int main(){
    int unos, zbroj_parnih{}, zbroj_neparnih{};
    while(true){
        std::cout << "Unesite cijelobrojnu vrijednost: ";
        std::cin >> unos;

        if (unos == 0){
            break;
        }
        else if (unos % 2 == 0){
            zbroj_parnih += unos;
        }
        else{
            zbroj_neparnih += unos;
        }
    }
    std::cout << "Zbroj parnih brojeva: " << zbroj_parnih << std::endl;
    std::cout << "Zbroj neparnih brojeva: " << zbroj_neparnih << std::endl;

    return 0;
}