#include<iostream>
using namespace std;
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstdio>
#include <unistd.h>
#include<arpa/inet.h>
#include <thread>

int createSocket();
int createBind(int sock_id);
int createListen(int sock_id);
int createAccept(int sock_id,struct sockaddr_in* client_addr, socklen_t* client_len);
void createRecv(int client_id);

