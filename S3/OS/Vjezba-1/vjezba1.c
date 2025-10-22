#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define N 8

int OZNAKA_CEKANJA[N];
int PRIORITETI[N];
int TEKUCI_PRIORITET = 0;

void vrijeme_prekida() {
    time_t vrijeme;
    time(&vrijeme);
    printf("\n\nPrekidna rutina pozvana u: %s\n", ctime(&vrijeme));
}

void razina_prekida() {
    int razina = 8;

    do {
        printf("Razina prekida: ");
        scanf("%d", &razina);
    } while (razina > 7 || razina < 0);
    printf("\n");

    OZNAKA_CEKANJA[razina] = 1;
}

void obrada_prekida(int n) {
    printf("Obradujem prekid razine %d\n", n);
    for (int i = 1; i <= 5; i++) {
        printf("Prekid razine %d: %d/5\n", n, i);
        sleep(1);
    }
    printf("Zavrsio s obradom prekida razine %d\n\n", n);
}

void prekidna_rutina(int sig) {
    // ispisi vrijeme pozivanja prekida
    vrijeme_prekida();

    // odredi razinu prekida
    razina_prekida();

    // helper varijabla
    int x = 1;

    do {
        x = 0;

        // provjeri ako postoji proces veceg prioriteta
        // koji je na cekanju
        for (int j = TEKUCI_PRIORITET; j < N; j++) {
            if (OZNAKA_CEKANJA[j] != 0)
                x = j;
        }

        if (x > 0) {
            OZNAKA_CEKANJA[x] = 0;
            PRIORITETI[x] = TEKUCI_PRIORITET;
            TEKUCI_PRIORITET = x;

            // odredi listu signala koje
            // treba blokirati / odblokirati
            sigset_t siglist = {};
            sigaddset(&siglist, SIGINT);

            // odblokiraj SIGINT
            sigprocmask(SIG_UNBLOCK, &siglist, NULL);

            // obradi prekid
            obrada_prekida(x);

            // blokiraj SIGINT
            sigprocmask(SIG_BLOCK, &siglist, NULL);

            TEKUCI_PRIORITET = PRIORITETI[x];
        }
    } while (x > 0);
}

int main() {
    // definiraj koja funckcija se poziva sa ctrl+c
    struct sigaction sigac = {};
    sigac.sa_handler = prekidna_rutina;
    sigaction(SIGINT, &sigac, NULL);

    // glavna rutina
    printf("\nObradujem glavnu rutinu:\n");
    for (int i = 1; i <= 10; i++) {
        printf("Glavna rutina: %d/10\n", i);
        sleep(1);
    }
    printf("Zavrsio s obradom glavne rutine.\n");

    return 0;
}
