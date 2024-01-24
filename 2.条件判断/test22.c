// 统计给定整数M和N区间内素数的个数并对它们求和
// 输入M和N(1 <= M <= n <= 500)：10 31
// 输出：7 143

#include <stdio.h>

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  int cnt = 0;
  int sum = 0;

  // 排除m=1的情况
  if (m == 1)
    m = 2;
  int i, j;
  for ( i = m; i <= n; i++) {
    int isPrime = 1;
    for ( j = 2; j < i-1; j++) {
      if (i % j == 0) {
        isPrime = 0;
        break;;
      }
    }
    if (isPrime == 1) {
      cnt++;
      sum += i;
      printf("%d ", i);
    }
    if (i == n) {
      printf("\n");
    }
  }
  printf("一共多少%d个, 之和为%d\n", cnt, sum);

  return 0;
}
