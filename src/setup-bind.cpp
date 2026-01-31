#include "MultiThreaded_TCP_Server/header-files.h"

int createBind(int sock_id)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);           // Network byte order
    addr.sin_addr.s_addr = INADDR_ANY;     // Bind to all interfaces (0.0.0.0)
    
    int binded = bind(sock_id, (struct sockaddr*)&addr, sizeof(addr)); 
    return binded;
}