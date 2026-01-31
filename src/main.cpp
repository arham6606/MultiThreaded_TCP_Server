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
    if (bind_id == -1) {
        perror("Bind error");
        close(socket_id);
        return -1;
    }

    int listen_id = createListen(socket_id);
    if(listen_id == -1)
    {
        perror("Listen error");
        close(socket_id);
        return -1;
    }

    cout<<"Server running on port 8080"<<endl;
    
    while(true)
    {   
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        
        int client_id = createAccept(socket_id,&client_addr,&client_len);

        if(client_id == -1)
        {
            perror("Accept Error");
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        
        cout << "✅ Client connected! fd=" << client_id 
                << " from " << client_ip << ":" 
                << ntohs(client_addr.sin_port) << endl;
        
        // Close client for now
        //close(client_id);
    }

    close(socket_id); // should not be closed in real servers

}