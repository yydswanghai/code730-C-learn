#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
  char *addr1 = "1.2.3.4";
  // 1字节能表示的最大整数位255，这是错误的IP地址，验证inet_addr函数的错误检测能力
  // inet_addr 失败时返回 INADDR_NONE
  char *addr2 = "1.2.3.256";

  unsigned long conv_addr = inet_addr(addr1);
  if (conv_addr == INADDR_NONE) {
    printf("Error occureded! \n");
  } else {
    printf("Network ordered integer addr: %#lx \n", conv_addr);
  }
  conv_addr = inet_addr(addr2);
  if (conv_addr == INADDR_NONE) {
    printf("Error occureded \n");
  } else {
    printf("Network ordered integer addr: %#lx \n\n", conv_addr);
  }

  return 0;
}