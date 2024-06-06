#include <stdio.h>

void client()
{
    int op = {0};
    
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
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        default:
            printf("Error Invalid Option Entered \n");
            break;
        }
    }
};