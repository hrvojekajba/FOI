---
geometry: "margin=2.5cm"
mainfont: Atkinson Hyperlegible Next
monofont: JetBrainsMono NF Medium
---

# Skripta za drugi kolokvij iz kolegija Osnove Web Tehnologija

Hrvoje Kajba

---

## JavaScript - klijent

---

### Statičke i dinamičke stranice

Sadržaj stranica može se sastavljati na dva načina: **statički** i **dinamički**.
_Statički_ način predstavlja unaprijed pripremljen i jednaki sadržaj za sve korisnike.
_Dinamički_ način predstavlja sadržaj koji se sastavlja u ovisnosti o:

- lokalno pohranjenom identifikatoru korisnika (cookies/kolačići),
- upisanim podacima formulara koji poziva zahtjevanu stranicu i
- podacima iz baze podataka.

Kada se govori o statičkim i dinamičkim stranicama, moguće ih je proučavati sa aspekta aktivnosti. Prema tome razlikujemo:

- **pasivne** (statičke) stranice - ne prati rad korisnika, većinom one stranice koje prikazuju neke informacije i ne očekuju nikakvu interakciju sa korisnikom i
- **aktivne** (dinamičke) stranice - prati rad korisnika i prema njemu može mjenjati izgled i sadržaj stranice.

Aktivnost stranice se postiže ugradnjom programksih mogućnosti na korisničkoj strani kojima se sadržaj dobiven od poslužitelja prilagođava zahtjevima korisnika i njegovom radu. Obično se radi o otvaranju i zatvaranju nekog sadržaja (npr. prilikom klikom gumba otvaramo pop-up) ili validaciji obrazaca.

---

### Skripte u HTML-u

Kako bi uključili skriptu u HTML stranicu koristi se sljedeća oznaka:

```html
<script type="application/javascript">
    document.write("Moja prva skripta!");
</script>
```

No postoji i mogućnost da preglednik ne podržava skriptiranje ili je onemogućeno izvršavanje skripata, pa se u tom slučaju koristi:

```html
<noscript>Preglednik ne podržava skripte!</noscript>
```

Program je također moguće uključiti u HTML dokument kroz vanjsku datoteku:

```html
<script type="text/javascript" src="mojaSkripta.js"></script>
```

gdje je `mojaSkripta.js`:

```js
document.write("Moja prva skripta!");
```

Kada se uključuje vanjska JavaScript datoteka, ona se često stavlja unutar `<head>` oznake, no treba i biti oprezan gdje uključujemo JavaScript, jer ako naš program ispisuje nešto to će biti ispisano tamo gdje je JavaScript program uključen u HTML datoteku.

JavaScript je skripti jezik, što znači da je _interpreterski_ jezik. Neke osobine takvih jezika su to da im je za _izvršenje potreban interpreter_ koji kod izvršuje liniju po liniju, to da imaju _slabo povezivanje podataka_ (nema tipova podataka), koriste se za _pisanje manjih programskih cijelina_ i to da postoje razne vrste skriptnih jezika (JS, Python, PHP, bash...)

---

### Objektni model dokumenta i preglednika

Ova skripta očekuje da imate osnovno znanje JavaScripta (deklaracija varijabli, grananje, iteracije i sl.) te zbog toga odmah krećemo na objektni model dokumenta (_DOM_) i preglednika.

U JavaScriptu postoje neki objekti koji se u kodu nikada zapravo ne instanciraju od korisnika, od tih objekata najbitniji su: **document** i **window** (koristi **globalThis**).

Objekt _document_ sadrži informacije o trenutno učitanom dokumentu ( u velikoj većini slučajeva HTML stranici). Kada se radi sa HTML-om, koristi se API zvan **DOM** (Document Object Model), a objekt _document_ je naš način pristupa DOM-u. Sam DOM je kreiran da se koristi s bilo kojim programskim jezikom, ali u velikoj većini slučajeva ga koristimo preko JavaScripta.

Unutar DOM-a dokumenti imaju logičku strukturu nalik stablu. Ovu strukturu možemo prikazati kroz primjer jednostavne tablice u HTML-u:

```html
<table id="korijen" style="border: 1px solid black">
    <caption>
        DOM stablo
    </caption>
    <tr id="grana-1" class="red">
        <td id="grana-1-1" class="celija">Grana 1.1.</td>
        <td id="grana-1-2" class="celija">Grana 1.2.</td>
    </tr>
    <tr id="grana-2" class="red">
        <td id="grana-2-1" class="celija">Grana 2.1.</td>
        <td id="grana-2-2" class="celija">Grana 2.2.</td>
    </tr>
    <tr id="grana-3" class="red">
        <td id="grana-3-1" class="celija">Grana 3.1.</td>
        <td id="grana-3-2" class="celija">Grana 3.2.</td>
    </tr>
</table>
```

Kao što možemo vidjeti u HTML kodu gore, korijen objekta je `<table>`, dok su `<tr>` grane tog korijena, a `<td>` grane tih grana.

Pomoću DOM-a možemo napraviti razne stvari poput:

- dohvatiti pojedini objekt na temelju nekog kriterija (_id_, _class_ i sl.),
- pogledati sve atribute objekta,
- dodijeliti vrijednost svakom atributu nekog objekta (ako se tom atributu smije mjenjati vrijednost),
- nekom objektu dodati funkciju koja će se pozivati ako se s tim objektom interaktira i
- tom objektu oduzeti funkciju, pa se ona više neće pozivati.

Dohvaćanje elementa na temelju njihovih osobina se može napraviti na više načina. Prvi od tih načina je dohvaćanje elementa po njegovoj oznaci (HTML _tag_), no ovo će najčešće vratiti polje objekta koji svi imaju tu oznaku:

```js
let tablice = document.getElementByTagName("table");
```

Drugi način dohvaćanja elementa je prema njihovom identifikatoru (HTML atribut _id_):

```js
let gumb = document.getElementById("kul-gumbic");
```

Treći način je dohvaćivanje elementa prema njegovom imenu klase (HTML atribut _class_) ili putem atributa _name_:

```js
let prviGumb = document.getElementByClassName("gumb");
let drugiGumb = document.getElementByName("gumb-ime-123");
```

Nakon što smo dohvatili objekt možemo i dohvatiti vrijednosti njegovih atributa, to možemo postići na dva načina:

```js
tablica["caption"];
```

ili

```js
tablica.caption;
```

Naravno, uz _document_ drugi važan ugrađeni object je prije spomenuti _window_ koji je sama srž **BOM**-a (Browser Object Model). BOM se ponaša slično kao i DOM, samo što sadrži bitne informacije o korisniku susava, tipu preglednika, rezoluciji ekrana, povijesti preglednika i sl. U kontekstu preglednika _window_ objekt je globalni objekt koji se dobije kada se iskoristi **globalThis**.

Objekt _window_ može se koristiti za manipulaciju trenutnim ili otvaranje novog prozora:

```js
// otvaranje novog prozora
var prozorDva = window.open(
    "prozor2.html",
    "Poruka",
    "scrollbars=no, width=300, height=240, toolbar=yes, location=yes",
);

// izmjena veličine trenutnog prozora
window.resizeTo(600, 400);
```

BOM nam omogućuje razne druge mogućnosti kao što su:

- _timer_ funkcije (funkcije koje se pozivaju nakon određenog vremena provedenog na stranici),
- _location_ ugrađeni objekt koji nam omogućuje kontrolu nad trenutnim URL-om,
- _history_ objekt koji nam omogućuje upravljanjem povijesti preglednika i
- _navigator_ objekt koji nam omogućuje dohvaćanje informacija o pregledniku.

---

### Rad s događajima

Jedan od najvažnijih dijelova DOM API-ja su događaji (_Events_). Mnogi događaji koji se izvršuju u pregledniku se izvršuju pomoću takozvanih _rukovatelja događaja_ (Event Handlers). Slučaj u kojem se rulovatelji događaja koriste skoro pa i uvijek su obrasci i njihova validacija. Različiti događaja odnose se na različite elemente (gumbove, naslove, tablice i sl.) i događaju se najčešće kada korisnik sa njima provede neku radnju (klik, hover...). Programiranjem rukovatelja događaja statičke stranice postaju dinamičke.

Programiranje rukovatelja može se ostvariti na nekoliko načina. Prvi od tih načina je korištenje `onload` rukovatelja ugrađenog u HTML:

```html
<body onload="popupPoruka()">
    <script type="text/javascript">
        function popupPoruka() {
            alert("Dobrodošli na ovu web stranicu!");
        }
    </script>
    <noscript>Izvršavanje skripte je onemogućeno!</noscript>
</body>
```

Drugi način dodavanja rukovatelja je pomoću `addEventListener` metode ugrađene u sve DOM objekte koje dohvaćujemo sa JavaScript-om:

```html
<body>
    <script type="text/javascript">
        function popupPoruka() {
            alert("Dobrodošli na ovu web stranicu!");
        }
        window.addEventListener("load", popupPoruka());
    </script>
    <noscript>Izvršavanje skripte je onemogućeno!</noscript>
</body>
```

Također se kroz JavaScript window objektu može i pridružiti anonimna funkcija (lamba funkcija). Ovo su funkcije koje nemaju identifikator i izvode se samo jednom, tj. izvode se samo na jedan događaj:

```html
<body>
    <script type="text/javascript">
        window.onload = function () {
            alert("Dobrodošli na ovu web stranicu!");
        };
    </script>
    <noscript>Izvršavanje skripte je onemogućeno!</noscript>
</body>
```

---

### Validacija podataka obrazaca

Kao što je spomenuto, unos podataka putem obrasca je jedan od najčešćih načina na koji korisnik stupa u interakciju sa web stranicom. Podaci u obrascu se često moraju provjeriti prije nego što se pošalju poslužitelju, jer poslužitelj od obrasca očekuje smislene informacije koje može na nekin način obrađivati.

```html
<!-- obrazac.html -->
<form name="obrazac" , action="validacijaForme.js" onsubmit="return provjeri(this)">
    Naziv korisnika: <input name="naziv" class="ok" size="30" maxlength="30" /><br />
    Preglednik:
    <select id="preglednik" name="preglednik" multiple="multiple" size="3">
        <option value="-1">Odaberite preglednik</option>
        <option value="0">Firefox</option>
        <option value="1">Chrome</option>
        <option value="2">Edge</option>
        <option value="3">Safari</option>
        <option value="4">Opera</option>
    </select>
    <br />
    <input type="submit" value="Pošalji" />
</form>
```

```js
// validacijaForme.js
function provjeri(forma) {
    var pogreska = false;

    if (forma.naziv.value.length <= 5) {
        alert("Niste upisali dovoljno znakova!");
        forma.naziv.className = "krivo"; // postavljamo stil unosa naziv u krivo
        forma.naziv.focus(); // fokusiramo korisnika na unos naziv
        pogreska = true;
    } else {
        forma.naziv.className = "tocno"; // postavljamo stil unosa naziv u tocno
    }

    if (forma.preglednik.value === -1) {
        alert("Niste odabrali preglednik!");
        forma.preglednik.className = "krivo"; // postavljamo stil odabira preglednik u krivo
        forma.preglednik.focus(); // fokusiramo korisnika na odabir preglednik
        pogreska = true;
    } else {
        forma.preglednik.className = "tocno";
    }

    if (pogreska) {
        return false;
    } else {
        alert("Uneseni ispravni podaci u formu!");
    }

    return true;
}
```

---

### Rad s kolačićima

Kolačići omogućuju privremeno pohranjivanje podataka o stanju rada korisnika na pojedinoj web stranici. Obično se koriste za pohranivanje podataka o korisničkom identitetu, aktivnosti, personalizaciji i sl. Kolačić se tretira kao par naziv=vrijednost:

```js
document.cookie = "{naziv}={vrijednost};expires={vrijediDo}";
```

U sljedećem primjeru kreiran je obrazac koji korisnika pita ime i koliko dugo žele da traje kolačić, nakon toga se kreira kolačić po parametrima koje je zadao korisnik:

```html
<!-- obrazac.html -->
<form name="obrazac">
    Ime i prezime: <input name="ime_prezime" /><br />
    Trajanje: <input name="trajanje" /><br />
    <input type="button" value=" Upiši " onclick="upisi_cookie();" />
</form>
```

```js
// obrada.js
function upisi_cookie() {
    let danas = new Date();
    let istice = new Date();
    let trajanje = parseInt(document.obrazac.trajanje.value);

    istice.setTime(danas.getTime() + 1000 * 60 * trajanje);

    let ime = document.obrazac.ime_prezime.value;

    document.cookie = "ime=" + ime + ";expires=" + istice.toGMTString();
}
```

---

## JavaScript - poslužitelj

NodeJS je program koji se najčešće koristi kako bi se JavaScript koristio kao jezik poslužitelja. NodeJS je otvorenog koda i može se koristiti na Linux, Windows i MacOS operativnim sustavima. Poanta NodeJS-a je to da omogućuje da se JavaScript _izvršuje izvan preglednika_.

Kao i većina programa, NodeJS programi izvršavaju se slijedno i u slučaju jednostavnijih programa završavaju nakon zadnje linije koda. Kod složenijih programa to ipak nije slučaj zato što su većinu vremena oni bazirani na događajima i asinkroni su.

---

### Rad sa datotekama

Kako bi imali stranicu koja prati rad korisnika moramo imati način na koji ćemo spremati podatke koje generira korisnik kroz svoj rad. Najjednostavniji način na koji se ovo postiže je putem rada sa datotekama. U ovom pristupu se podaci jednostavno spremaju na neku datoteku na strani poslužitelja te se, kada je potrebno, vuću van i prikazuju korisniku. Najčešći format datoteke koji se koristi pri ovakvom pristupu je `.csv` datoteka, a njom možemo pristupiti na sljedeći način:

```csv
Pero;Perić;pperic@foi.hr ​
Ivo;Ivić;iivic@foi.hr ​
Marko;Marić;mmaric@foi.hr
```

```js
// obradi.js
datotecniSustav = require("fs");
let podaci = datotecniSustav.readFileSync("korisnici.csv", "utf-8");

// ispisi ime i prezime
let linije = podaci.split("\n");
for (let linija in linije) {
    var redak = linija.split(";");
    console.log(redak[0] + " " + redak[1]);
}
```

---

### Moduli i događaji

U kontekstu NodeJS programa često se koristi pojam _modul_. Modul nije ništa drugo nego prije pripremljena klasa, skup funkcija, konstante ili sl. Kada se učita neka funkcija zapravo se instancira objekt preko kojeg se dalje rade pozivi funkcija i pristupa atributima. Tako, na primjer, `require("fs")` daje instancu objekta _fs_ s kojeg kasnije možemo koristiti kako bi pristupili njegovim metodama, npr. `readFileSync()`,

Kreiranje vlastitog modula je jednostavno, samo je potrebno koristiti ključnu riječ `exports`:

```js
module.exports = { hkajba: 12293, mkaniski: 12001 }; // module koji vraća portove vezane za pojedince
```

ili

```js
exports.portovi = { hkajba: 12293, mkaniski: 12001 };
```

Razlika je u tome da se koristeći drugi način može definirati više različitih elemenata. Tako bi mogli i definirati `exports.putanje` unutar iste `.cjs` datoteke, te onda kroz tu datoteku unijeti više elemenata:

```js
let portovi = require("./modul.js").portovi;
let korisnici = require("./modul.js").korisnici;
```

U Node programima sve funkcionira na principu događaja, slično kao što je i u pregledniku. Program započinje i kreira razne događaje koji aktiviraju neke funkcije kada se izvrše. Ti događaji se mogu aktivirati na razne događaje, jedan od njih je čak i čitanje datoteke:

```js
citac.on("line", function obradi(red) { // događaj čitanja retka
    ...
}).on("close", function ()); // događaj zatvaranja datoteke
```

---

### Funkcija operatorom strelica

Funckije kao strelice se često koriste kao zamjena za anonimne funkcije. Tako bi se na primjer koristile pri definicije rukovatelja događaka:

```js
gumb.addEventListener("click", (event) => {
    ...
})
```

Uz to, funkcija kao strelica se može i imenovati putem varijable, tj. mi varijablu definiramo kao anonimnu funkciju:

```js
const zbroj = (a, b) => {
    return a + b;
};
```

---

### Jednodretveni način rada

NodeJS radi u jednodretvenom načinu rada, te se svi događaji i funkcije izvršavaju većinski asinkrono. U jednodretvenom načinu rada se zadaci izvršavaju slijedno, a ne paralelno kao što je u višedretvenom načinu rada.

No, kako nebi došlo do ogromnog usporavanja sustava tijekom rada, NodeJS ima implementiran API koji omogućuje da se funkcije ili procesi sa dugim vremenom izvršavanja izvršuju na "drugom mjestu" na serveru.

---

### Kreiranje HTTP servera

Kako bi NodeJS program zapravo postao HTTP poslužitelj potrebno je koristiti modul _http_. Taj modul ima funkciju `createServer` koja traži kao argument funkciju koju će pozvati kada pristigne zahtjev. Funkcija mora imati dva argumenta u koje će se predati objekti koji predstavljaju HTTP zahtjev i odgovor:

```js
const http = require("http");
const hostname = "localhost";
const port = 8000;

const server = http.createServer((httpZahtjev, httpOdgovor) => {
    httpOdgovor.statusCode = 200;
    httpOdgovor.setHeader("Content-Type", "text/html");
    httpOdgovor.write("Moj NodeJS server!<br>Tražena adresa:", httpZahtjev.url);
    httpOdgovor.end();
});

server.listen(port, hostname, () => {
    console.log(`Server pokrenut na http://${hostname}:${port}/`);
});
```

Već možemo vidjeti da ovo jednostavno nije praktično za koristiti u praksi, pogotovo kada se grade velike aplikacije. Razlog ovome je to da programer mora _sve_ raditi sam, a to uključuje čitanje zahtjeva, ispis i slanje odgovora i sl. Zato se u praksi najčešće koristi jedan drugi modul nazvan `express`:

```js
const express = require("express"); // jedino ako je dodan $NODE_PATH
const server = express();
const port = 5000;

server.get("/", (zahtjev, odgovor) => {
    odgovor.send("Moj NodeJS Express server!");
});

server.listen(port, () => {
    console.log(`Server pokrenut na portu: ${port}`);
});
```

Ponekad je problem ako se u putanji lokacije NodeJS servera nalazi nešto drugo osim korijenskog direktorija, onda se mora koristiti:

```js
const express = require("express"); // jedino ako je dodan $NODE_PATH
const server = express();
const port = 5000;

server.use(express.static(__dirname));

server.get("/", (zahtjev, odgovor) => {
    odgovor.send("Moj NodeJS Express server!");
});

server.listen(port, () => {
    console.log(`Server pokrenut na portu: ${port}`);
    console.log(__dirname);
});
```

---

### Posluživanje statičnih web dokumenata

Glavni smisao servera je posluživanje nekih dokumenata, ukoliko se želi poslužiti neka statična HTML stranica to se može napraviti na dva načina:

```js
server.use("/stranica", express.static("stranica.html"));
```

ili

```js
server.get("stranica", (zahtjev, odgovor) => {
    odgovor.sendFile(__dirname + "/stranica.html");
});
```

U drugom načinu, iako je finalni rezultat isti, je moguće napraviti neke dodatne radnje (npr. spremiti podatke koje je poslao korisnik...). Ponekad se želi podjeliti cijeli direktorij sa nekom vrstom multimedija, npr. slike. To se može napraviti na sljedeći način:

```js
server.use("/slike", express.static("slike"));
```

---

### Objekt odgovora

Objekt odgovora je objekt koji omogućuje vraćanje odgovora na korisnički zahtjev. Objekt sadrži metodu `send` koja se koristila ranije da bi vratila odgovor. Metode `send` odmah šalje odgovor na klijentsku stranicu i _koristi se samo jednom_ za svaki zahtjev.

S druge strane, metoda `write` može se više puta pozvati jer ne šalje odmah odgovor, nego samo zapisuje u njega bez slanja. Da bi se poslao odgovor koji je oblikovan metodom `write` koristi se metoda `end`:

```js
server.get("/", (zahtjev, odgovor) => {
    odgovor.write("Moja prva web stranica!<br>");
    odgovor.write("Ovo je poslano pomoću metode `write`.");
    odgovor.end();
});
```

Standardno svi odgovori su statusa `200 OK`, no ako se želi koristiti neki drugi status, npr. `403` tada se može iskoristiti metoda `status`:

```js
server.get("/", (zahtjev, odgovor) => {
    odgovor.status(403);
    odgovor.write("Zabrana pristupa!");
    odgovor.end();
});
```

Preusmjeravanje na drugu stranicu moguće je izvršiti pomoću `redirect` metode:

```js
server.get("/preusmjeri", (zahtjev, odgovor) => {
    odgovor.redirect("/");
});
```

Također je moguće koristiti `type` metodu koja odredi koja vrsta odgovra se šalje natrag:

```js
serve.get("/json", (zahtjev, odgovor) => {
    var JSON = { primjer: "ovo je primjer JSON-a" };
    odgovor.type("json");
    odgovor.send(JSON);
});
```

---

### Generiranje HTML sadržaja

Kada je jasno na koji način i koje podatke želimo poslati, bolja opcija je dinamički generirati te podatke u HTML dokument, npr. dinamički generirati HTML tablicu i ispuniti ju podacima iz dokumenta. To možemo napraviti na sljedeći način:

```js
server.get8("/ispis", (zahtjev, odgovor) => {
    odgovor.send(kreirajTablicu());
})

const kreirajTablicu = () => {
    let podaci = datotecniSustav.readFileSync("korisnici.csv", "utf-8");

    let tablica = "<table border='1'>";
    tablica += "<tr>";
    ...
    tablica += "</table>"

    return tablica;
}
```

---

### Rad sa bazom podataka

Složeni projekti uglavnom imaju potrebe za velikim spremištima podataka. Kada dođe do takvih potreba, jednostavne `.csv` datoteke više nisu dosta zbog svojih ograničenja (neorganiziranost i manjak relacijskih odnosa među tablicama). Tu u igru ulaze baze podataka. Ova skripta očekuje od čitatelja da ima osnovno znanje o radu sa bazama podataka (`CREATE`, `INSERT`, `SELECT` i sl.) te neće ponoviti to gradivo.

Kako bi pristupili bazi podataka preko NodeJS servera, moramo prvo koristiti modul pravilan za našu bazu, u ovom primjeru se koristi modul `mysql2`. Nakon što imamo pravi modul možemo pristupiti našoj bazi, a to radimo na sljedeći način:

```js
let mysql = require("mysql2"); // samo ako je dodan $NODE_PATH

const server = "localhost";
const korisnik = "hkajba";
const lozinka = "superteskalozinka123";
const baza = "hkajba_baza";

var vezaDB = mysql.createConnection({
    host: server,
    user: korisnik,
    password: lozinka,
    database: baza,
});

vezaDB.connect((err) => {
    if (err) console.log("Greška:", error);
    else {
        console.log("Veza uspostavljena!");
        var sql = "SELECT * FROM KORISNICI";
        vezaDB.query(sql, (err, result) => {
            console.log(result);
            vezaDB.end();
        });
    }
});
```

Nakon ispisa podataka možete primjetiti da se pozove metoda `end`. Naime, ako se ona ne pozove veza sa bazom ostaje otvorena. Ovo može biti zgodno ako želimo napraviti više upita na bazu bez da svaki puta otvaramo novu vezu.

U ovom primjeru, ispis podataka iz base se dešava u terminalu, no ako želimo ispisati podatke na web stranicu to možemo učiniti tako da spojimo ono što smo naučili sada i malo prije:

```js
server.get("/ispis", (zahtjev, odgovor) => {
    let zaglavlje = ds.readFileSync("zaglavlje.html", "utf-8");
    let podnozje = ds.readFileSync("podnozje.html", "utf-8");

    let sql = "SELECT * FROM KORISNICI";

    let result = vezaDB.query(sql (err, result) => {
        if (err) {
            odgovor.send("Greška kod baze podataka!");
        }
        else {
            odgovor.write(zaglavlje);
            odgovor.write(kreirajTablicu(result));
            odgovor.write(podnozje);
            odgovor.end();
        }
    })
})
```

---

### Modeli autentifikacije i autorizacije

Web aplikacije često zahtjevaju provjeru identiteta svojih korisnika, a jednom identificirani korisnici imaju pristup određenim radnjama i resursima te aplikacije koji nisu dostupni korisnicima koji se nisu identificirali. Proces provjere identiteta korisnika zove se **autentifikacija**, a proces kontrole sadržaja aplikacije na temelju dodjeljenih uloga zove **autorizacija**.

Kada se govori o metodama autentifikacije najčešće se razlikuju tri vrste:

- _Nešto što znaš_ - korisnik mora nešto zapamtiti kako bi se identificirao (lozinka, PIN...),
- _Ono što imaš_ - korisnik mora nešto imati sa sobom kako bi se identificirao (npr. token) i
- _Ono što jesi_ - koriste se korisnikovi biometrijski podaci (otključavanje mobitela otiskom prsta).

---

### Izrada REST web servisa

U razvoju web aplikacija se koriste razne vrste web servisa. Web servisi su u suštini softverske komponente koje putem mrežnih protokola (primarno HTTP i HTTPS) pružaju neku uslugu (prikaz podataka, dodavanje podataka i sl.).

Osnovni standardi koje koriste REST servisi su:

- **REST** (REpresentational State Transfer),
- **JSON** (JavaScript Object Notation) i
- **WADL** (Web Application Description Language).

REST servisi su postali popularni zbog lakoće slaganja. Često vremena je dosta samo definirati URL do servisa, a sam zahtjev obraditi unutar tog URL-a. REST servisi svoje odgovore vraćaju primarno u JSON formatu, ali mogu i koristiti druge formate. Ukoliko je to potrebno, REST servisi mogu imati i definirane parametre.

Ako se REST servis drži ključnih ograničenja koja se definiranja za njega, smijemo ga zvati RESTful servis. Ta ograničenja glase:

- klijent kreira zahtjev, server vraća odgovor,
- zahtjevi se obrađuju neovisno jedan o drugome,
- REST API je ujednačen neovisno o promjenama na serveru ili klijentu,
- označava da ima više slojeva gdje svaki ima svoju zadaću i sučelje koje nudi sloju iznad,
- mogućnost cachanja čestih upita i
- _opcionalno_ je kodiranje-na-zahtjev

REST servis ima četiri glavne metode: `GET`, `POST`, `PUT` i `DELETE`. U sljedećum isječku koda je prikaz njihove implementacije, no nisu definirane funckije koje rade sa bazom podataka pošto je to sve objašnjeno u prethodnom dijelu:

```js
// GET metoda
server.get("rest/korisnici", (zahtjev, odgovor) => {
    odgovor.type("json");
    odgovor.send(dajKorisnike());
})

// POST metoda
server.post("rest/korisnici" (zahtjev, odgovor) => {
    odgovor.type("json");
    console.log(zahtjev.body);
    let korisnik = zahtjev.body;
    dodajKorisnika(korisnik);
    odgovor.send(korisnik);
})

// PUT metoda
server.put("rest/korisnici/:id", (zahtjev, odgovor) => {
    odgovor.type("json");
    let id = zahtjev.params.id;
    let korisnik = zahtjev.body;
    azurirajKorisnika(id, korisnik);
    odgovor.send(korisnik);
})

// DELETE metoda
server.delete("rest/korisnici/:id", (zahtjev, odgovor) => {
    odgovor.type("json");
    let id = zahtjev.params.id;
    let korisnik = brisiKorisnika(id);
    odgovor.send(korisnik);
})
```

---

### Sigurnost web aplikacija

Sigurnost web aplikacije je bitnija iz dana i dan, te postaje još bitnija ako web aplikacija ima veći broj korisnika ili nije napravljena samo za internu uporabu.

Jedan od najčešćih načina napada web aplikacije je **SQL ubacivanje**. To je vrsta napada u kojem haker namjerno ubaci krivi SQL upit u neki obrazac u nadi da pokvari sam upit koji se šalje našoj bazi podataka.

Još jedna bitna stvar na koju treba obratiti pažnju je način spremanja lozinka korisnika. One nikada ne smiju biti spremljene a da _nisu spremljene sa sažetom_ (**hash**-om). U NodeJS se lozinka može spremiti za sažetom koristeći `crypto` modul na sljedeći način:

```js
let vrijeme = new Date().getTime();

const kreirajSHA256() = (lozinka, sol) => {
    const hash = crypto.createHash("sha256");
    hash.write(tekst + sol);

    let izlaz = hash.digest("hex");

    hash.end();
    return izlaz;
}

kreirajHash(lozinka, vrijeme);
```

Još jedna bitna vrsta napada je **XSS** (_Cross Site Scripting_). To je vrsta napada u kojem haker kroz obrazac pokušava ubaciti HTML oznake i skripte na našu stranicu, što je, naravno, moguće zato što imamo dinamično generiranu stranicu. Najbolji način sprječavanja ovoga je filtriranja bilo kakvog unosa na web stranici (ili funkcijama ili regularnim izrazima).
