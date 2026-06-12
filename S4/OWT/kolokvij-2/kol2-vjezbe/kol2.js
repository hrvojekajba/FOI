let gumbIspis = document.getElementsByClassName("ispis");

class ObradaTeksta {
    constructor() {
        this.tekstA = "";
        this.tekstB = "";
        this.ispisRezultata = document.getElementsByTagName("h1")[0];
    }

    preuzmiUnos() {
        this.tekstA = document.getElementById("tekstA");
        this.tekstB = document.getElementById("tekstB");
    }

    prikaziPodatke() {
        let totalDuljina = tekstA.value.length + tekstB.value.length;
        this.ispisRezultata.innerHTML = `Prikaz rezultata: ${tekstA.value} - ${tekstB.value} = ${totalDuljina}`;
    }
}

let obrada = new ObradaTeksta();

gumbIspis[0].addEventListener("click", (event) => {
    obrada.preuzmiUnos();
    obrada.prikaziPodatke();
});
