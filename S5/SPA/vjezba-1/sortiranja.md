---
geometry: "margin=2.5cm"
mainfont: Atkinson Hyperlegible Next
monofont: SFMono Nerd Font Medium
---

# Algoritmi sortiranja

- quicksort
- mergesort

## Insertion sort (sortiranje ubacivanjem)

Insertion sort koristi jedan dio polja da spremi sortirane elemente, na početku algoritma to je _prvi element polja_.

Algoritam radi na sljdeći način:

1. Uzmi prvu vrijednost iz nesortiranog dijela polja
2. Premjesti ju na točno mjesto u sortiranom dijelu polja
3. Nastavi kroz nesortirani dio onoliko puta koliko je vrijednosti u polju

```cpp
// primjer za prvu ocjensku vježbu
void insertionSort(List<int>& lista) {
    int n = lista.End(); // vraća broj elemenata
    for (int i = 0; i < n; ++i) {
        int key = lista.Retrieve(i);
        int j = i - 1;

        // prebaci elemente liste koji su veći od ključa prema naprijed
        while (j >= 0 && lista.Retrieve(j) > key) {
            lista.ChangeValue(j + 1, lista.Retrieve(j));
            j = j - 1;
        }

        lista.ChangeValue(j + 1, key);
    }
}
```

\newpage

## Bubble sort (mjehuričasto sortiranje)

Mjehuričasto sortiranje trenutnu vrijednost uspoređuje sa sljedećom, ako je trenutna veća od sljedeće, zamjeni ih i nastavi dalje.

Algoritam radi na sljedeći način:

1. Idi kroz polje jednu po jednu vrijednost
2. Za svaku vrijednost, usporedi je sa sljedećom
3. Ako je sljedeća vrijednost veća, zamjeni ih tako da veća uvijek dođe na kraj polja
4. Prođi kroz polje onoliko puta koliko je vrijednosti u polju

```cpp
// primjer za prvu ocjensku vježbu
void bubbleSort(List<int>& lista) {
    int n = lista.End(); // vraća broj elemenata liste
    bool sortirano = false;

    while (!sortirano) {
        sortirano = true;

        for (int i = 0; i < n; ++i) {
            if (lista.Retrieve(i) < lista.Retrieve(i - 1)) {
                // zamjeni elemente
                int helper = lista.Retrieve(i);
                lista.ChangeValue(i , lista.Retrieve(i - 1));
                lista.ChangeValue(i - 1, helper);

                sortirano = false;
            }
        }
    }
}
```

\newpage

## Cocktail sort (dvosmjerno mjehuričasto sortiranje)

Proces je skoro pa isti kao i mjehuričasto sortiranje, samo što se izmjenjuju iteracije od početka do kraja (najveći prema kraju) i od kraja do početka (najmanji prema početku).

Algoritam radi na sljedeći način:

1. Prva iteracija je ista kao mjehuričasto sortiranje, veće vrijednosti se guraju prema kraju
2. Sljedeća iteracija je suprotna od prve, ide se od kraja prema početku, svaki element se uspoređuje sa prijašnjim u polju, ako je manji se zamjene
3. Iteracije se izmjenjuju

```cpp
// primjer za prvu ocjensku vježbu
void dvosmjerniBubbleSort(List<int>& lista) {
    int end = lista.End();
    int start = 0;
    bool sortirano = false;

    while (!sortirano) {
        sortirano = true;

        // od početka do kraja
        for (int i = start; i < end; ++i) {
            if (lista.Retrieve(i) > lista.Retrieve(i + 1)) {
                int helper = lista.Retrieve(i);
                lista.ChangeValue(i, lista.Retrieve(i + 1));
                lista.ChangeValue(i + 1, helper);
                sortirano = false;
            }
        }

        // ako ne dođe do promjene sortirano iz true u false, polje je sortirano
        if (sortirano)
            break;

        sortirano = true;
        --end;

        // od kraja do početka
        for (int i = end; i >= start; --i) {
            if (lista.Retrieve(i) > lista.Retrieve(i + 1)) {
                int helper = lista.Retrieve(i);
                lista.ChangeValue(i, lista.Retrieve(i + 1));
                lista.ChangeValue(i + 1, helper);
                sortirano = false;
            }
        }

        ++start;
    }
}
```

\newpage

## Mergesort (sortiranje spajanjem)
