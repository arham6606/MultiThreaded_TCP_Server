#include "MultiThreaded_TCP_Server/header-files.h"

int main()
{
    int socket_id = createSocket();

    if(socket_id == -1)
    {
        perror("Socket error");
        return -1;
    }

    int bind_id  = createBind(socket_id);
    if (bind_id== -1) {
        perror("Bind error");
        close(socket_id);
        return -1;
    }

    

}