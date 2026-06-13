---
geometry: "margin=2.5cm"
mainfont: Atkinson Hyperlegible Next
monofont: JetBrainsMono NF Medium
---

# Mreže računala - LAB4 Izvještaj

Hrvoje Kajba - IPS-G2

---

## A. Prvi pogled na uhvaćene pakete

### A1

**Koja je IP adresa i broj TCP porta koje koristi klijentsko računalo (source) koje je poslalo datoteku na gaia.cs.umass.edu? Da bi odgovorili na ovo pitanje, najlakši način je da označite HTTP poruku i istražite detalje TCP paketa korištenih za prijenos te poruke.**

Klijentsko računalo koristi IP adresu `192.168.1.102`, TCP port je `1161`.

### A2

**Koja je IP adresa računala gaia.cs.umass.edu (u slučaju da ste iza proxy poslužitelja, koja je adresa proxy poslužitelja na koji ste spojeni)? Na koji port se primaju i šalju TCP segmenti za ovu vezu?**

IP adresa poslužitelja je `128.119.245.12`, TCP porta je `80`.

### A3

**Koja je IP adresa i broj TCP porta koje koristi vaše računalo da bi poslalo datoteku na gaia.cs.umass.edu?**

Moje računalo koristi IP adresu `192.168.8.146` i TCP port `34270`.

---

## B. TCP osnove

### B1

**Koji je redni broj (sequence number) TCP SYN segmenta koji se koristi za iniciranje uspostave TCP-veze između klijentskog računala i gaia.cs.umass.edu? Što je to u tom segmentu što ga identificira kao SYN segment?**

Redni broj TCP SYN segmenta je 0 ako se misli na relativni ili 1988242361 ako se misli na raw. Kao SYN segment ga identificira flag koji se postavlja da bi se označilo da je SYN segment: `Flags: 0x002 (SYN)`.

### B2

**Koji je redni broj (sequence number) SYNACK segmenta koji je poslan od gaia.cs.umass.edu kao odgovor na SYN? Koja je vrijednost «ACKnowledgement» polja u SYNACK segmentu? Kako je gaia.cs.umass.edu odredilo tu vrijednost? Što je to u tom segmentu što ga identificira kao SYNACK segment?**

Redni broj tog segmenta je također 0. Vrijednost polja `ACKnowledgement number` je 1. To je broj koji je poslužitelj odredio kako bi ACK segment znao odrediti svoj broj segmenta. Kao SYNACK segment ga identificira flag koji se postavlja da bi se tako označio: `Flags: 0x012 (SYN, ACK)`.

### B3

**Koji je redni broj (sequence number) TCP segmenta koji sadrži HTTP POST naredbu? Napomena: da bi pronašli POST naredbu bit će potrebno pretražiti sadržaj paketa «packet content field» koji se nalazi na dnu Whireshark prozora, tražeći segment koji sadrži «POST» unutar DATA polja.**

Redni broj TCP segmenta koji sadrži HTTP POST naredbu je 152497.

### B4

**Smatrajte TCP-segment koji sadrži HTTP-ovu poruku POST prvim segmentom TCP-veze. Koje su vrijednosti rednih brojeva (sequence numbers) prvih 6 segmenata TCP-veze (uključujući segment koji sadrži HTTP POST)? U kojem je trenutku pojedini segment poslan? Kada je potvrđen primitak (s ACK) za svaki primljeni segment? Uzimajući u obzir kada je pojedini segment poslan i kada je primljena potvrda njegovog primitka, koji je RTT za svaki od 6 segmenata? Koja je procjena vrijednosti RTT-a (EstimatedRTT) nakon primitka svake ACK-potvrde?**

Redni broj narednih šest TCP segmenta nakon HTTP POST poruke su svi 1. Svi segmenti su poslani jedan nakon drugoga. Prosječni RTT za tih 6 paketa je oko 53ms.

### B5

**Kolika je veličina svakog od prvih 6 segmenata?**

Veličina svih šest segmenata je 32 bajta.

### B6

**Koja je minimalna veličina raspoloživog prostora u međuspremniku koju oglašava primatelj tijekom cijele Wiresharkove snimke?**

4022.

### B7

**Ima li TCP segmenata koji su ponovo preneseni? Što ste morali provjeriti da bi mogli odgovoriti na ovo pitanje? Je li u nekom trenutku nedostatak slobodnog prostora u međuspremniku usporavao slanje na strani pošiljatelja?**

Da, postoje dva segmenta koji su bili ponovno preneseni. Da bi ovo provjerio sam filtrirao rezultate u _Wiresharku_.

### B8

**Koliko podataka primatelj tipično potvrđuje u s ACK-om? Možete li pronaći slučajeve kada primatelj potvrđuje svaki drugi primljeni segment (pogledajte tablicu 3.2 na str. 247 u knjizi).**

Primatelj s ACK-om tipično potvrđuje svaki drugi segment.

### B9

**Kolika je propusnost za ovu TCP-vezu? Objasnite kako ste izračunali tu propusnost.**

Propusnost se može izračunati tako da podjelimo veličinu skaliranja prozora s RTT-om. Ovdje to je 32/53, pa je propusnost ~0.6.
