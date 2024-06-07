#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include "client/client.c"

void server()
{
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;  

    // Create Socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Socket Creation Failed.");
        exit(1);
    }

    // Bind Socket
    server_addr.sin_family = AF_INET6; 
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Binding Failed.");
        exit(1);
    }

    // Listen for Connections
    if (listen(sockfd, 5) < 0) // Queue 5 messages 
    {
        perror("Listen Failed.");
        exit(1);    
    }

    // Accept Clients Connections
    while(1) 
    {
        client_addr_size = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_size); 
        if(new_sockfd < 0)
        {
            perror("Accept Failed.");
            continue;
        }

        // Logic for Connected Client, new_sockfd

        close(new_sockfd); // Close client socket
    }
    
    close(sockfd); // Close all connections
};



int main()
{
    printf("TEST");

    return 0;
}