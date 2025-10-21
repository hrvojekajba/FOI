#include<iostream>

int main(){
    float *prviPok = new float;
    float *drugiPok = new float;

    std::cout << "Unesite prvi decimalni broj: ";
    std::cin >> *prviPok;

    std::cout << "Unesite drugi decimalni broj: ";
    std::cin >> *drugiPok;

    float umnozak = (*prviPok) * (*drugiPok);

    std::cout << "Cijeli dio umnoska: " << int(umnozak) << "\n";
    std::cout << "Decimalni dio umnoska: " << umnozak - int(umnozak) << "\n";

    delete prviPok, drugiPok;
    return 0;
}