#include "net_connection.h"
#include <cstring>
#include <iostream>

#ifdef __ANDROID__
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#endif

// Implementação básica de Socket UDP para comunicação local Wi-Fi
namespace NetManager {
    int sockfd = -1;
    bool isServer = false;

    bool initSocket(int port) {
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            return false;
        }

        // Tornar o socket não-bloqueante para o jogo não travar à espera de pacotes
        int flags = fcntl(sockfd, F_GETFL, 0);
        fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

        sockaddr_in address{};
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);

        if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            close(sockfd);
            sockfd = -1;
            return false;
        }

        return true;
    }

    void closeSocket() {
        if (sockfd >= 0) {
            close(sockfd);
            sockfd = -1;
        }
    }
}
