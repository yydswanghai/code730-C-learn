// sizeof

#include <stdio.h>

int main() {
  int a;
  a = 6;

  printf("sizeof(int)=%ld\n", sizeof(int));// 4
  printf("sizeof(a)=%ld\n", sizeof(a));// 4
  printf("sizeof(a++)=%ld\n", sizeof(a++));// 4 这里a静态的被替换为了6
  printf("a=%d\n", a);// 6

  return 0;
}
