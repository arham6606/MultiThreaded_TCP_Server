#include "MultiThreaded_TCP_Server/header-files.h"
atomic<bool>shutting_down{false};

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

    server_fd = socket_id;

    signal(SIGINT,handlerSigint);

    cout<<"Server running on port 8080"<<endl;
    
    while(!shutting_down.load())
    {     
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        
        int client_id = createAccept(socket_id,&client_addr,&client_len);

        if(client_id == -1)
        {
            if(shutting_down.load())
            {
                break;
            }
            perror("Accept Error");
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        {
            lock_guard<mutex>lock(active_clients_mutex);
            ++client_count;
        }
        cout << "✅ Client connected! fd=" << client_id 
                << " from " << client_ip << ":" 
                << ntohs(client_addr.sin_port) << endl;

                cout<<"Client Count:"<<client_count<<endl;
        // client send data
        thread t(createRecv,client_id);
        t.detach();
    // createRecv(client_id);
        
        // Close client for now
        //close(client_id);
    }
 cout<<"End Client Count:"<<client_count<<endl;
    close(socket_id); // should not be closed in real servers

}