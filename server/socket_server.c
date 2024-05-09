#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h> // For close()
#include "../utils/network_utils.h"


int main() {
    int socketFd = createTcpV4Socket();
    printf("Server socket\n");
    if (socketFd == -1) {
        perror("Socket creation failed\n");
        return 1; // Early exit if socket creation fails
    }
    int port = 2000;
    //server side so using empty ip for all network to connect to  
    struct sockaddr_in* address = createIpv4Address("", port);

    if (address == NULL) {
        close(socketFd); // Close the socket on memory allocation failure
        return 1;
    }

    // Try to bind  to the given IP and port
    int bind_result =bind(socketFd, address, sizeof(*address));
    if (bind_result!=-1){
        printf("Socket was bound successfully\n");
    }
    else{
        printf("Socket couldn't bound ");
    }

    int listen_result =listen(socketFd,10);
    struct sockaddr_in clientAddress;
    int clientAddressSize= sizeof(struct sockaddr_in);
    int clientAcceptSocketFD=accept(socketFd,&clientAddress,&clientAddressSize );


    char buffer[1024];
    while(true){
        ssize_t amountReceived= recv(clientAcceptSocketFD, buffer, 1024, 0);
        if (amountReceived>0){
            buffer[amountReceived]=0;
            printf("client:%s\n", buffer);
        }
        if (amountReceived ==0){
            break;
        }


    }
    printf("Respose %s",buffer );
    close(clientAcceptSocketFD);
    shutdown(socketFd,SHUT_RDWR);

    // Free the allocated address structure
    // free(address);
    
    // Close the socket to release system resources
    // close(socketFd);

    return 0;
}
