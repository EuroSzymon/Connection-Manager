// Author: DotykProboszcza

#include <pcap.h>
#include <iostream>

void packet_handler(u_char* user, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    // Pomijamy pakiet, jeśli jego rozmiar jest mniejszy niż minimalny nagłówek IP
    if (pkthdr->len < 14 + 20) {
        return;
    }

    // Odczytujemy adres źródłowy i docelowy z nagłówka IP
    const u_char* src_ip = packet + 26;
    const u_char* dst_ip = packet + 30;

    // Wyświetlamy adresy IP
    std::cout << "Adres źródłowy: " << int(src_ip[0]) << "." << int(src_ip[1]) << "." << int(src_ip[2]) << "." << int(src_ip[3]) << std::endl;
    std::cout << "Adres docelowy: " << int(dst_ip[0]) << "." << int(dst_ip[1]) << "." << int(dst_ip[2]) << "." << int(dst_ip[3]) << std::endl;
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];

    // Otwieramy interfejs sieciowy w trybie promiscuous
    pcap_t* handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        std::cerr << "Błąd przy otwieraniu interfejsu sieciowego: " << errbuf << std::endl;
        return 1;
    }

    // Ustawiamy filtr na ruch IP
    struct bpf_program fp;
    pcap_compile(handle, &fp, "ip", 0, PCAP_NETMASK_UNKNOWN);
    pcap_setfilter(handle, &fp);

    // Rozpoczynamy przechwytywanie pakietów
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);
    return 0;