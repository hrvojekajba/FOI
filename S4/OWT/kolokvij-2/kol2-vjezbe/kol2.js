class ObradaTeksta {
    constructor() {
        this.tekstA = "";
        this.tekstB = "";
        this.ispisRezultata = document.getElementsByTagName("h1")[0];
    }

    preuzmiUnos() {
        this.tekstA = document.getElementById("tekstA").value;
        this.tekstB = document.getElementById("tekstB").value;
    }

    prikaziPodatke() {
        let totalDuljina = this.tekstA.length + this.tekstB.length;
        this.ispisRezultata.innerHTML = `Prikaz rezultata: ${tekstA.value} - ${tekstB.value} = ${totalDuljina}`;
    }
}

let obrada = new ObradaTeksta();

document.getElementsByClassName("ispis")[0].addEventListener("click", () => {
    obrada.preuzmiUnos();
    obrada.prikaziPodatke();
});
