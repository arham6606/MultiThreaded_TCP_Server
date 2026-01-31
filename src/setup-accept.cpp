#include "MultiThreaded_TCP_Server/header-files.h"

int createAccept(int sock_id,struct sockaddr_in* client_addr, socklen_t* client_len)
{
    // BLOCKS until client connects
    int client_fd = accept(sock_id, (struct sockaddr*)client_addr, client_len);
    return client_fd;
}