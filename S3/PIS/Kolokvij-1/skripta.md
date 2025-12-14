# Projektiranje informacijskih sustava
## Kolokvij 1 - skripta

## 1. Projektiranje informacijskih sustava
### 1.1. Projektiranje inforacijskog sustava - što?
- Osmišljavanje i oblikovanje informacijskog sustava koji funkcijom, strukturom, podatkovnim sadržajem i ponašanjem odgovara potrebama organizacijskog sustava za koji se razvija i budućih korisnika.

Projektiranje informacijskog sustava se sastoji od više faza i elemenata, a to su:

- koncipiranje
- dizajn
- svrha i procesi
- građa (arhitektura) - razine - dijelovi i njihove veze (hardware, software, lifeware i orgware)
- baze podataka, dokumenti, zapisi
- nefunkcionalna svojstva, performanse
- misija, vizija, strategija, ciljevi, zahtjevi

### 1.2. Projektiranje informacijskog sustava - kako?
Postoji više načina na koji možemo projektirati informacijski sustav, a to su: 

- Korištenje odgovarajuće metodike projektiranja
- Modeliranje kao osnova projektiranja
- Inžinjerski pristup

Da bismo izgradili informacijski sustav, također trebamo razumijeti poslovni sustav koji razvijamo, istražiti ponašanje sustava u radu, poznavati procese sustava kojeg projektiramo na svim razinama, poznavati same tehnologije koje korisitmo u izradi informacijskog sustava, moći preustrojiti organizacijske sustave i odabrati optimalnu tehničku potopru za izgrađeni sustav.

No, izgradiit informacijski sustav također znači i projektirati i izvesti sve programe unutar toga IS-a, uskladiti te programe s poslovanjem, funkcionalno i ekonomski optimirati IS, uvesti taj novoizgrađeni IS i obrazovati njegove korisnike o njegovom korištenju, zaštititi taj IS tijekom njegova rada te pratiti uspješnost njegova korištenja.

### 1.3. Inženjerske discipline
Projektiranje informacijskih sustava je znanost koja je velikim dijelom preuzela svoje spoznaje iz ranijih znanstvenih područja (informacijske znanosti, računarstvo, organizacijske znanosti...), te su na temelju tih spoznaja razvijene _inženjerske discipline i informacijska struka_

Praktičnom primjenom znanstvenih spoznaja u rješavanju problema razvoja, primjene i održavanja informacijskih sustava bave se posebne **inžinjerske discipline**:

- Inženjerstvo sustava (System Engineering)
- Informacijsko inženjerstvo (Information Engineerign)
- Programsko inženjerstvo (Software Engineering)

Osnovni cilj primjene metodike inženjerskog projektiranja IS-a je određivanje funkcije, strukture i ponašanja informacijskog sustava, primjerenih ciljevima organizacije.


## 2. Odnos informacijskog sustava i organizacije
### 2.1. Sustav
**Sustav** je cjelovita tvorevina, sastavljena od skupa međusobno povezanih dijelova, koja svrhovito djeluje i u međudjelovanju je s okolinom.

Sustave možemo razvrstati prema građi, porijeklu i drugim kriterijima:

- društveni, tehnički, biološki...
- prirodni i umjetni
- složeni (sastavljeni od podsustava) ili jednostavni (dijelovi su im elementi)
- samoregulirajući ili vođeni izvana
- stalne strukture ili promjenjive strukture
- prema namjeni (organizacijski, informacijski te zdravstveni, financijski, upravni...)

### 2.2. Informacijski sustav
**Informacijski sustav** je društveno-tehnički sustav koji prikuplja, pohranjuje, čuva, obrađuje ili isporučuje informacije svojim korisnicima, koji mogu biti ljudi, organizacije ili drugi tehnički sustavi.

Informacijski sustav je složen sustav, a njegovu strukturu čine:

- Strojna oprema (hardware)
- Programska oprema (software)
- Komunikacijska i druga infrastruktura
- Podatci (dataware)
- Ljudi (lifeware)
- Društevno-tehničko ustrojstvo, tj. organizacija (orgware)

#### 2.2.1. Procesna komponenta sustava
Sustav ostvaruje svoju svrhu procesom transformacije ulaznih tokova u izlazne.

### 2.3. Kibernetički model sustava
Kibernetika je znanost o sustavima i upravljanju sustavima.

Kibernetski pogled na sustave pretpostavlja da su sustavi upravljivi. Upravljanje sustavom je njegovo održavanje u željenom stanju, ostvarivanje željenog ponašanja i funkcionalnosti.

Osnovni koncept i mehanizam održavanja sustava u željenom stanju je negativna povratvna veza. 

#### 2.3.1 Negativna povratna veza
U proces unutar sustava ulaze ulazni tokovi, te ih proces potom transformira u izlazne tokove. Jedan od tih izlaznih tokova se uzima kao mjerni član, preko kojeg se kontrolira ispravnost transformacije unutar procesa. Mjerni član se potom prosljeđuje upravljačkoj jedinici, koja s obzirom na vrijednost mjernog člana nastavlja daljnju uporabu procesa, ili ju zaustavlja.

### 2.4. Odnos organizacijskog i informacijskog sustava
S obzirom na mjesto i ulogu informacijskog sustava unutar organizacijskog, razlikuju se dva pogleda na informacijske sustave: **preslikavanje organizacije** i **upravljanje organizacijom**.

#### 2.4.1. Preslikavanje organizacije
Ovaj pogled pretpostavlja pasivnu ulogu informacijskog sustava. Informacijski sustav sadrži opise **prošlih stanja poslovnih procesa i poslovnih događaja** pohranjene u bazi podataka organizacijskog sustava.

Ovaj pogled je nastavo u vrijeme klasičnih sustava obrade podataka, namijenjenih trajnom pohranjivanju podataka o poslovanju, zatim obračunavanju, izvještavanju, kontroli i reviziji poslovanja i sl.

#### 2.4.2. Upravljanje organizacijom
Prema ovom pogledu informacijski sustav bitno utječe na strukturu, funkciju i ponašanje organizacijskog sustava.

Osim "preslikavanja organizacije", svrha informatičkog sustava je **pružanje potrebnih informacija donositeljima odluka** tijekom samih procesa donošenja odluka.

Informacijski sustav je *dio upravljačkog člana* organizacijskog sustava. Korisnici na temelju informacija donose odluke i poduzimaju aktivnosti, kojima utječu na organizacijski sustav.
