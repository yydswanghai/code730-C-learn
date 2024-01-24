#include <stdio.h>

int main() {
  char c = 255;
  int i = 255;
  printf("c=%d,i=%d\n", c, i);
  // c=-1,i=255
  // c 11111111
  // i 00000000 00000000 00000000 11111111 

  unsigned char c2 = 255;
  printf("c2=%d\n", c2);
  // 255
  
  return 0;
}