// 超出范围的浮点数

#include <stdio.h>

int main() {
  printf("%f\n", 12.0/0.0);// 正无穷大
  printf("%f\n", -12.0/0.0);// 负无穷大
  printf("%f\n", 0.0/0.0);// 不存在的数字

  return 0;
}
