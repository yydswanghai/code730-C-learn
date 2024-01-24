// 数组变量是const的指针，所以不能被赋值

#include <stdio.h>

int main() {
  int a[] = {1,2,3,4,5};
  int b[] = a;// 错误
  // int b[] --> int * const b;
  // 数组变量是一个常量指针

  return 0;
}