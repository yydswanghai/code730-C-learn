// 不能取的地址

#include <stdio.h>

int main() {
  int i = 0;
  int p;
  p = (int)&i;
  // p = (int)&(i+p);
  p = (int)&(i++);
  // p = (int)&(++i);
  printf("0x%x\n", p);
  printf("%p\n", &i);

  return 0;
}