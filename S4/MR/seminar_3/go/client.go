package main

import (
	"fmt"
	"log"
	"net"
	"strconv"
	"strings"
)

const (
	JMBAG   string = "0016170032"
	IME     string = "Hrvoje"
	PREZIME string = "Kajba"
)

func check_ip(ip_address string) bool {
	var ispravan bool = true
	split_ip := strings.Split(ip_address, ".")

	for i := range split_ip {
		ip_number, err := strconv.Atoi(split_ip[i])
		if err != nil {
			log.Fatal("Failed to convert string to number")
		}

		if ip_number >= 0 && ip_number <= 255 {
			continue
		} else {
			ispravan = false
		}
	}

	return ispravan
}

func get_ip() string {
	var ip_address string

	fmt.Println("")
	for {
		fmt.Printf("Uneste IP adresu: ")
		fmt.Scanln(&ip_address)

		if check_ip(ip_address) {
			break
		} else {
			fmt.Println("Unesena neispravna IP adresa!")
			continue
		}
	}

	return ip_address
}

func get_port() int {
	var port int

	fmt.Println("")
	for {
		fmt.Printf("Unesite port: ")
		fmt.Scanln(&port)

		if port >= 0 && port <= 65535 {
			break
		} else {
			fmt.Println("Unesen je neispravan port!")
			continue
		}
	}

	return port
}

func main() {
	var ip_address string = get_ip()
	var port int = get_port()
	var destination string = ip_address + ":" + strconv.Itoa(port)

	// provjeri adresu poslužitelja
	server_address, err := net.ResolveUDPAddr("udp", destination)
	if err != nil {
		log.Fatal("Failed to resolve server address")
	}

	// spoji se na poslužitelja
	connection, err := net.DialUDP("udp", nil, server_address)
	if err != nil {
		log.Fatal("Failed to connect to server")
	}
	defer connection.Close()

	for {
		// pošalji jmbag serveru
		message := []byte(JMBAG)
		_, err := connection.Write(message)
		if err != nil {
			log.Fatal("Failed to send message to server")
		}

		// čekaj odgovor od servera
		buffer := make([]byte, 1024)
		answer, _, err := connection.ReadFromUDP(buffer)
		if err != nil {
			log.Fatal("Failed to read anwser from server")
		}

		fmt.Printf("\nServerov odgovor: %s", string(buffer[:answer]))

		if string(buffer[:answer]) == "ime" {
			message = []byte(JMBAG + ", " + IME)
		} else {
			message = []byte(JMBAG + ", " + PREZIME)
		}

		_, err = connection.Write(message)
		if err != nil {
			log.Fatal("Failed to send message to server")
		}

		var nastavi string
		fmt.Printf("\nŽelite li nastaviti s slanjem poruke [d/n]?")
		fmt.Scanln(&nastavi)

		if nastavi != "d" {
			break
		}
	}

}
