#ifndef NET_CONNECTION_H
#define NET_CONNECTION_H

namespace NetManager {
    bool initSocket(int port);
    void closeSocket();
}

#endif

#ifndef NET_CONNECTION_H
#define NET_CONNECTION_H

namespace NetManager {
    bool initSocket(int port);
    void closeSocket();
    bool receiveData(char* buffer, int length); // <--- Adicionar esta linha
}

#endif

bool sendData(const char* data, int length, const char* ip, int port);
