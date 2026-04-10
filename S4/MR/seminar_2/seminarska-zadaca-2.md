# Druga seminarska zadaća iz Mreža računala - DNS
## Hrvoje Kajba - IPS2-S-G13

---

### Pitanje 1.

**Pitanje:**
Pomoću nslookup saznajte IP adresu (verzije 4) web poslužitelja Nanyang tehnološkog sveučilišta iz Singapura. Naziv tog web-poslužitelja je www.ntu.edu.sg.

**Odgovor:**
`nslookup` za www.ntu.edu.sg vraća 192.168.8.1 kao IP računala na toj adresi. IP poslužitelja je 104.16.4.14.

![nslookup za www.ntu.edu.sg](./slike/nslookup-ntu-edu-sg.png)

---

### Pitanje 2.

**Pitanje:**
Pomoću nslookup odredite naziv autoritativnog poslužitelja DNS-a za domenu uu.se koja pripada Sveučilištu Uppsala iz Švedske.

**Odgovor:**
`nslookup` za uu.se kao autoritativne poslužitelje DNS-a vraća:

![uu.se nslookup](./slike/nslookup-uuse.png)

---

### Pitanje 3.

**Pitanje:**
Pokrenite nslookup naredbu kojom ćete saznati naziv poslužitelja e-pošte Indijskog instituta za tehnologiju iz Mumbaija, ako je primjer jedne e-mail adrese dean.ap@iitb.ac.in, ali tako da upit ne šaljete svom lokalnom DNS poslužitelju nego poslužitelju 8.8.8.8

**Odgovor:**
`nslookup` nije mogao pronaći poslužitelja za DNS

![nslookup indijski mail](./slike/nslookup-indija-mail.png)

---

### Pitanje 4.

**Pitanje:**
Pronađite poruke upita i odgovora DNS-a (eng. DNS query; DNS response). Šalju li se preko protokola UDP ili TCP?

**Odgovor:**
Poruke upita i odgovora DNS-a se šalju preko TCP.

---

### Pitanje 5.

**Pitanje:**
Koji je odredišni port poruke upita DNS-a? Koji je izvorišni port poruke odgovora DNS-a?

**Odgovor:**
Odredišni port poruke upita DNS-a je 53, a izvornišni port poruke odgovora DNS-a je također 53.

---

### Pitanje 6.

**Pitanje:**
Na koju adresu IP je poslana poruka upita DNS-a? Pomoću ipconfig odredite adresu IP vašeg lokalnog poslužitelja DNS-a. Jesu li te dvije adrese IP jednake?

**Odgovor:**
Poruka upita DNS-a je poslana na IP adresu 192.168.8.1, IP adresa lokalnog poslužitelja DNS je također 192.168.8.1.

![Korisnikov DNS](./slike/userdns.png)
![Wireshark slika poruke upita DNS-a](./slike/wireshark-dns-upit.png)

---

### Pitanje 7.

**Pitanje:**
Analizirajte poruku upita DNS-a. Koji je „tip“ (eng. „type”) upita DNS-a? Sadrži li poruka upita bilo kakav „odgovor“?

**Odgovor:**
Tip poruke upita DNS-a je HTTPS, poruka ne sadrži bilo kakav odgovor.

![DNS tip](./slike/wireshark-dns-tip.png)

---

### Pitanje 8.

**Pitanje:**
Analizirajte poruku odgovora DNS-a. Koliko „odgovora“ je navedeno? Što svaki od tih odgovora sadrži?

**Odgovor:**
Poruka odgovora DNS-a sadrži jedan odgovor. Odgovor sadrži ime odgovora, njegov tip, klasu, TTL i duljinu poruke.

![DNS odgovor](./slike/wireshark-dns-odgovor.png)

---

### Pitanje 9.

**Pitanje:**
Pogledajte paket TCP SYN koje je poslalo vaše računalo i koje se treba nalaziti neposredno iza odgovora DNS-a. (Napomena. Ako ste za vrijeme snimanja mrežnog prometa imali neke aplikacije aktivne, moguće je da se između nalaze i neki drugi paketi, koji nisu vezani za ovu vježbu!) Odgovara li IP adresa paketa TCP SYN nekoj od IP adresa koje ste dobili u odgovoru DNS-a?

**Odgovor:**
Pri pregledu vidljivo je da je IP adresa ishodišta TCP SYN paketa jednaka IP adresi odredišta poruke odogovora DNS-a.

![TCP SYN paket](./slike/wireshark-tcp-syn.png)

---

### Pitanje 10.

**Pitanje:**
Ova web stranica sadrži slike. Šalje li vaše računalo nove upite DNS-u prije dohvaćanja svake slike

**Odgovor:**
Računalo ne šalje poseban DNS upit za svaku sliku, već dohvaća sve slike odjednom.

---

### Pitanje 11.

**Pitanje:**


**Odgovor:**


---

### Pitanje 13.

**Pitanje:**


**Odgovor:**


---

### Pitanje 14.

**Pitanje:**


**Odgovor:**


---

### Pitanje 15.

**Pitanje:**


**Odgovor:**


---

### Pitanje 16.

**Pitanje:**


**Odgovor:**


---

### Pitanje 17.

**Pitanje:**


**Odgovor:**


---

### Pitanje 18.

**Pitanje:**


**Odgovor:**


---

### Pitanje 19.

**Pitanje:**


**Odgovor:**


---

### Pitanje 20.

**Pitanje:**


**Odgovor:**


---

### Pitanje 21.

**Pitanje:**


**Odgovor:**


---

### Pitanje 22.

**Pitanje:**


**Odgovor:**


---

### Pitanje 23.

**Pitanje:**


**Odgovor:**


---

### Pitanje 24.

**Pitanje:**


**Odgovor:**


---
