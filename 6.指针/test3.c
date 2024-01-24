// 相邻的变量的地址
// i是早于p先定义的变量，但是在i在高位
// 在内存的堆栈中，分配是自顶向下分配的

#include <stdio.h>

int main() {
  int i = 0;
  int p;
  printf("%p\n", &i);// 0x16d6a3098
  printf("%p\n", &p);// 0x16d6a3094

  return 0;
}