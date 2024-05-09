
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "network_utils.h"
#include<string.h>



// Function to create an IPv4 address structure
struct sockaddr_in* createIpv4Address(const char* ip, int port) {
    struct sockaddr_in* address = malloc(sizeof(struct sockaddr_in)); // No cast needed
    if (address == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    address->sin_family = AF_INET;
    address->sin_port = htons(port); // Convert port to network byte order
    if (strlen(ip)==0){
        printf("size ip 0\n");
        address->sin_addr.s_addr=INADDR_ANY;
    }
    else{
        if (inet_pton(AF_INET, ip, &(address->sin_addr)) <= 0) { // Corrected `inet_pton`
        printf("Invalid IP address\n");
        free(address); // Free memory if `inet_pton` fails
        return NULL;
    }
    }
   
    return address; // Return the pointer to the allocated structure
}



// Function to create a TCP socket
int createTcpV4Socket() {
    //here socket function take 
    //adress= AF_Inet(means ipv4 adress), 
    //sock_stream means tcp or udp 
    //protocol:0 means This is the protocol parameter. When you set it to 0, the system chooses the appropriate default protocol based on the socket type. In this case, it would be TCP.
    //socketFd is the socket file descripter if it is -1 then socket creation fails .


    //this is to get permission from os for tcp connection which provide fd to connect to it ;
    return socket(AF_INET, SOCK_STREAM, 0);
}


