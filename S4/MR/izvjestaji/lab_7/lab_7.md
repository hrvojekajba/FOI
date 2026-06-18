---
geometry: "margin=2.5cm"
mainfont: Atkinson Hyperlegible Next
monofont: CaskaydiaCove Nerd Font
---

# Mreže računala - LAB7 izvještaj

Hrvoje Kajba - IPS-G2

## A. Analiza Ethernetovog okvira

### A1

**Koja je 48-bitna MAC adresa vašeg računala?**

48-bitna MAC adresa mog računala je `b6:8d:0b:df:75:96`.

### A2

**Koja je 48-bitna odredišna adresa u Ethernetovom okviru? Je li to adresa računala gaia.cs.umass.edu? (Pomoć: odgovor je ne). Kojem uređaju pripada ta Ethernet adresa?**

MAC adresa odredišta je `a2:3f:b8:22:6f:81`. Ta adresa ne pripada računalu gaia.cs.umass.edu. Ta MAC adresa pripada mojem ruteru.

### A3

**Koja je vrijednost polja «Type» u okviru (zapišite heksadekadski)? Čemu služi polje «Type» ? Kojem protokolu odgovara ta vrijednost?**

Vrijednost polja je `0x0800`. Polje služi tome da se odredi protokol preko kojeg se prenosi paket. Protokol koji je određen ovdje je IPv4.

### A4

**Nakon koliko se bajtova od početka Ethernetovog okvira pojavljuje zaglavlje protokola HTTP?**

Nakon 66 bajtova.

### A5

**Koliko bajtova u Ethernetovom okvira zauzimaju polja zaglavlje drugog sloja, a koliko bajtova podaci koje se prenose kao teret (payload) unutar odabranog okvira?**

Zaglavlje drugog sloja zauzima 14 bajtova, a 455 bajtova se prenosi kao payload.

### A6

**Koja je vrijednost CRC polja i čemu ono služi?**

Nema CRC polja.

### A7

**Koja je izvorišna adresa u Ethernetovog okviru? Je li to MAC adresa vašeg računala ili gaia.cs.umass.edu? Koji uređaj ima tu Ethernet adresu?**

Izvorišna adresa u Ethernetovom okviru je `a2:3f:b8:22:6f:81`. To nije niti adresa mog računala niti adresa gaia.cs.umass.edu. To je adresa prvog usmjernika od kojeg je došao paket.

### A8

**Koja je odredišna adresa u Ethernetovom okviru? Je li to adresa vašeg računala?**

Odredišna adresa u Ethernetovom okviru je `b6:8d:0b:df:75:96`, to je MAC adresa mojeg računala.

### A9

**Koja je vrijednost polja «Type» u okviru (zapišite heksadekadski)? Kojem protokolu odgovara ta vrijednost?**

Vrijednost polja `Type` je `0x0800` što odgovara protokolu IPv4.

### A10

**Nakon koliko se bajtova od početka Ethernetovog okvira pojavljuje zaglavlje protokola HTTP?**

Nakon 79 bajtova.

---

## B. Address Resolution Protocol

### B1

**Zapišite sadržaj ARP-cachea kojeg ste dobili. Što znače pojedini stupci u tablici?**

Ispis ARP-cachea:

```
_gateway (192.168.8.1) at a2:3f:b8:22:6f:81 [ether] on wlp98s0
Samsung (192.168.8.182) at b0:f2:f6:d8:0f:0a [ether] on wlp98s0
```

Stupci su IP adresa, MAC adresa i Type.

### B2

**Koja je vrijednosti izvorišne adrese, a koja odredišne adrese u zaglavlju Ethernetovog okvira? Koje značenje ima vrijednost adrese koju ste našli kao odredište u Ethernetovom okviru?**

Izvorišna adresa je `a2:3f:b8:22:6f:81`, a odredišna je `b6:8d:0bdf:75:96`. Odredišna adresa je adresa mog računala.

### B3

**Koja je vrijednost polja «Type» u okviru (zapišite heksadekadski)? Čemu služi polje «Type» ? Kojem protokolu odgovara ta vrijednost?**

Vrijednost polja `Type` je 0x806, što odgovara protokolu ARP. Polje služi da bi se odredio protokol više razine.

### B4

**Nakon koliko bajtova od početka Ethernetovog okvira započinje polje «opcode» u zaglavlju ARP-poruke?**

21 bajt.

### B5

**Koja je vrijednost „opcode“ polja u zaglavlju ARP zahtjeva?**

1.

### B6

**Sadrži li ARP poruka IP-adresu pošiljatelja?**

Da, sadrži polje `Sender IP address: 192.168.8.1`.

### B7

**Zašto poruka ARP upita sadrži polje „Target IP address“?**

Zato što preko toga ARP određuje čiju MAC adresu treba nabaviti.

### B8

**Koja je vrijednost polja „Target MAC address“ u zaglavlju ARP poruke zahtjeva? Sadrži li ARP poruka zahtjeva MAC adresu sučelja čiju je IP adresa navedena u polju „Target IP address“?**

Vrijednost polja `Target MAC address` je `00:00:00:00:00:00`. ARP poruka zahtjeva ne sadrži MAC adresu uređaja čija je IP adresa u `Target IP address`

### B9

**Zašto zaglavlje APR poruke sadrži polja „Hardware type“, „Protocol type“, „Hardware size“, „Protocol size“ i što ona znače?**

Zato što ARP ne radi isključuvo sa IPv4 i Ethernet protokolima, pa mora imati potrebne informacije da se može prilagoditi, nabrojana polja su one informacije koje treba da se prilagodi.

### B10

**Koja je vrijednost polja «opcode» kod ARP odgovora?**

2

### B11

**Po čemu znate (pretpostavljate) da je dobivena ARP poruka odgovor na prethodnu poruku ARP zahtjeva?**

Jer paket odgovora redoslijedno dolazi odmah nakon paketa zahtjeva, također `Sender IP address` u zahtjevu je jednak `Sender IP address` u odgovoru.

### B12

**Koje su vrijednosti izvorišne i odredišne adrese u zaglavlju Ethernetovog okvira koji prenosi ARP odgovor?**

Izvorišna adresa je `b6:8d:0b:df:75:96`, a odredišna adresa je `a2:3f:b8:22:6f:81`.

### B13

**U Wiresharku otvorite «Wireshark Trace - ethernet» datoteku. Prvi ARP paket sadrži poruku ARP zahtjeva koje je poslalo računalo na kojem je pokrenut Wireshark, a drugi paket sadrži ARP poruku odgovora koje je poslalo računalo sa traženom MAC adresom. Ali tamo je još jedno računalo na mreži, što dokazuje paket 6 – još jedan ARP zahtjev. Zašto nema ARP poruke (poslane na ARP zahtjev u paketu 6)?**

U Wireshark snimci ne mogu naći treći ARP paket.
