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

void server_side()
{
    // File descriptors, info on client, and server socket addresses
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr; 
    socklen_t client_addr_size;  

    printf("Server is running and waiting for connections...\n");

    // Create a IPv4, TCP Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0)
    {
        perror("Socket Creation Failed.");
        exit(1);
    }

    /**
     *  server_addr.sin_family : Address family of socket, IPv4, IPv6, etc
     *
     *  server_addr.sin_addr.s_addr : IP address of the server
     * 
     *  server_addr.sin_port : Port number that the server will listen on, in network byte order using htons()   
     */
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(1800);
    
    /**
     *  The function bind will attempt to bind the Socket 'sockfd' to the IP Address and Port Number  
     * 
     *  sockfd : Socket descriptor
     * 
     *  (struct sockaddr*)&server_addr : Pointer to the 'server_addr' struct that contains the IP address, and port number that the socket will be bound to  
     * 
     *  sizeof(server_addr) :  Size of the 'server_addr' in bytes
     */
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
        new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_size); // Return a new socket descriptor for the accepted client connection
        if(new_sockfd < 0)
        {
            perror("Accept Failed.");
            continue;
        }

        // Logic for Connected Client, new_sockfd
        char buf[256];  
        int bytes_recieved = recv(new_sockfd, buf, sizeof(buf), 0);
        if (bytes_recieved < 0)
        {
            perror("Recieve Failed.");
            close(new_sockfd);
            continue;
        }

        printf("Message Recieved: %s\n", buf);
       
        int bytes_sent = send(new_sockfd, buf, bytes_recieved, 0);
        if(bytes_sent < 0)
        {
            perror("SEND FAILED");
            close(new_sockfd);
            continue;
        }

        close(new_sockfd); // Close client socket
    }
    
    close(sockfd); // Close all connections
};

int main()
{
    // Run server
    
    server_side();
    return 0;
}