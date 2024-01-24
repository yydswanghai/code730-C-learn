// 地址+1，等于把指针移动到下一个sizeof

#include <stdio.h>

int main() {
  char ac[] = {0,1,2,3,4,5,6,7,8,9};
  char *p = ac;
  printf("p  =%p\n", p);  // 0x16b4eb088
  printf("p+1=%p\n", p+1);// 0x16b4eb089
  printf("sizeof(char)=%lu\n", sizeof(char));
  printf("*(p+1)=%d\n", *(p+1));// 等价 ac[1]

  int ai[] = {0,1,2,3,4,5,6,7,8,9};
  int *q = ai;
  printf("q  =%p\n", q);  // 0x16f483060
  printf("q+1=%p\n", q+1);// 0x16f483064
  printf("sizeof(int)=%lu\n", sizeof(int));
  printf("*(q+1)=%d\n", *(q+1));// 等价 ai[1]

  return 0;
}