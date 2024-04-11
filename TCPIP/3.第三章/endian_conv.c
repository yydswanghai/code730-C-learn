#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
  unsigned short host_port = 0x1234; // 保存2字节的数据
  unsigned short net_port;
  unsigned long host_addr = 0x12345678;// 保存4字节的数据
  unsigned long net_addr;
  
  net_port = htons(host_port);// 转换为网络字节序
  net_addr = htonl(host_addr);// 转换为网络字节序

  printf("主机端口: %#x \n", host_port); // 0x1234
  printf("网络端口: %#x \n", net_port);  // 0x3412     网络字节序
  printf("主机IP : %#lx \n", host_addr);// 0x12345678
  printf("网络IP : %#lx \n", net_addr); // 0x78563412 网络字节序

  return 0;
}