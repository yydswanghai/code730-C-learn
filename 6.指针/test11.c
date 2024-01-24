// 测试p[0]

#include <stdio.h>

int main() {
  int min = 2;
  int *p = &min;
  printf("*p=%d\n", *p);// p指向min的地址，*p就是min地址里面的值
  printf("p[0]=%d\n", p[0]);// p[0] 把p所指向的地址，当作一个数组

  return 0;
}