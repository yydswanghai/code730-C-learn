// 右移
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a = 0x80000000;// 4字节的整数所能表达的最大的负数
//1000000000000...000
//1100000000000...000 实际上是这样移一位
//0100000000000...000 而不是这种

  unsigned int b = 0x80000000;
  printf("a=%d\n", a);// a是一个负数
  printf("b=%u\n", b);// b是一个正数

  printf("a<<1=%d\n", a<<1);// 0000000000000...000
  printf("a>>1=%d\n", a>>1);// 右移后依然是一个负数
  printf("b>>1=%u\n", b>>1);// 右移后依然是一个正数

  return 0;
}
