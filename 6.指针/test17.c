// 指针的类型

#include <stdio.h>

int main() {
  char ac[] = {0,1,2,3,4};
  char *p = &ac[0];

  int ai[] = {0,1,2,3,4};
  int *q = ai;

  q = p;// 指向不同类型的指针是不能直接互相赋值的

  return 0;
}
