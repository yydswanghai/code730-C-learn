// 测试AA的补码和取反
#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned char c = 0xAA;
  printf(" c=%hhx\n", c);
  printf("~c=%hhx\n", (char)~c);
  printf("-c=%hhx\n", (char)-c);

  return 0;
}
