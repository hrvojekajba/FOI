import socket as s
import signal

SERVER_ADDRESS = "127.0.0.1"
SERVER_PORT = 50000
BUFFER_SIZE = 2048


def main():
    server_socket = s.socket(s.AF_INET, s.SOCK_DGRAM)
    server_socket.bind((SERVER_ADDRESS, SERVER_PORT))

    shutdown_requested = False
    ime_prezime = False

    def handle_sigint(signum, frame):
        nonlocal shutdown_requested
        shutdown_requested = True

    signal.signal(signal.SIGINT, handle_sigint)

    print("== Mali posluzitelj za testiranje ==")
    print("Postoji timer od kad se dobi prva poruka, 10 sekundi je.")
    print("Taj timer utjece na CTRL+C pa bu mozda malo trebalo cekat,")
    print("a tu je cist da posluzitelj more delat celo vreme i sikak")
    print("se na kraju socket zatvori :) (also da malo brze pisi odgovor)")
    print("Ak ti je prekratko, while petlja prva linija promeni 10.0 v nes vece")
    print("\nNa klijentu upisi ove podatke:")
    print(" - server_adresa = '127.0.0.1'")
    print(" - server_port = 50000")
    print("=================================================================\n")
    while not shutdown_requested:
        server_socket.settimeout(10.0)
        try:
            encoded_message, client_info = server_socket.recvfrom(BUFFER_SIZE)
        except s.timeout:
            continue

        print(f"[JMBAG]: {encoded_message.decode()}")

        if ime_prezime:
            server_socket.sendto("ime".encode(), client_info)
            ime_prezime = False
        else:
            server_socket.sendto("prezime".encode(), client_info)
            ime_prezime = True

        encoded_message, client_info = server_socket.recvfrom(BUFFER_SIZE)
        print(f"[DOBIVENO]: {encoded_message.decode()}\n")

    server_socket.close()


if __name__ == "__main__":
    main()
