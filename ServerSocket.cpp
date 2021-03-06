//
// Created by zuckerberg on 27/09/18.
//

#include "ServerSocket.h"

string ServerSocket::Message;

void* ServerSocket::Task(void *argv) {
    int n;
    int newsockfd = (long)argv;
    char msg[MaxPacketSize];
    pthread_detach(pthread_self());
    while(1)
    {
        n=recv(newsockfd,msg,MaxPacketSize,0);
        if(n==0)
        {
            close(newsockfd);
            break;
        }
        msg[n]=0;
        Message = string(msg);
    }
    return 0;
}

void ServerSocket::setup(int port) {
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    memset(&serverAddress,0,sizeof(serverAddress));
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
    serverAddress.sin_port=htons(port);
    bind(sockfd,(struct sockaddr *)&serverAddress, sizeof(serverAddress));
    listen(sockfd,5);
}

string ServerSocket::receive() {
    string str;
    while(1)
    {
        socklen_t sosize  = sizeof(clientAddress);
        newsockfd = accept(sockfd,(struct sockaddr*)&clientAddress,&sosize);
        str = inet_ntoa(clientAddress.sin_addr);
        pthread_create(&serverThread,NULL,&Task,(void *)newsockfd);
    }
    return str;
}

string ServerSocket::getMessage() {
    return Message;
}

void ServerSocket::Send(string msg) {
    send(newsockfd,msg.c_str(),msg.length(),0);
}

void ServerSocket::clean() {
    Message = "";
    memset(msg, 0, MaxPacketSize);
}

void ServerSocket::detach() {
    close(sockfd);
    close(newsockfd);
}