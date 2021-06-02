服务端

初始化socket；bind将服务能力到 ip:port；listen将socket转化为单独的服务socket；accept等待客户端请求

客户端

初始化socket；connect向服务端发起请求

客户端向内核write字节流写；内核通过网络设备发送字节流到服务器；服务器从内核读取字节流到进程；业务逻辑处理

服务端、客户端都执行close，链路关闭

套接字通用地址结构
typedef unsigned short int sa_family_t;
struct sockaddr{
    sa_family_t sa_family; /*地址族，16-bit；AF_LOCAL；AF_INET；AF_INET6*/
    char sa_data[14]; /*具体地址值，112-bit；*/
}

IPv4 套接字地址族结构

/* IPV4套接字地址，32bit值.  */
typedef uint32_t in_addr_t;
struct in_addr
  {
    in_addr_t s_addr;
  };
  
/* 描述IPV4的套接字地址格式  */
struct sockaddr_in
  {
    sa_family_t sin_family; /* 16-bit */
    in_port_t sin_port;     /* 端口号  16-bit*/
    struct in_addr sin_addr;    /* Internet address. 32-bit */


    /* 这里仅仅用作占位符，不做实际用处  */
    unsigned char sin_zero[8];
  };