#include<iostream>

int main(){
    struct node{
        int sifraStudenta;
        int ocjenaProg;
        char imeStudenta[50];
        node *next;
    };
    node *head = nullptr; //inicijalizacija glava lista, lista je prazna pa je nullptr

    int izbor{};
    do{
        std::cout << "1 - UNOS\n2 - ISPIS\n9 - IZLAZ\nUNOS: ";
        std::cin >> izbor;

        if (izbor == 1){
            node *new_element = new node; //inicijalizacija novog elementa liste

            std::cout << "Unesite sifru studenta: ";
            std::cin >> (*new_element).sifraStudenta;

            std::cout << "Unesite ocjenu iz programiranja: ";
            std::cin >> (*new_element).ocjenaProg;

            std::cin.ignore();
            std::cout << "Unesite ime studenta: ";
            std::cin.getline((*new_element).imeStudenta, 50);

            (*new_element).next = nullptr; //posto je novi element zadnji, njegov next je nullptr

            //ako lista nije prazna moramo iterirati kroz nju da nademo zadnji node
            if (head == nullptr){ 
                head = new_element; //ako je ovo prvi element, head postaje novi element
            }
            else{
                node *temp = head; //ako lista nije prazna, stvaramo temp pointer koji je head i njime iteriramo kroz listu
                while((*temp).next != nullptr){ //provjerava ako je trenutni node zadnji
                    temp = temp->next; //ako nije ide na sljedeci
                }
                (*temp).next = new_element; //kada nade zadnji node, tj nullptr postavlja ga kao novi element
            }
        }

        if (izbor == 2){
            node *temp = head;
            while (temp != nullptr){ //iterira kroz vezanu listu
                std::cout << "Ime studenta: " << (*temp).imeStudenta << "\n";
                std::cout << "Sifra studenta: " << (*temp).sifraStudenta << "\n";
                std::cout << "Ocjena studenta: " << (*temp).ocjenaProg << "\n";
                std::cout << "\n";
                temp = temp->next; //ide na slj node kad je ispisao sve iz trenutacnog
            }
        }
    }while (izbor != 9);

    while (head != nullptr){ //loop koji brise alociranu memoriju
        node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}