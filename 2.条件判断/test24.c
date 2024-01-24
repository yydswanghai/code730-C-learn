// 求序列的前N项和 2/1 + 3/2 + 5/3 + 8/5 + ...
// 注意该序列从第2项起，每一项的分子是前一项分子与分母的和，分母是前一项的分子
// 输入：20
// 输出：32.66

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  double dividend = 2;// 分子
  double divisor = 1;// 分母
  double sum = 0.0;
  int i;
  double temp;

  for ( i = 1; i < n; i++) {
    sum += dividend/divisor;
    temp = dividend;
    dividend = dividend + divisor;
    divisor = temp;
    printf("%f/%f\n", dividend, divisor);
  }

  printf("%.2f\n", sum);

  return 0;
}
