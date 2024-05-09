#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdbool.h>
#include "../utils/network_utils.h"

int main(){
    int socketFd=socket(AF_INET,SOCK_STREAM,0);
    printf("I am client\n");

    //this is to assign ipv4 adress 
    char*ip = "127.0.0.1";
    int port =2000;
    struct sockaddr_in *address=createIpv4Address(ip, port); 

     if (address == NULL) {
        close(socketFd); // Close the socket on memory allocation failure
        return 1;
    }
    //we could connect this file descripter to remote socket reamining idle 
    int result = connect(socketFd,address, sizeof (*address) );
    if (result ==0){
        printf("Connection successful \n");
    }

    else{
        printf("connection failed");
    }
    const char *message =NULL;
    size_t message_size=0;
    printf("Enter message orType (exit) to quit\n");
    while (true)
    {
        size_t count = getline(&message,&message_size, stdin );
        if (count>0){
            if (strcmp(message, "exit\n")==0){
                break;
            }
            ssize_t amountSend= send(socketFd,message, strlen(message), 0 );
        }
    }
    

    close(socketFd);
    return 0;
} 