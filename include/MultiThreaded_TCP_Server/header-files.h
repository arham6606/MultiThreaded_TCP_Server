#include <iostream>
using namespace std;
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>
#include <mutex>
#include <csignal>
#include <atomic>
extern atomic<bool> shutting_down;
extern mutex active_clients_mutex;
extern int client_count;
extern int server_fd;

int createSocket();
int createBind(int sock_id);
int createListen(int sock_id);
int createAccept(int sock_id, struct sockaddr_in *client_addr, socklen_t *client_len);
void createRecv(int client_id);
void handlerSigint(int);
