#include <stdio.h>

int main() {
  int i;
  i = 3+4, 5+6;// 先运行：3+4被赋值给i，然后运行：5+6的结果没有给任何
  
  printf("%d\n", i);// 7

  int j;
  j = (3+4, 5+6);// 括号内表达式的结果：逗号后面的那个5+4的结果

  printf("%d\n", j);// 1

  return 0;
}