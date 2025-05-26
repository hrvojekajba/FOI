1. Spojite se na postgres bazu i kreirajte novu ulogu koja se naziva "bp1_korisnik" s kojom korisnik ima pravo kreiranja baze podataka, kreiranja uloga i prijavu s lozinkom "korisnik1".
`CREATE ROLE bp1_korisnik WITH LOGIN PASSWORD 'korisnik1' CREATEDB CREATEROLE`
- `CREATE ROLE` - narpravi ulogu
- `WITH LOGIN PASSWORD` - da uvjet da se korisnik prijavi na ulogu s lozinikom
- `CREATEDB CREATEROLE` - da korisniku pravu kreacije uloga i baza podataka

2. U ulozi korisnika 'bp1_korisnik' kreirajte bazu podataka pod nazivom 'bp_fakultet' te se spojite na tu bazu s tom ulogom.
`SET ROLE bp1_korisnik`
`CREATE DATABASE bp_fakultet`
`\c bp_fakultet bp1_korisnik`
- `SET ROLE` - postavljamo se u ulogu bp1_korisnik
- `CREATE DATABASE bp_fakultet` - kreiramo bazu podataka kao bp1_korisnik
- `\c bp_fakultet bp1_korisnik` - na bazu se spajamo s ulogom bp1_korisnik

3.  Kreirajte dvije tablice:
Tablica kolegij: 
- **id** - cjelobrojna vrijednost koja raste automatski, primarni ključ
- **naziv** - znakovni niz do 20 znakova, vrijednost mora biti unesena i unikatna
- **studij** - znakovni niz do 20 znakova
- **godina** - cjelobrojna vrijednost, mora biti unesena i unikatna
Tablica student:
- **id** - cjelobrojna vrijednost koja raste automatski, primarni ključ
- **ime** - znakovni niz do 20 znakova, vrijednost mora biti unesena
- **prezime** - znakovni niz do 20 znakova, vrijednost mora biti unesena
- **kolegij** - vanjski ključ na tablicu kolegij, prilikom brisanja briše se i ova vrijednost
`CREATE TABLE kolegij (id SERIAL PRIMARY KEY, naziv VARCHAR(20) NOT NULL UNIQUE, studij VARCHAR(20), godina INTEGER NOT NULL UNIQUE);`
- `CREATE TABLE` - stvori tablicu kolegij
- `id SERIAL PRIMARY KEY` - postavlja id kao primarni ključ koji automatski raste(`SERIAL`)
- `naziv VARCHAR(20) NOT NULL UNIQUE` - naziv je znakovno niz koje mora biti uneseno (`NOT NULL`) i unikatno (`UNIQUE`)
- `studij VARCHAR(20)` - studij je znakovni niz
- `godina INTEGER NOT NULL UNIQUE` - godina se definira kao int, koji mora biti unesen i unikatan
`CREATE TABLE student (id SERIAL PRIMARY KEY, ime VARCHAR(20) NOT NULL, prezime VARCHAR(20) NOT NULL, kolegij INTEGER REFERENCES kolegij(id) ON DELETE CASCADE);`
- `CREATE TABLE` - stvori tablicu student
- `id SERIAL PRIMARY KEY` - postavlja id kao primarni ključ koja automatski raste
- `ime VARCHAR(20) NOT NULL` - ime je znakovni niz od 20 znakova koji se mora unesti
- `prezime VARCHAR(20) NOT NULL` - isto kao ime
- `kolegij INTEGER REFERENCES kolegij(id) on DELETE CASCADE` - kolegij je integer koji se referencira na primarni ključ iz tablice kolegij, ako se u toj tablici izbriše red, i u ovoj će se izbrisati red sa pripadajućom vrijednosti (kolegij == kolegij(id))

4. Popunite tablicu kolegij i student podacima tako da imate najmanje 3 kolegija i 3 studenta tako da jedan kolegij NEMA NITI JEDNOG STUDENTA.
`INSERT INTO kolegij(naziv, studij, godina) VALUES ('Matematika', 'IPS', '1'), ('Baze podataka', 'IPS', 2), ('SPA', 'IPS', 3);`
- `INSERT INTO kolegij` - specificiramo da unosimo u tablicu kolegij
- `(naziv, studij, godina)` - specificiramo u koje stupce unosimo
- `VALUES (...)` - vrijednosti koje unosimo u te stupce
`SELECT * FROM kolegij;`
- Ispisuje sav sadržaj iz tablice kolegij
`INSERT INTO student(ime, prezime, kolegij) VALUES ('Hrvoje', 'Kajba', 1), ('Šimun', 'Klarić', 1), ('Petar', 'Jug', 2);`
- U tablicu student unosimo ime, prezime i kolegij - **KOLEGIJ JE VANJSKI KLJUČ NA TABLICU KOLEGIJ**
- Hrvoje Kajba i Šimun Klarić se povezuju s kolegijem 1 - Matematikom, a Petar Jug se povezuje s kolegijem 2 - Bazom podataka, nitko nije povezan s kolegijem 3 - SPA

5. Promjenite tablicu kolegij tako da obrišete stupac godina.
`ALTER TABLE kolegij DROP COLUMN godina;`
- `ALTER TABLE kolegij` - označavamo da mijenjamo tablicu
- `DROP COLUMN godina` - brišemo stupac godina

6. Napišite upit koji vraća ime i prezime studenta čije ime završava na slovo 'a'.
`SELECT ime, prezime FROM student WHERE ime LIKE '%a';`
- `SELECT ime, prezime FROM student` - ispisuje ime i prezime iz tablice student ako zadovolje uvjet
- `WHERE ime LIKE '%a'` - uvjet - ako ime završava na 'a'
- % znak predstavlja više znakova, npr. 'A%' bi bilo da riječ počinje na 'A', '%a%' bi bilo da riječ samo sadrži slovo 'a'...

7. Kreirajte pogled koji vraća naziv kolegija i studija i ime i prezime studenta, za sve studente i kolegije.
`CREATE VIEW pogled1 AS SELECT k.naziv AS kolegij, k.studij, s.ime, s.prezime FROM student s JOIN kolegij k ON s.kolegij = k.id;`
- `CREATE VIEW pogled1` - kreiraj pogled1
- `AS SELECT k.naziv AS kolegij`

8. Korištenjem naredbe `SELECT INTO` kreirajte tablicu student_studij koja sadrži ime, prezime i naziv kolegija za sve studente koji su na studiju IPS.
`SELECT s.ime, s.prezime, k.naziv INTO student_studij FROM student s JOIN kolegij k ON s.kolegij = k.id WHERE k.studij = 'IPS';`
- `SELECT s.ime, s.prezime, k.naziv INTO student_studij` - definiramo koje stupce želimo staviti u novu tablicu
- `FROM student s JOIN kolegij k` - definiramo iz koje dvije tablice uzimamo stupce
- `ON s.kolegij = k.id` - definiramo da je s.kolegij vanjski ključ na k.id
- `WHERE k.studij = 'IPS'` - definiramo uvjet koji mora biti zadovoljen da bi se uzeo red

9. Korištenjem naredbe `SELECT INTO` kreirajte tablicu student_studij1 koja sadrži ime, prezime i naziv kolegija za sve studente koji su na studiju IPS - koristite operator `IN`.
`SELECT s.ime, s.prezime, k.naziv INTO student_studij1 FROM student s JOIN kolegij k ON s.kolegij = k.id WHERE k.studij IN (SELECT naziv FROM kolegij WHERE naziv = 'IPS');`
- `SELECT s.ime, s.prezime, k.naziv INTO student_studij1` - definiramo stupce koje želimo staviti u novu tablicu
- `FROM student s JOIN kolegij k` - definiramo iz koje dvije tablice želimo uzeti stupce
- `ON s.kolegij = k.id` - definiramo da je s.kolegij vanjski ključ na tablicu kolegij (k.id)
- `WHERE k.studij IN (...)` - definiramo da se uzmu redak iz tablice u kojoj je k.studij = IPS, nakon toga s kodom ispod odredimo tablicu u kojoj su samo redci koji imaju traženi naziv
- `(SELECT naziv FROM kolegij WHERE naziv = 'IPS)'` - definiramo tablicu iz koje vučemo redke

9. Kreirajte funkciju istudent koja prima 3 argumenta (ime, prezime i kolegij), te unosi te vrijednosti u tablicu student - napišite poziv te funkcije.
- **Deklaracije funkcije:**
`CREATE FUNCTION istudent (arg_ime VARCHAR, arg_prezime VARCHAR, kolegij_id INTEGER)`
`RETURNS VOID`
`AS $$ INSERT INTO student(ime, prezime, kolegij) VALUES (arg_ime, arg_prezime, kolegij_id)$$`
`LANGUAGE SQL;`
- **Poziv funkcije:**
`SELECT istudent('Hrvoje', 'Kajba', 1);`
