---
geometry: "margin=2.5cm"
mainfont: Atkinson Hyperlegible Next
monofont: CaskaydiaCove Nerd Font
---

# Mreže računala - LAB5 izvještaj

Hrvoje Kajba - IPS-G2

---

## A. Analiza IP protokola

### A1

**Koja je IP adresa računala na kojem radite?**

IP adresa računala na kojem radim je `192.168.8.1`.

### A2

**Koja je vrijednost protokola višeg sloja zapisana u zaglavlju IP datagrama?**

Zapisan je UDP: `Protocol: UDP (17)`.

### A3

**Koliko bajtova zauzima zaglavlje promatranog IP datagrama? Odredite koliko bajtova su veliki podaci koji se prenose kao teret (payload) unutar IP datagrama. Objasnite kako ste odredili veličinu podataka koji se prenose.**

Zaglavlje zauzima 20 bajtova: `Header Length: 20 bytes (5)`. Velična payloada je 300 bajtova, to sam odredio tako da sam oduzeo veličinu zaglavlja od `Total Length: 320`.

### A4

**Je li taj datagram fragmentiran? Objasnite kako ste to odredili.**

Nije fragmentiran, zadan je flag: `Flags: 0x2, Don't fragment`.

### A5

**Vrijednosti kojih polja se uvijek mijenjaju u jednoj seriji ICMP poruka koje šaljete sa svog računala?**

Polja koja se uvijek mijenjaju su: `Total Length`, `Identification` i `Header Checksum`.

### A6

**Vrijednosti kojih polja ostaju konstantna? Koja polja uvije moraju biti konstantna? Koja polja se mogu mijenjati? Zašto?**

Polja koja ostaju konstantna `Source Address`, `Destination Address`, `Time to Live`, `Protocol` i `Differentiated Services Field`. Mjenjaju se `Total Length`, `Identification` i `Header Checksum` jer se svakim sljedećim paketom na njih nadodaje.

### A7

**Opišite kakav je uzorak vrijednosti u polju „Indentification“**

U polju `Identification` se nalazi heksadecimalni identifikator tog paketa.

### A8

**Koja je vrijednost „indentication“ i „TTL“ polja?**

Vrijednost polja `Identification` raste svakim uzastopnim paketom, a vrijednost `TTL` polja se ne mjenja.

### A9

**Jesu li te vrijednosti nepromijenjena za sve ICMP „TTL-exceeded“ odgovore koje vam je poslao najbliži usmjernik? Zašto?**

Ne. Zato što su TTL-exceeded ICMP paketi oni koji nisu bili ispravno poslani.

### A10

**Jesu li te poruke poslane u IP datagramima koji su fragmentirani?**

Da.

### A11

**Odaberite prvi fragment jednog datagrama i zabilježite o kojem se datagramu radi. Na temelju čega znate da se radi o fragmentiranom IP datagramu? Kako znate da se radi o prvom, a ne nekom drugom fragmentu koji slijedi iza prvog fragmenta? Koliko je velik taj IP datagram?**

Odabrao sam paket s ID-jem 48711. Znamo da je paket fragmentiran jer je postavljena zastavica `More fragments`. Znamo da je prvi fragment pošto je `Fragment offset: 0`. Totalna veličina paketa je 2000 bajtova.

### A12

**Odaberite drugi fragment. Ima li iza njega još fragmenata? Kako to znate?**

Nema više fragmenata iza njega pošto nije zadan flag `More fragments`.

### A13

**Koja se polja razlikuju u zaglavlju IP datagrama prvog i drugog fragmenta?**

Razlikuju se `Total length`, `Flags` i `Fragment offset`.

### A14

**Koliko je fragmenata nastalo iz originalnog datagrama?**

Nastalo je šest fragmenata.

### A15

**Koja se polja razlikuju u zaglavljima IP datagrama različitih fragmenata?**

Razlikuju se `Total length`, `Fragment offset` i `Flags`.
