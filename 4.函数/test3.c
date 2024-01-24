// 函数的原型声明
// 原型声明
#include <stdio.h>

void sum(int begin, int end);

int main() {
  sum(1,10); 
  sum(20,30); 
  sum(35,45); 

  return 0;
}

void sum(int begin, int end) {
  int i;
  int sum = 0;
  for ( i = begin; i <= end; i++) {
    sum += i;
  }
  printf("%d到%d到和是%d\n", begin, end, sum);
}