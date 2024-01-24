// 求a的连续和
// 输入两个整数a和n，a的范围是[0, 9)，n的范围是[1, 8]，求数列之和S = a+aa+aaa+...+aaa...a(n个a)
// 如a为2，n为8时，输出的是 2+22+222+...+22222222的和
// 输入：2 4
// 输出：2468

#include <stdio.h>

int main() {
  int a, n;
  scanf("%d %d", &a, &n);
  
  int sum = 0;
  int i;
  int t = 0;
  // 0*10+2 + 2*10+2 + (2*10+2)*10+2
  for ( i = 0; i < n; i++) {
    t = t*10+a;
    sum += t;
    printf("t=%d\n", t);
  }
  printf("%d\n", sum);
  
  return 0;
}
