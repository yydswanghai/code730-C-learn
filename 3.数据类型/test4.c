// 整数越界测试

#include <stdio.h>

int main() {
  char c = 127;
  int i = 255;
  c = c+1;
  printf("c=%d,i=%d\n", c, i);
  // c=-128,i=255

  char c2 = -128;
  c2 = c2-1;
  printf("c2=%d\n", c2);
  // c2=127
  
  return 0;
}
