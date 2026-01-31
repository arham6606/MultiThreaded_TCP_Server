#include "MultiThreaded_TCP_Server/header-files.h"



int createSocket()
{
    int sock_id = socket(AF_INET,SOCK_STREAM,0);
    return sock_id;
}