// network_utils.h

#ifndef NETWORK_UTILS_H
#define NETWORK_UTILS_H

#include <netinet/in.h>

// Function declaration for createIpv4Address
struct sockaddr_in* createIpv4Address(const char* ip, int port);
int createTcpV4Socket();

#endif // NETWORK_UTILS_H