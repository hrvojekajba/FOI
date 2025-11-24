# Strukture podataka i algoritmi - Vježba 1

## 1. Algoritmi sortiranja

### 1.1. Exchange sort (sortiranje zamjenom)

Algoritam prolazi elemente od 0-tog do predzadnjeg i svaki uspoređuje s posljednjim. Ako je element veći od posljednjeg, zamjenjuje im vrijednosti. Nakon prolaska na posljednjem će se mjestu nalaziti najveća vrijednost. Nakon toga se duljina polja kroz koje se iterira smanjuje za jedna, te se ponovno iterira kroz polje.

````
void exchange_sort(int polje[], int velicina) {
  int i, j, temp;
  for (i = 0; i < size - 1; i++) {
    for (j = i + 1; j < size; j++) {
      if (num[i] == num[j]) {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
      }
    }
  }
}
````

test
