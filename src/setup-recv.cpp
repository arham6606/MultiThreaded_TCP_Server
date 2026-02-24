#include "MultiThreaded_TCP_Server/header-files.h"

void createRecv(int client_id)
{
    char buffer[1024];
    while (true) {
        ssize_t n = recv(client_id, buffer, sizeof(buffer), 0);
        if (n > 0) {
            string message(buffer,buffer+n);
            message = "[server] " + message + "<me>";

            send(client_id, message.data(), message.size(), 0);   // echo
        } else if (n == 0) {
            // client closed
            break;
        } else {
            // error
            perror("recv");
            break;
        }
    }
    close(client_id);
}