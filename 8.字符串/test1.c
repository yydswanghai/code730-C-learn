#include <stdio.h>

int main() {
  int i = 0;
  char *s = "hello world";
  char *s2 = "hello world";
  // s[0] = 'B';
  char s3[] = "hello world";

  printf("&i=%p\n", &i);// 0x16bcdb070
  printf(" s=%p\n", s); // 0x104127f74     位于程序的代码段，只读
  printf("s2=%p\n", s2);// 0x104127f74     同一个代码段
  printf("s3=%p\n", s3);// 0x16bcdb078     同一个代码段
  s3[0] = 'B';
  printf("s3[0]=%c\n", s3[0]);

  return 0;
}