/*Ulaz: decimalni brojevi A, B, C
Izlaz: Korijeni jednadžbe Ax^2+Bx+C */
#include <iostream>
#include <cmath>

int main(){
    int A,B,C;
    double D;

    std::cout << "Unesi A: ";
    std::cin >> A;
    std::cout << "Unesi B: ";
    std::cin >> B;
    std::cout << "Unesi C: ";
    std::cin >> C;

    if (A == 0){
        if (B != 0){
            std::cout << "X = " << (double)C/B*-1 << "\n";
        }
        else{
            if (C == 0){
                std::cout << "Bilo koji x\n";
            }
            else{
                std::cout << "Nema rjesenja\n";
            }
        } 
    }
    else{
        D = std::pow(B,2)-4*A*C;
        if (D >= 0){
            std::cout << "x1 = " << -B + std::sqrt(D) << "\n";
            std::cout << "x2 = " << -B - std::sqrt(D) << "\n";
        }
        else{
            std::cout << "x1 = " << -B/(2*A) << " + " << std::sqrt(-D)/(2*A) << "*i\n";
            std::cout << "x2 = " << -B/(2*A) << " - " << std::sqrt(-D)/(2*A) << "*i\n";
        }
    }
    return 0;
}
