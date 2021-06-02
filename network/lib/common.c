#include "common.h"

int make_socket(uint16_t port) {
    int sock;
    struct sockaddr_in name;

// 创建字节流型的socket
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

// 绑定到port和ip
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

// 把IPv4地址转换成通用地址格式，同时传递长度
    if (bind(sock, (struct sockaddr *) &name, sizeof(name)) < 0) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    return sock;
}

// 从socketfd描述字中读取size个字节
size_t readn(int fd, void *buffer, size_t size) {
    char *buffer_pointer = buffer;
    int length = size;
    
    while (length > 0) {
        int result = read(fd, buffer_pointer, length); 

        if (result < 0) {
            if (errno == EINTR)
                continue;
            else
                return(-1);
        } else if (result == 0)
            break;

        length -= result;
        buffer_pointer += result;
    }

    return (size - length);
}