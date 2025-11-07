#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define N 8

int SLIJEDNO[N];

int OZNAKA_CEKANJA[N];
int PRIORITETI[N];
int TEKUCI_PRIORITET = 0;

void vrijeme_prekida() {
    time_t vrijeme;
    time(&vrijeme);
    printf("\n\nPrekidna rutina pozvana u: %s\n", ctime(&vrijeme));
}

void razina_prekida() {
    int razina = 0;

    do {
        printf("Razina prekida: ");
        if (scanf("%d", &razina) != 1) {
            scanf("%*[^\n]");
            razina = 0;
        }
    } while (razina > 7 || razina <= 0);
    printf("\n");

    SLIJEDNO[razina] = 1;
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
        for (int i = 0; i < N; i++) {
            if (SLIJEDNO[i] == 1)
                x = i;
        }

        if (x > 0) {
            SLIJEDNO[x] = 0;

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
