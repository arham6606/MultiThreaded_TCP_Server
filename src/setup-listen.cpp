#include "MultiThreaded_TCP_Server/header-files.h"

int createListen(int sock_id)
{
    int listen_id = listen(sock_id,4);
    return listen_id;
}