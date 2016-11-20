/* 
 * File:   TCPServer.hpp
 * Author: dontsov
 *
 * Created on November 17, 2016, 8:58 PM
 */

#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <vector>

#include "TCPSocket.hpp"
#include "SocketAddress.hpp"
#include "Uncopyable.hpp"
#include "SocketUtil.hpp"

const size_t DEFAULT_PORT = 48000;

class TCPServer : private Uncopyable {
public:
    TCPServer();
    explicit TCPServer(const std::string& inAddress);
    virtual ~TCPServer();

    /** Процесс запуска сервера для приема и обработки данных */
    void Run();

    /** Количество подключившихся клиентов
     * 
     * @return количество клиентов
     */
    size_t CountOfConnectedClients() const;

private:
/* Хранит данные о клиенте для связи с ним */
    struct ClientInfo {
        TCPSocketPtr bindingSocket;
        SocketAddressPtr clientAddress;
    };

private:
    TCPSocketPtr mListenSocket;
    SocketAddressPtr mAddress;
    SocketsVector mReadableSockets;
    SocketsVector mReadSockets;
};

#endif /* TCPSERVER_HPP */