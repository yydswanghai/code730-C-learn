#include <stdio.h>

int main() {
  int i = 0;
  int p;
  p = (int)&i;
  printf("0x%x\n", p);
  printf("%p\n", &i);
  // 64位架构下
  printf("%lu\n", sizeof(int));// 4字节
  printf("%lu\n", sizeof(&i));// 8字节

  return 0;
}