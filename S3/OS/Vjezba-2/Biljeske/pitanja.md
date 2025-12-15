# Operacijski sustavi - Vježba 2
## Pitanja i odgovori
---
1. Napravi novi proces u kodu
Koristimo `fork()` da napravimo novi proces.

2. Napravi novu dretvu u kodu
Koristimo `pthread_create()` da napravimo novu dretvu.

3. Što je to dretva i čemu služi?
Dretva je osnovna jedinica izvođenja programa u procesu. Svaki proces može imati jednu ili više dretvi, koje mogu paralelno izvoditi program.

4. Što je to proces?
Proces je okolina u kojem se izvodi program. Sastoji se od segmenta instrukcija, segmenta korisničkih podataka i segmenta sustavskih podataka.

5. Što je zajednički spremnik i zašto je važan?
Zajednički spremnik je alocirani memorijski prostor koji više procesa može koristiti kako bi međusobno dijelili podatke.

6. Što radi `ipcs`?
Pokazuje informacije o iskorištenim sredstvima za međuprocesnu komunikaciju.

7. Čemu služi `ipcrm`?
Služi sa brisanje određenih sredstva za međuprocesnu komunikaciju.

8. Kako prokazati procese?


9. Završi proces u funkciji


10. Što to dijele dvije dretve istoga procesa?


11. Promjeni kod tako da ispis u 2.b zadatku bude sporiji


12. Gdje se poziva dretva?
13. Napiši kod tako da roditelj sačeka završetak proces djeteta
14. Kako `void` može primiti više argumenata?
15. Što je/gdje je kritični odsječak u kodu?
16. Stvori segmente dijeljene memorije veličine X bajtova
17. Do kad će dijeljena memorija biti zauzeta ako ju ne obrišemo?
18. Kako završiti tekuću dretvu?
19. Pričekaj da neko dijete završi ako postoji
20. Ispiši identifikator trenutnog procesa
21. Ispiši identifikator trenutne dretve
22. Obriši segment djeljene memorije na kraju `main()` funkcije
23. Objasni razliku između Deckerovog i Lampartovog algoritma
