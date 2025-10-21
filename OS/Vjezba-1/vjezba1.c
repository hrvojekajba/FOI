#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define N 8

int prioritet_prekida[N];

void vrijeme_ulaska() {
  time_t vrijeme;
  time(&vrijeme);
  printf("\n\nPrekidna rutina pozvana u %s\n", ctime(&vrijeme));
}

int odredi_razinu_prekida() {
  int i;
  printf("Razina prekida (0-8): ");
  scanf("%d", &i);
  return i;
}

void obrada_prekida() {
  for (int i = 7; i > 0; i--) {
    if (prioritet_prekida[i] == 1) {
      for (int j = 5; j > 0; j--) {
        printf("Rutina prekida razine %d: %d/5\n", i, j);
        sleep(1);
      }
      prioritet_prekida[i] = 0;
    }
  }
}

void prekidna_rutina(int sig) {
  vrijeme_ulaska();
  int i = odredi_razinu_prekida();
  prioritet_prekida[i] = 1;
  obrada_prekida();
}

int main() {
  // koristen sigaction jer sigset dela funny -- fml
  struct sigaction sigac = {};
  sigac.sa_handler = prekidna_rutina;
  sigaction(SIGINT, &sigac, NULL);

  printf("Poceo osnovni program\n");

  for (int i = 10; i > 0; i--) {
    printf("Glavni program: %d/10\n", i);
    sleep(1);
  }

  printf("Zavrsio osnovni program\n");

  return 0;
}
