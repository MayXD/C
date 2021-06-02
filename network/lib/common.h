#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h> 

int make_socket(uint16_t port);
size_t readn(int fd, void *buffer, size_t size);