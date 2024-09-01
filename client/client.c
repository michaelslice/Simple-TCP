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
#include <sys/unistd.h>

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
    
    while (message != "2"){
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);

        if(message == "2"){
            close(sockfd);
            exit(1);
            break;
        }

        int bytes_sent = send(sockfd, message, strlen(message), 0); 
        if (bytes_sent < 0)
        {
            perror("Send Failed");
            close(sockfd);
            exit(1);
        }
    }

    close(sockfd);
};

void create_chat_room()
{
    int chatrooms[20];

    struct sockaddr_in server_addr;
    int sockfd;
    
    char server_name[100];
    printf("Hello Please Enter Chat Room Name for Creation: ");
    scanf("%s", server_name);
    
    char server_port[100];
    printf("Hello Please Enter Chat Room Name for Creation: ");
    scanf("%d", server_port);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0)
    {
        perror("Socket Creation Failed.");
        exit(1);
    }

    printf(server_name);
    printf("\n");
};

void client()
{
    int op = 0;
    int option = 0;

    printf("Hello welcome to Simple Chat, please enter a message (Press 2 to Quit). \n");
    client_side();
    
};

int get_ip_address()
{
    char hostname[128];
    gethostname(hostname, sizeof(hostname));
    printf("My hostname: %s\n", hostname);
}

int main()
{
    // Run client mode
    client();

    return 0;
}