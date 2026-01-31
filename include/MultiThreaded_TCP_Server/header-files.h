#include<iostream>
using namespace std;
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstdio>
#include <unistd.h>
#include<arpa/inet.h>

int createSocket();
int createBind(int sock_id);
