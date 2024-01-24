// 浮点数的输出

#include <stdio.h>

int main() {
  double ff = 1234.56789;
  printf("%e,%f\n", ff, ff);
  printf("%E,%.10f\n", ff, ff);  

  // 计算机用离散的数字去表达数字
  printf("%.3f\n", -0.0049);// 被4舍5入
  printf("%.30f\n", -0.0049);
  printf("%.3f\n", -0.00049);

  return 0;
}
