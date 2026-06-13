---
geometry: "margin=2.5cm"
mainfont: Atkinson Hyperlegible Next
monofont: JetBrainsMono NF Medium
---

# Mreže računala - LAB1 izvještaj

Hrvoje Kajba - IPS-2

---

## A. Snimanje i analiza _tracerouteovih_ paketa

### A1

**Koliko je čvorova bilo na putu od računala na kojem radite do odredišta?**
Na putu od računala na kojem radim do odredišta bilo je 11 čvorova.

### A2

**Koliko je odgovora dobiveno od svakog pojedinog čvora?**
Svaki pojedini čvor je vratio tri odgovora. To možemo vidjeti po tome da je svaki čvor na putu vratio tri vremena koja prikazuju koliko vremena je bilo potrebno da paket dođe do čvora i natrag.

### A3

**Koja je IP adresa drugog čvora koji je ispisao traceroute?**
192.168.18.1

### A4

**Možete li prema IP adresi pronaći odgovor koji vam je poslao 2. čvor? Koliko je njegovih odgovora on pristiglo?**
Mogu, odgovor koji je vraćen je ICMP poruka. Poslana su tri odgovora sa te IP adrese.

### A5

**Odaberite jedan paket i odgovorite na sljedeće pitanje. Poruka ICMP-a (Internet Control Message Protocol) prenosi se kao teret (payload) nekog drugog protokola. O kojem se protokolu radi?**
Odabrao sam paket koji sam već pregledao u pitanju A4. Poruka ICMP-a se prenosi preko IPv4 protokola.

---

## B. Istraživanje topologije mreže te otkrivanje potencijalnih geostacionarnih satelitskih poveznica i prekooceanskih vodova

### B1

**Istraživanje topologije mreže**
Za istraživanje topologije mreže sam odlučio odabrati četiri računala na različitim dijelovima svijeta, jedno u Europi, jedno u Aziji, jedno u Sjevernoj Americi i jedno u Južnoj Americi.

Za Europu sam odabrao konzum.hr. Pokretanjem `traceroute` sam vidio da počinjem od IP adrese `192.168.1.1` (privatna IP adresa mog računala), te onda krećem kroz računalo IP adrese `10.80.245.242` (računalo koje se vrlo vjerojatno nalazi unutar Hrvatske ili njoj bližne zemlje zbog vremena putovanja paketa), te sam se onda prebacio kroz još par bližnjih računala dok nisam dobio finalni odgovor na `traceroute` od računala u Njemačkoj.

Za Aziju sam odabrao sony.jp. Pokretanjem `traceroute` sam vidio da počinjem od IP adrese `192.168.1.1` (privatna IP adresa mog računala), te onda krećem kroz računalo IP adrese `10.80.245.242` (isto računalo kao u slučaju sa konzum.hr), te sam se onda ponovno prebacio kroz nekoliko bližnjih računala u Europi sve dok nisam dobio finalni paket od servera u Singapuru (`sin-sa1-i.SIN.SG.NET.DTAG.DE`).

Za Sjevernu Ameriku sam odabrao amazon.com. Pokretanjem `traceroute` ponovno vidimo da je privatna IP adresa mog računala `192.168.1.1`. Ponovno prolazim kroz par računala unutar Hrvatske ili bližnjih država, sve dok nisam preusmjeren na računalo koje se vrlo vjerojatno nalazi unutar SAD-a (`was-sa3-i.WAS.US.NET.DTAG.DE`).

Za Južnu Ameriku sam odabrao amazon.com.br. U ovom izvođenju `traceroute` je situacija bila skoro pa ista kao u izvođenju za amazon.com, što vjerojatno znači da je amazon.com.br također smješten unutar Sjeverne Amerike.

### B2

**Određivanje geostacionarnih satelitskih poveznica i prekooceanskih vodova**
U svrhu pronalaženja prekooceanskih vodova sam odlučio ponovno `traceroute` pokrenuti prema amazon.com, pošto sam siguran da se poslužitelj nalazi u Sjevernoj Americi. Lako možemo primjetiti kada je paket izašao iz Europe prema Sjevernoj Americi zbog ogromnog skoka u vremenu prijenosa paketa:

```
traceroute to amazon.com (98.87.170.74), 30 hops max, 60 byte packets
 1  _gateway (192.168.1.1)  1.546 ms  2.830 ms  2.817 ms
 2  192.168.18.1 (192.168.18.1)  4.130 ms  4.451 ms  4.592 ms
 3  10.80.245.242 (10.80.245.242)  7.180 ms  7.330 ms  6.409 ms
 4  10.80.248.46 (10.80.248.46)  6.139 ms  5.867 ms  6.376 ms
 5  10.80.248.25 (10.80.248.25)  8.500 ms  8.488 ms  8.326 ms
 6  195.29.246.137 (195.29.246.137)  9.035 ms  7.356 ms  6.347 ms
 7  62.157.250.194 (62.157.250.194)  9.759 ms  9.146 ms  10.683 ms
 8  was-sa3-i.WAS.US.NET.DTAG.DE (62.154.14.74)  119.752 ms  118.395 ms  118.157 ms
 9  was-sa3-i.WAS.US.NET.DTAG.DE (62.154.14.74)  117.897 ms  117.891 ms  116.936 ms
```

Kao što možemo vidjeti, skok u vremenu je otprilike 110ms, što znači da smo vrlo vjerojatno pogodili prekooceanski vod. Najverojatnije je to jedan od mnogih vodova koji kreću na zapadu Velike Britanije i završavaju na istočnoj obali SAD-a.
