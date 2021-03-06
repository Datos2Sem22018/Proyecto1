//
// Created by zuckerberg on 27/09/18.
//

#ifndef PROYECTO1_CLIENTSOCKET_H
#define PROYECTO1_CLIENTSOCKET_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netdb.h>
#include <vector>
using namespace std;


class ClientSocket {
private:
    int sock;
    string address;
    int port;
    struct sockaddr_in server;
public:
    ClientSocket();
    bool setup(string address, int port);
    bool Send(string data);
    string receive(int size = 4096);
    string read();
    void exit();
};



#endif //PROYECTO1_CLIENTSOCKET_H
