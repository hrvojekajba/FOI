---
geometry: "margin=2.5cm"
mainfont: Atkinson Hyperlegible Next
monofont: CaskaydiaCove Nerd Font
---

# Mreže računala - LAB3 izvještaj

Hrvoje Kajba - IPS-G2

---

## A. Osnovna HTTP interakcija: GET upit i odgovor

### A1

**Koristi li vaš preglednik HTTP verziju 1.0 ili 1.1? Koju verziju HTTP-a koristi poslužitelj?**

Moj preglednik koristi HTTP verziju 1.1, poslužitelj također koristi HTTP verziju 1.1.

### A2

**Koje jezike (ako ijedan) vaš preglednik može prihvatiti od poslužitelja?**

Moj preglednik može prihvatiti samo engleski, u paketu snimljenom pomoću _Wiresharka_ je navedeno: `Accept-Language: en-US, en;`.

### A3

**Koja je IP adresa Vašeg računala? Koja je adresa gaia.cs.umass.edu poslužitelja?**

IP adresa mog računala je: `192.168.8.146`, a IP adresa poslužitelja je: `128.199.245.12`.

### A4

**Koji se statusni kod vraća pregledniku od poslužitelja?**

Preglednik je pri uspješnom povratku GET odgovora vratio `200 OK`.

### A5

**Kada je HTML datoteka koju dohvaćate zadnji put mijenjana na poslužitelju?**

Zadnji puta je modificirana 28. listopada 2025. U paketu snimljenom na _Wiresharku_ piše sljedeće: `Last-Modified: Tue, 28 Oct 2025 05:59:01 GMT`.

### A6

**Koliko bajta sadržaja se vraća vašem pregledniku?**

Vraća se 128 bajta sadržaja: `File Data: 128 bytes`.

---

## B. HTTP uvjetni GET i poruka odgovora

### B1

**Analizirajte sadržaj prve HTTP GET poruke od preglednika prema poslužitelju. Vidite li “IF-MODIFIED-SINCE” redak u HTTP GET?**

Ne.

### B2

**Analizirajte sadržaj odgovora od poslužitelja. Je li poslužitelj eksplicitno vratio sadržaj datoteke? Kako to možete odrediti?**

Je, to možemo vidjeti po `Line-based text data: text/html (10 lines)` u paketu.

### B3

**Analizirajte sadržaj druge HTTP GET poruke od preglednika prema poslužitelju. Vidite li “IF-MODIFIED-SINCE” redak u HTTP GET? Ako da, koje informacije slijede iza “IF-MODIFIED-SINCE” zaglavlja?**

Da, vidim `If-Modified-Since`. Nakon `If-Modified-Since` slijedi datum i vrijeme: `If-Modified-Since: Tue, 28 Oct 2025 05:59:01 GMT`.

### B4

**Koji se HTTP statusni kodovi i izrazi vraćaju od poslužitelja kao odgovor na drugi HTTP GET? Je li poslužitelj eksplicitno vratio sadržaj datoteke? Objasnite.**

U odgovoru se vraća statusni kod `304 Not Modified`. Poslužitelj ovaj puta nije eksplictino vratio sadržaj datoteke. Do ovoga dolazi do toga da korisnik nije apsolutno ništa promjenio u svojoj GET poruci, pa je poslužitelj odličio poslati manji odgovor u kojem samo servira stranicu koja je već spremljena kod korisnika, umjesto da ponovno šalje cijelu `.html` datoteku.

---

## C. Dohvaćanje većih dokumenata

### C1

**Koliko HTTP GET zahtjeva je uputio vaš preglednik?**

Prema poslužitelju je uputio dva GET zahtjeva, jedan za `.html` datoteku na stranici i jednu za iconu stranice.

### C2

**Koliko je HTTP odgovora povezanih s prethodnim HTTP GET upitom pristiglo?**

Pristigla su dva GET odgovora, jedan za svaki upit.

### C3

**Koji je statusni kôd i izraz/fraza u pristiglom odgovoru?**

Statusni kod i fraza su `200 OK`.

### C4

**Koliko je TCP segmenata koji sadrže podatke bilo potrebno da bi se prenijela jedna HTTP poruka odgovora?**

Bilo je potrebno 628 bajta TCP segmenta da bi se prijenela HTTP poruka odgovora.

---

## D. HTML dokumenti s ugrađenim objektima

### D1

**Koliko HTTP GET zahtjeva je poslao preglednik? Na koje adrese su poslani GET zahtjevi?**

Poslana su četiri HTTP GET zahtjeva. Jedan za `.html` dokument, jedan za ikonu web stranice, te dva za slike koje su referencirane u `.html` dokumentu. Prvi zahtjev (`.html` dokument) je poslan na `128.119.245.12`, drugi (ikona web stranice) na `128.119.245.12`, treći (gornja slika) na `128.119.245.12` i četvrti (donja slika) na `2.56.99.24`.

### D2

**Možete li odrediti je li preglednik dohvatio slike serijski (jednu nakon druge) ili ih je dohvatio s oba sjedišta paralelno? Objasnite.**

Možemo odrediti prema vremenu kada je paket snimljen u _Wiresharku_, prvo je poslan zahtjev za gornju sliku, a onda za donju.

---

## E. Provjera vjerodostojnosti

### E1

**Koji je bio odgovor poslužitelja (statusni kod ili izraz) na inicijalnu naredbu GET?**

Odgovor je bio `401 Unauthorized`.

### E2

**Kad preglednik pošalje HTTP GET poruku drugi put, koje novo polje je uključeno u poruku?**

Novo polje koje je uključeno je `Authorization: Basic ...`.

### E3

**Na koji način bi napadač mogao saznati tuđe korisničko ime i lozinku i iskoristiti ih za neovlašten pristup zaštićenom web mjestu?**

Napadač bi mogao snimate pakete na nekoj mreži, te ako se koristi neenkriptirani HTTP jednostavno može izvuči korisniče podatke na drugoj GET poruci od korisnika prema poslužitelju.

---

## F. POST metoda

### F1

**Pronađite poruku koja koristi POST metodu? Tko je poslao tu poruku klijent ili poslužitelj?**

Poruku je poslao klijent.

### F2

**Koja polja se nalaze u zaglavlju poruke s POST metodom, a niste ih uočili kod poruka s GET metodom? Koju vrijednost ima polje Content – Length i što ono označava?**

`Content-Length` i `Content-Type`, oboje se javljaju jer mi kao klijent šaljemo poslužitelju datoteku, a ne on nama. Polje `Content-Length` označava veličinu datoteke koju šaljemo poslužitelju.

### F3

**Što se nalazi iza zaglavlja snimljene poruke (koja je koristila POST metodu)?**

`MIME Multipart Media Encapsulation`.

### F4

**Pronađite HTTP poruku odgovora koja je poslana kao reakcija na poruku s POST metodom. Tko je poslao odgovor klijent ili poslužitelj? Koji je statusni kod odgovora?**

Poruku odgovora je poslao poslužitelj, statusni kod odgovora je `200 OK`.

### F5

**Što se nalazi u snimljenoj poruci odgovora (iza zaglavlja)? Što je napravio vaš web preglednik nakon što je dobio ovu poruku?**

Iza zaglavlja se nalazi cijeli `.html` dokument koji poslužitelj šalje skupa sa odgovorom prema klijentu. Nakon primljenog odgovora moj preglednik je otvorio taj `.html` dokument.
