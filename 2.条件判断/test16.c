// 前n项求和 1 + 1/2 + 1/3 + 1/4 +...+ 1/n

#include <stdio.h>

int main() {
  int n;
  int i;
  double sum = 0.0;

  scanf("%d", &n);
  for ( i = 1; i <= n; i++) {
    // 1.0/i 由于 1.0是浮点数，所以会把另外一个数也变成浮点数，运算的结果也是浮点数
    sum += 1.0/i;
  }
  printf("f(%d)=%f\n", n, sum);

  return 0;
}

// 前n项求和 1 + 1/2 - 1/3 + 1/4 -...+ 1/n

int main2() {
  int n;
  int i;
  double sum = 0.0;
  int sign = 1;

  scanf("%d", &n);
  for ( i = 1; i <= n; i++) {
    // sign 就是 + - 号
    sum += sign * 1.0/i;
    sign = -sign;
  }
  printf("f(%d)=%f\n", n, sum);

  return 0;
}