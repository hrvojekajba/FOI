Program koji prihvaća prekide razvrstanih po prioritetu u svom najjednostavnijem rješenju koristi sljedeće strukture podataka:
1. **TEKUCI_PRIORITET**
2. **PRIORITETI[N]** - polje u koje se pohranjuje kontekst dretve
3. **OZNAKA_CEKANJA[N]**- polje u koje se zapisuju zastavice o tome koje razine prekida su aktivne
---
Postoje dvije verzije prekida koji mogu biti generirani:
1. Nenamjerni prekidi:
	- dijeljenje s 0
	- adresiranje nepostojeće lokacije
	- dekodiranje nepostojećeg operacijskog koda
2. Namjerni prekidi:
	- procesor ima barem jednu instrukciju koja omogućuje izazivanje prekida programa, to se naziva *programski prekid*, tj. *software interrupt*
	- **poziv jezgre**, tj. poziv **jezgrine funkcije**
---
Jezgra može procesu poslati signal, taj signal može biti proizveden od same jezgre, poslan od strane programa ili ga može poslati i korisnik.

Primjeri navedenih signala:
1. Od strane jezgre - kada program pokuša pristupiti memoriji koja nije u njegovom adresnom prostoru **(SIGSEGV)**
2. Proces sam sebi - **SIGALRM**
3. Korisnik procesu - prekidni signal, generira se unosom *CTRL+C* **(SIGINT)**

Za većinu signala sam proces može kontrolirati što se dešava nakon što ga je prihvatio (izuzetak je **SIGKILL**):
- Može prihvatiti ugrađenu akciju (u većini slučajeva ovo ubija proces)
- Može ga ignorirati
- Može uhvatiti signal i izvesti određenu funkciju koja je pridodana njemu
---
Neki od najbitnijih signala u modernoj implementaciji *UNIX-a*:
- **SIGINT** - šalje se sa *CTRL+C*, koristi se za prekid procesa
- **SIGQUIT** - šalje se sa *CTRL+backslash*, najčešće izmijenjeno na *CTRL+X*, koristi se za kraj izvršavanja programa
- **SIGKILL** - jedini sigurni način da se ubije proces, ne može biti uhvaćen niti ignoriran od strane procesa
- **SIGSEGV** - jezgra šalje procesu kad pristupi tuđoj memoriji
- **SIGALRM** - šalje se kad istekne traženo vrijeme čekanja procesora
- **SIGTERM** - standardni signal za uništavanje procesa, rabi se kod isključivanja da ubije sve aktivne procese, očekuje se da ubijeni proces spremi aktualno stanje prije završetka
- **SIGSTOP** - privremeno zaustavljanje procesa (*CTRL+Z*)
---
