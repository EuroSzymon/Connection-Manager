// Author: DotykProboszcza

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Błąd przy tworzeniu gniazda." << std::endl;
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80); // Możesz zmienić port w zależności od potrzeb
    inet_pton(AF_INET, "192.168.1.1", &addr.sin_addr); // Adres IP do skanowania

    int result = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (result < 0) {
        std::cerr << "Urządzenie jest niedostępne." << std::endl;
        return 1;
    }

    std::cout << "Urządzenie jest dostępne." << std::endl;
    close(sockfd);
    return 0;
}