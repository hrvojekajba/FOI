1. 
	`CREATE TABLE kategorija (id SERIAL PRIMARY KEY, naziv VARCHAR(50) NOT NULL, dostupno_online BOOLEAN DEFAULT FALSE);`
	
	`CREATE TABLE artikli (id SERIAL PRIMARY KEY, naziv VARCHAR(100) NOT NULL, opis VARCHAR(300), cijena NUMERIC(10, 2), mjera VARCHAR(40) NOT NULL, kategorija INTEGER REFERENCES kategorija(id) ON DELETE RESTRICT ON UPDATE RESTRICT);`

2. 
	`ALTER TABLE kategorija ADD CONSTRAINT jedinstvenost UNIQUE(naziv);`

3. 
	`INSERT INTO kategorija (naziv, dostupno_online) VALUES ('hrana', true), ('piće', true), ('droga', true);`
	
	`INSERT INTO artikli (naziv, opis, cijena, mjera, kategorija) VALUES ('Kruh', null, 2.5, 'g', 1), ('Pašteta', null, 2, 'g', 1), ('Fanta', null, 1.5, 'ml', 2);`

4. 
	`SELECT naziv, cijena FROM artikli WHERE opis != NULL ORDER BY naziv, cijena DESC;`

5. 
	`SELECT k.naziv AS kategorija, a.naziv AS artikl, a.opis FROM kategorija k LEFT JOIN artikli a ON k.id = a.kategorija;`

6. 
	`CREATE VIEW pogled AS SELECT k.naziv AS kategorija FROM kategorija k JOIN artikli a ON k.id = a.kategorija WHERE a.cijena < 100;`

7. 
	`SELECT k.naziv AS kategorija, COUNT(*) AS broj INTO broj_artikala FROM kategorija k JOIN artikli a ON k.id = a.kategorija GROUP BY k.naziv;`

8. d
	`CREATE FUNCTION najveca_cijena() RETURNS NUMERIC(10, 2)`
	`AS $$ SELECT MAX(cijena) FROM artikli; $$ LANGUAGE SQL;`
	`SELECT najveca_cijena();` - poziv funkcije