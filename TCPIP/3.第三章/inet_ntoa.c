#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
  struct sockaddr_in addr1, addr2;
  char *str_ptr;
  char str_arr[20];

  addr1.sin_addr.s_addr = htonl(0x1020304);
  addr2.sin_addr.s_addr = htonl(0x1010101);

  str_ptr = inet_ntoa(addr1.sin_addr);
  strcpy(str_arr, str_ptr);// 浏览并复制str_ptr的IP地址信息
  printf("Dotted-Decimal notation1: %s \n", str_ptr);

  inet_ntoa(addr2.sin_addr);// 再次调用覆盖了新的IP地址字符串
  printf("Dotted-Decimal notation2: %s \n", str_ptr);// 输出新的IP地址字符串
  printf("Dotted-Decimal notation3: %s \n", str_arr);// 之前复制的IP地址字符串

  return 0;
}