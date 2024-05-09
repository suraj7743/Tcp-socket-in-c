#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    struct ifaddrs *address;
    if (getifaddrs(address)==-1 ){
        printf("getifAddress faild \n");
        return -1;
    };
    struct ifaddrs * addres= address;
    while ((addres))
    {
        
    }
    

}