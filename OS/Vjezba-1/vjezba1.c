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

void prekidna_rutina(int sig) {
  vrijeme_ulaska();

  int i;
  printf("\nRazina prekida: ");
  scanf("%d", &i);
  prioritet_prekida[i] = 1;
}

int main() {
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
