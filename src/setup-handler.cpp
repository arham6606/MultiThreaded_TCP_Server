#include "MultiThreaded_TCP_Server/header-files.h"
int server_fd = 0;

void handlerSigint(int)
{
shutting_down.store(true);
close(server_fd);
cout<<"Server closing"<<endl;
}