#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define N 8

int OZNAKA_CEKANJA[N];
int PRIORITET[N];
int TEKUCI_PRIORITET = 0;

void vrijeme_ulaska() {
    time_t vrijeme;
    time(&vrijeme);
    printf("\nPrekidna rutina pozvana u %s\n", ctime(&vrijeme));
}

void obrada_prekida(int n) {
    printf("Obradujem prekid razine %d\n", n);
    for (int i = 5; i > 0; i--) {
        printf("Prekid razine %d: %d/5\n", n, i);
        sleep(1);
    }
    printf("Zavrsio sa obradom\n\n");
}

void prekidna_rutina(int sig) {
    vrijeme_ulaska();

    int i;
    printf("Razina prekida: ");
    scanf("%d", &i);
    printf("\n");
    OZNAKA_CEKANJA[i] = 1;

    int x = 1;

    do {
        x = 0;

        // odreduje prekid najveceg prioriteta koji ceka obradu
        for (int j = TEKUCI_PRIORITET; j < N; j++) {
            if (OZNAKA_CEKANJA[j] != 0)
                x = j;
        }

        // ako postoji prekid koji ceka obradu idi u obradu
        if (x > 0) {
            printf("USAO U IF, X: %d\n", x);
            // postavlja se da je proces u obradi, tj. da je obraden
            OZNAKA_CEKANJA[x] = 0;
            // u PRIORITET[x] se postavlja prethodni tekuci proces
            PRIORITET[x] = TEKUCI_PRIORITET;
            printf("PRIORITET[x]: %d\n", PRIORITET[x]);
            // postavlja se da je x trenutni proces
            TEKUCI_PRIORITET = x;
            printf("TEKUCI_PRIORITET: %d\n", TEKUCI_PRIORITET);

            // dodaj sigint u new_list
            sigset_t sig_list = {};
            sigaddset(&sig_list, SIGINT);
            // odobri koristenje SIGINT
            sigprocmask(SIG_UNBLOCK, &sig_list, NULL);

            printf("Ulazim u obradu prekida\n");
            obrada_prekida(x);
            printf("Izlazim iz obrade prekida\n");

            // zabrani koristenje SIGINT
            sigprocmask(SIG_BLOCK, &sig_list, NULL);
            printf("sigsuspend prosao\n");

            TEKUCI_PRIORITET = PRIORITET[x];
            printf("novi TEKUCI_PRIORITET: %d\n", TEKUCI_PRIORITET);
        }
    } while (x > 0);
}

int main() {
    struct sigaction sig = {};
    sig.sa_handler = prekidna_rutina;
    sigaction(SIGINT, &sig, NULL);

    printf("Poceo osnovni program\n");

    for (int i = 10; i > 0; i--) {
        printf("Glavni program: %d/10\n", i);
        sleep(1);
    }

    printf("Zavrsio osnovni program\n");

    return 0;
}
