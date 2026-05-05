import socket


# funkcija za provjeru unesene IP adrese
def check_ip(ip_adresa: str):
    ispravan: bool = True
    split_ip = ip_adresa.split(".")

    for number in split_ip:
        if int(number) >= 0 and int(number) <= 255:
            continue
        else:
            ispravan = False

    return ispravan


# funkcija za provjeru unesenog porta
def check_port(port: int):
    if port >= 0 and port <= 65535:
        return True
    else:
        return False


# funkcija za unos IP adrese
def ip_unos():
    ip_adresa: str

    while True:
        ip_adresa = input("Unesite IP adresu na koju se želite spojiti: ")

        if not check_ip(ip_adresa.strip()):
            print("Unesena neispravna IP adresa!")
            continue
        else:
            break

    return ip_adresa.strip()


# funkcija za unos porta
def port_unos():
    port: int

    while True:
        port = int(input("Unesite port na koji se želite spojiti: "))

        if not check_port(port):
            print("Unesen neispravan port!")
            continue
        else:
            break

    return port


def main():
    # odgovori koji se šalju serveru
    jmbag: str = "0016170032"
    ime: str = "Hrvoje"
    prezime: str = "Kajba"

    # ip adresa i port na koji se šalju odgovori
    ip_adresa: str = ip_unos()
    port: int = port_unos()
    destination = (ip_adresa, port)

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # šalji poruke sve dok korisnik ne prestane
    while True:
        # korisnik definira poruku koju šalje poslužitelju
        message: str = jmbag

        # korisnik šalje prvotnu poruku poslužitelju
        client_socket.sendto(message.encode(), destination)

        # zaprimi odgovor od poslužitelja
        response, where_from = client_socket.recvfrom(1024)

        print(f"\n[Server]: {response.decode()}\n")

        # ako je odgovor ime, pošalji jmbag i ime
        if response.decode() == "ime":
            message = f"{jmbag}, {ime}"
            client_socket.sendto(message.encode(), destination)
        # ako je odgovor prezime, pošalji jmbag i prezime
        elif response.decode() == "prezime":
            message = f"{jmbag}, {prezime}"
            client_socket.sendto(message.encode(), destination)

        nastavi: str = input("Želite li ponovno poslati poruku [d/n]? ")

        if not nastavi.strip().lower() == "d":
            break


if __name__ == "__main__":
    main()
