#include <stdio.h>

void swap();// 不确定是什么类型，不要写这种原型，要确定参数及类型

int main() {
  int a = 5;
  int b = 6;
  
  swap(a, b);

  {
    int a = 0;
    printf("a=%d\n", a);
  }

  printf("a=%d,b=%d\n", a, b);

  return 0;
}

void swap(double a, double b) {
  int t = a;
  a = b;
  b = t;
}