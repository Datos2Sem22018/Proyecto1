//
// Created by zuckerberg on 27/09/18.
//

#ifndef PROYECTO1_SERVERSOCKET_H
#define PROYECTO1_SERVERSOCKET_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#define MaxPacketSize 4096
using namespace std;


class ServerSocket {
public:
    int sockfd, newsockfd, n, pid;
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
    pthread_t serverThread;
    char msg[MaxPacketSize];
    static string Message;
    void setup(int port);
    string receive();
    string getMessage();
    void Send(string msg);
    void detach();
    void clean();
private:
    static void* Task(void* argv);
};


#endif //PROYECTO1_SERVERSOCKET_H
