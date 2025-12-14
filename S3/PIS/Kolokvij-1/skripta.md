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

### 2.5. Procesni (funkcionalni) pogled na organizaciju
Procesi reprezentiraju funkcionalnost sustava, a funkcionalnost je preduvjet za ostvarivanja svrhe sustava.

#### 2.5.1. Informatički pogled na procese
Osnovne informacije o objektnom sustavu su proces i podatci. Procesi i podatci su osnovni predment interesa tijekom razvoja informacijskg sustava.

**Proces** je skup aktivnosti kojima se skup ulaznih podataka transformira u skup izlaznih podataka.

#### 2.5.2. Funkcionalni pogled na organizaciju
*Funkcionalno raščlanjivanje* je razlaganje neke funkcionalne komponente na funkcionalne komponente niže razine.

Funkcijsko područje sadrži skup logički povezanih funkcija. Funkcija reprezentira postizanje svrhe sustava. Za razliku od procesa, funkcija nema dinamiku, dok proces ima definirane događaje i uvjete kojima se on pokreće i prekida.

### 2.6. Model poslovanja, poslovnih procesa i informacijskog sustava
**Model poslovanja (Bussiness model - BM)** je skup međusobno povezanih modela koji opisuju različite aspekte poslovanja, uključujući strukturu organizacije, poslovne ciljeve i prioritete, poslovne procese i pravila, padataka i sl. Model poslovanja mora predočiti koje se vrijednosti isporučuju kupcima, kako se to čini i s kakvim (financijskim) rezultatima.

## 3. Metodologija informacijskih sustava
**Metoda** je planski postupak za postignuće nekog cilja na teoretskom ili praktičnom području.

**Metodologija** je općenito znanost o metodama i njihovoj primjeni.

**Metodologija informacijskih/programskih sustava** je znanstvena disciplina o pravilima, pristupima, prpcesima, metodama, tehnikama i sredstvima *razvoja, primjene i održavanja* informacijskih i programskih sustava.

### 3.1. Metodika
Na temelju metodoloških istraživanja i praktičnih iskustava razvijene su *metodike razvoja, primjene i održavanja informacijskih i programskih sustava*.

Metodika je uređen skup načela, pristupa, pravila, činjenica, obrazaca, metoda i tehnika rješavanja nekog zadatka. Ona je također normativni i preskriptivni obrazac za rješavanje posla te je i formalizirana apstrakcija razvojnog poduhvata.

#### 3.1.1. Struktura metodike - pristupi

**Pristup (paradigma)** je skup početnih pretpostavki o objektu projektiranja i skup općih načela, koja proizlaze iz pojedinih znanstvenih teorija ili iskustva.

Pristupi određuju svrhu, ulogu, strukturu, ponašanje, način razvoja ili korištenja informacijskog ili programskog sustava, njegov odnos s okolinom i sl.

#### 3.1.2. Struktura metodike - načela
- Kakva je *uloga znanosti i struke u projektiranju*? (inženjerske pristup)
- Kakva je *uloga informacijskog sustava*? (preslikavanje organizacije, upravljanje organizacijom)
- Kakva je *namjena sustava*? (obrada transakcija, podrška u odlučivanju, podrška uredskog rada...)
- Kakva je *usklađenost sa zahtjevima organizacije i korisnika*? (tehnički pristup, društveni pristup, tehničko-društveni pristup)
- Što je *objekt modeliranja*, postojeći sustav, ili vizija budućeg sustava?
- Kakva je *prilagodljivost stanju ili promjenama objektnog sustava*? (strukturni pristup, situacijski/adaptibilni pristup)
- Kako izgleda *razvojni ciklus*? (fazni pristup, inkrementalni pristup)
- Kakav je *odnos prema dijelovima i cjelini*? (analitički pristup, holistički pristup)
- Što je *osnovni model*? (funkcijski pristup, podatkovni pristup, objektni pristup)
...

#### 3.1.3. Struktura metodike - obrasci procesa
*Proces razvoja informacijskog sustava* je skup međusobno povezanih aktivnosti, koje se izvode tijekom razvojnog ciklusa. Stvarni se razvojni poduhvati izvode u skladu s odabranim obrascem procesa razvoja, koji su propisani ili preporučeni metodikom razvoja.

#### 3.1.4. Struktura metodike - metode i tehnike
**Tehnika** je skup praktičnih postupaka i vještina primjene zadane metode i obavljanja posla u konkretnoj situaciji.

*Osnovne metode i tehnike* u fazi projektiranja su modeliranje, a u fazi konstrukcije su programiranje.

*Metoda* - teorija načina primjene teorije
*Tehnika* - praksa primjene, vještina

#### 3.1.5. Struktura metodike - koncepti i metamodeli
*Modeli sustava* oblikuju se i izrađuju pomoću **koncepata**, od kojih je svaki na nekoj apstraktnoj razini reprezentira određeno svojstvo predmeta modeliranja.

**Metamodel** je skup svih koncepata i načina njihove primjene, u okviru neke metode ili tehnike modeliranja. To je model svih mogućih modela koje možemo izraditi pomoću koncepata neke metode i tehnike.

### 3.2. Model
**Model** je eksplicitna interpretacija nečijeg shvaćanja situacije, ili samo predodžbe situacije. Može biti izražen matematički, riječima ili simbolički, ali iznad svega mora biti koristan.

Vrste modela:

- **Slikovni** - slikovna predodžba predmeta, smanjenih, stvarnih ili povećanih dimenzija
- **Analogni** - neka svojstva originala u istom ili drugom fizičkom mediju
- **Matematički**
- **Konceptualni** - opis *kvalitativnih* aspekata područja od interesa ili pojave skupom dogovorenih koncepata (poznata simbolika, sintaksa i semantika)

Svojstva modela:

- **Verbalni modeli** sadrže opis sustava s komentarom na prirodnom jeziku
- **Fizički modeli** su povećane ili smanjene replike fizičkog sustava, izrađeni su u jednakom ili različitom fizičkom mediju u odnosu na original, a oponašaju funkciju i ponašanje sustava
- **Grafički modeli** prikazuju neka svojstva originala u formi slike, crteža ili dijagrama
- **Formalni modeli** su modeli kod kojih su svojstva originala prikazana matematičkih ili logičkim relacijama.

Mjesto modela:

- **Unutarnji (interni)** modeli su uključeni u sustav i dio su njegove strukture
- **Vanjski (eksterni)** modeli su izvan strukutre sustava

### 3.3. Veze metoda, tehnika i modela
Metode mogu biti opće (npr. apstrakcija, generalizacija, klasifikacija i sl.) ili posebne (strukturna analiza sustava, modeliranje ponašanja i sl.). Metode i tehnike projektiranja čvrsto su povezane, tako da se ta dva pojma često koriste kao sinonimi (npr. metoda entiteti-veza i tehnika entiteti-veza).

Tehnike se više vežu uz primjenu metoda. Tako govorimo o **dijagramskim tehnikama** (npr. oblikovanje dijagrama primjenom određene notacije, na temelju znanstvene metode), **tehnikama izrade specifikacija** (primjena specifikacijskog jezika određene sintakse i semantike), **tehnikama grupnog rada** s korisnicima i sl.

Projektiranje informacijskih i programskih sustava je **modeliranje**. Tijekom aktivnosti projektiranja izrađuju se modeli predmeta projektiranja uz pomoć različitih metoda i tehnika modeliranja.

## 4. Razvojni ciklus informacijskog sustava
### 4.1. Razvojni ciklus
**Razvojni ciklus** informacijskog sustava ili podsustava je vremensko razdoblje između donošenja formalne odluke o razvoju i formalne isporuke ili formalnog prekida razvoja.

Rezultat samog razvoja je ciljni proizvod, tj. određeni tip, varijanta ili generacija primjenjivog proizvoda. Rezultat svake faze razvojnog ciklusa je cjelovit, prepoznatljiv i provjerljiv model ili proizvod, koji se primjenjuje u sljedećoj fazi.

Svaki stvarni poduhvat razvoja informacijskog ili programskog sustava odvija se u skladu s nekakvim *predloškom* (modelom, obrascem, uzorkom), koji mora biti unaprijed opisan, te usklađen i prihvaćen od strane korisnika i projektanta.

Za neki stvarni poduhvat razvoja, predložak razvojnog ciklusa preuzima se doslovno iz odabrane metodike razvoja ili djelomično prilagođava stvarnim potrebama.

Predložak razvojnog ciklusa uvijek sadrži:

- **podjelu razvojnog ciklusa na faze**
- **opis mogućeg slijeda faza**
- **uvjete prelaska s jedne faze razvoja na drugu**

### 4.2. Strategijsko planiranje informacijskog sustava
Izrađuje se grubi konceptualni model postojećih procesa i podataka organizacijskog sustava, te model postojećeg informacijskog sustava.

Poslovodstvo aktivno sudjeluje u definiranju modela poslovnog sustava, što uključuje *model ciljeva, model ključnih čimbenika uspjeha, model kritičnih pretpostavki, model problema i model potreba za informacijama te drugih zahjteva prema IS-u...*

Na temelju analize ovih modela određuje se: *gruba struktura informacijskog sustava, prioriteti i redoslijed realizacije podsustava i okvirni troškovi i izvodljivost.*

Rezultat je strategijski plan informacijskog sustava, s planskim obzorom 3 do 5 godina.

### 4.3. Utvrđivanje izvodljivosti poduhvata
Cilj je utvrđivanje granica (opsega) i izvodljivosti planiranog poduhvata razvoja s tehničkih, tehnoloških, organizacijskih, ekonomskih i drugih gledišta.

Postoji više razina studije izvodljivosti i pratećih studija: *studija mogućnosti (opportunity), prethodna studija izvodljivosti (prefeasability), studija izvodljivosti (feasability) i studije potpore (support studies).*

Granice poduhvata se utvrđuju na grubom konceptualnom modelu podataka i procesa.

Rezultat je: **studija izvodljivosti, projektni zadatak budućeg poduhvata razvoja i eventualno natječajna dokumentacija.**

### 4.4. Analiza i specifikacija zahtjeva
U ovoj fazi se profinjava model podataka i procesa, odnosno objektni model. Detaljno se analiziraju i specificiraju zahtjevi prema budućem sustavu, koji se odnose na: *podatkovne sadržaje, funkcionalnost i tehnologiju rada, sučelje, odaziv, performanse i ostale oblike ponašanja i ostale nefunckionalne zahtjeve.*

### 4.5. Logičko modeliranje
Ova faza obuhvaća izradu detaljnog logičkog modela budućeg sustava, koji opisuje što on mora biti. U strukturnim tehnikama to znači: *dekompoziciju procesa, dijagrame toka podataka i opise unutarnje logike elementarnih procesa i model entitet-veze, njegovu pretvorbu u relacijski model i relacijsku analizu.*

U objektno orijentiranim tehnikama (npr. UML) to znači:

- specifikacija slučajeva korištenja i opis njihove unutarnje logike dijagramima aktivnosti
- izrada strukturnih modela (dijagrama klasa i podataka)
- opis dinamike objekta (strojevi stanja)
- specificiranje poruka (dijagrami slijeda i komunikacije)

### 4.6. Fizičko modeliranje i izrada
U ovoj fazi izrađuje se fizički model baze podataka (tablice, ključevi, indeksi, distribucija i replikacija), definiriaju se programski moduli i njihova distribucija, konstruiraju se programi, detaljno se razrađuju uloge korisnika i pogledi, detaljno se razrađuje sustav autorizacije korisnika i sigurnosti, detaljne se oblikuje sučelje, testiraju se pojedini moduli, moduli se integriraju i testira se cijelina, model se dokumentira i pojedini dijelovi i sustav u cjelini se validiraju s korisnicima.

### 4.7. Isporuka i primjena
