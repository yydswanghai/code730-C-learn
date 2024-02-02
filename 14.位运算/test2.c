// 左移
#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned char c = 0xA5;
  printf("   c=%hhx\n", c);
  printf("c<<2=%x\n", c<<2);// x 16进制输出
  printf("   c=%d\n", c);   // 165
  printf("c<<2=%d\n", c<<2);// 660    660=4倍的164

  return 0;
}
