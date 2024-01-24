// 数组的地址
// &a = a = a[0]

#include <stdio.h>

int main() {
  int a[10];
  
  printf("%p\n", &a);   // 0x16dd07070
  printf("%p\n", a);    // 0x16dd07070
  printf("%p\n", &a[0]);// 0x16dd07070
  printf("%p\n", &a[1]);// 0x16dd07074

  return 0;
}