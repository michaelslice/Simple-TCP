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

int main()
{
    client();
    // client_side();
    return 0;
}

void client_side()
{
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;  

    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(1800);

    // Create Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Socket Creation Failed.");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection Failed");
        close(sockfd);
        return;
    }

    char message[256];
    printf("Enter message");
    fgets(message, sizeof(message), stdin);

    int bytes_sent = send(sockfd, message, strlen(message), 0); 
    if (bytes_sent < 0)
    {
        perror("Send Failed");
        close(sockfd);
        exit(1);
    }

    close(sockfd);
};

void client()
{
    int op = 0;
    
    printf("Hello welcome to Simple Chat, please pick a command. \n");
         
    while(op != 5)
    {
        printf("Change User Name (Enter 1) \n");
        printf("Join a Chat Room (Enter 2) \n");
        printf("Create Chat Room (Enter 3) \n");
        printf("Print List of Chat Rooms (Enter 4) \n");
        
        printf("Quit (Enter 5) \n");

        (scanf("%d", &op));
        
        switch (op)
        {
        case 1:
            
            client_side();
            
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        default:
            printf("Error Invalid Option Entered \n");
            break;
        }
    }
};