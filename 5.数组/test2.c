// 测试数组越界

#include <stdio.h>

void f();

int main() {
  f();
  printf("here\n");// 没有运行到这

  return 0;
}

void f() {
  int a[10];
  a[10] = 0;
}
